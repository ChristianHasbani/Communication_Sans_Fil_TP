#include "window.h"
#include "ui_window.h"


#include <time.h>
#include <stdio.h>
#include "MfErrNo.h"
#include "Core.h"
#include "Sw_Device.h"
#include "Sw_Mf_Classic.h"
#include "Sw_Poll.h"
#include "Sw_ISO14443A-3.h"
#include "TypeDefs.h"
#include "Tools.h"


Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

ReaderName MonLecteur;
BOOL bench = FALSE;

void Window::close_reader(){
      LEDBuzzer(&MonLecteur, LED_OFF);
      RF_Power_Control(&MonLecteur, FALSE, 0);
      CloseCOM(&MonLecteur);
}

void Window::initCard(){

    int16_t status = MI_OK;
    uint8_t i;
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;
    uint8_t sect_count = 0;

     ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
     LEDBuzzer(&MonLecteur, LED_YELLOW_ON);
}
void Window::on_connectButton_clicked()
{

    char s_buffer[64];
    int16_t status = MI_OK;

    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 5;

    // Open communication with reader
      status = OpenCOM(&MonLecteur);


      status = Version(&MonLecteur);

      status = LEDBuzzer(&MonLecteur, LED_YELLOW_ON);
      if (status != MI_OK){
          close_reader();
      }

      // RF field ON
      RF_Power_Control(&MonLecteur, TRUE, 0);

    //set the label to the card version
    status = Version(&MonLecteur);
    ui->versionLabel->setText(MonLecteur.version);
    ui->versionLabel->update();


    //set text in the bottom left for the link
    ui->textWLinkLabel->setText("Copyright ODALID <a> http://odalid.comcontact@odalid.com</a>");//not done yet
    ui->textWLinkLabel->setOpenExternalLinks(true);
    ui->textWLinkLabel->wordWrap();
    ui->textWLinkLabel->update();
}



void Window::on_readCardBtn_clicked()
{
    int16_t status = MI_OK;
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;
    uint8_t data[16];
    uint32_t value = 0;
//    status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
    initCard();
    memset(data, 0x00, 16);

    //read firstname
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 9, data, AuthKeyA, 2);
    ui->prenomText->setText((char*) data);

    //read lastname
    status = Mf_Classic_Read_Block(&MonLecteur,TRUE,10,data,AuthKeyA,2);
    ui->nomText->setText((char*)data);

    //read counter
    status = Mf_Classic_Read_Value(&MonLecteur,TRUE,14,&value,AuthKeyA,3);
    ui->nbUnitText->setText((QString::number(value)));

    if(status == MI_OK){
        //update light card successfully read
        updateSuccessLEDBuzzer(status);
        initCard();

    }else{
        //Failed to read card
        updateFailedLEDBuzzer(status);
       close_reader();
//       updateFailedLEDBuzzer(status);
    }

}


void Window::on_quitBtn_clicked()
{
    close_reader();
    exit(EXIT_FAILURE);
}


void Window::on_disconnectButton_clicked()
{
    int16_t status = MI_OK;
    ui->textWLinkLabel->setText("");
    ui->nomText->setText("");
    ui->prenomText->setText("");
    ui->nbUnitText->setText("");
    updateSuccessLEDBuzzer(status);
    close_reader();

}

void Window::on_updateButton_clicked()
{
    char DataIn[16];
    uint8_t data[16];
    int16_t status = MI_OK;

    //write the firstname to the card
    strncpy(DataIn, ui->prenomText->text().toUtf8().data(), 16);
    for(int i = 0; i != '\n'; i++){
        data[i] = DataIn[i];
    }
    status = Mf_Classic_Write_Block(&MonLecteur,TRUE,9,data,AuthKeyB,2);

    //write the lastname to the card
    strncpy(DataIn, ui->nomText->text().toUtf8().data(), 16);
    for(int i = 0; i != '\n'; i++){
        data[i] = DataIn[i];
    }
    status = Mf_Classic_Write_Block(&MonLecteur,TRUE,10,data,AuthKeyB,2);


    if(status == 0){
        //update successful
       updateSuccessLEDBuzzer(status);

    }else{
        //update failed
       updateFailedLEDBuzzer(status);
    }
}

void Window::updateSuccessLEDBuzzer( int16_t status){
    status = LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(1);
    status = LEDBuzzer(&MonLecteur, LED_GREEN_ON);
    DELAYS_S(1);
}

void Window::updateFailedLEDBuzzer(int16_t status){
    status = LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(2);
    status = LEDBuzzer(&MonLecteur, LED_GREEN_ON+LED_YELLOW_ON+LED_RED_ON+LED_GREEN_ON);
    DELAYS_MS(2);
    status = LEDBuzzer(&MonLecteur, LED_RED_ON);
    DELAYS_S(1);
}


void Window::on_payBtn_clicked()
{
    int16_t status = MI_OK;
    uint8_t nbDec = ui->nbDecSpinner->value();
    uint32_t nbUnits =  ui->nbUnitText->text().toInt();
    uint32_t value = 0;

    initCard();

    if(nbUnits <= 0){
        qDebug("Error not enough number of units!!");
        updateFailedLEDBuzzer(status);
    }else if(nbDec >= nbUnits){
        qDebug("Error number to decrement exceeds the funds available!!");
        updateFailedLEDBuzzer(status);
    }else{

        status = Mf_Classic_Decrement_Value(&MonLecteur,TRUE,14,nbUnits,13,AuthKeyA,3);
        status = Mf_Classic_Restore_Value(&MonLecteur,TRUE,13,14,AuthKeyA,3);

        status = Mf_Classic_Read_Value(&MonLecteur,TRUE,14,&value,AuthKeyA,3);
        if(status == MI_OK){
            updateSuccessLEDBuzzer(status);
            ui->nbDecSpinner->clear();
        }else{
            updateFailedLEDBuzzer(status);
        }
        ui->nbUnitText->setText(QString::number(nbUnits));
        ui->nbUnitText->update();
    }




}


void Window::on_chargeBtn_clicked()
{
    int16_t status = MI_OK;
    uint8_t nbIncrement = ui->incrementSpinner->value();
    uint32_t value= 0;

    status = Mf_Classic_Increment_Value(&MonLecteur,TRUE,14,nbIncrement,13,AuthKeyB,3);
    status = Mf_Classic_Restore_Value(&MonLecteur,TRUE,13,14,AuthKeyB,3);

    status = Mf_Classic_Read_Value(&MonLecteur,TRUE,14,&value,AuthKeyA,3);

    ui->nbUnitText->setText(QString::number(value));
    ui->nbUnitText->update();

}

