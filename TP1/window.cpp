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

int Window::readInfo(uint8_t sect_count){

    uint8_t data[240] = {0};
    clock_t t0, t1;
    uint8_t bloc_count, bloc, sect;
    uint8_t offset;
    int16_t status = 0;
    uint8_t atq[2];
    uint8_t sak[1];
    uint8_t uid[12];
    uint16_t uid_len = 12;

    if (bench){
        printf("Reading %d sectors...\n", sect_count);
        t0 = clock();
    }
    bloc = 0;
    for (sect = 0; sect < sect_count; sect++){
        if (!bench)
        printf("Reading sector %02d : ", sect);


        memset(data, 0x00, 240);
        status = Mf_Classic_Read_Sector(&MonLecteur, TRUE, sect, data, AuthKeyA, 2);
        if (status != MI_OK){
            if (bench)
                printf("Read sector %02d ", sect);
            printf("[Failed]\n");
            printf("  %s (%d)\n", GetErrorMessage(status), status);
            status = ISO14443_3_A_PollCard(&MonLecteur, atq, sak, uid, &uid_len);
            if (status != MI_OK){
                printf("No available tag in RF field\n");
                //goto close;
            }
        }
        else{
            if (!bench){
                printf("[OK]\n");
                // Display sector's data
                if (sect < 32)
                    bloc_count = 3;
                else
                    bloc_count = 15;
                for (bloc = 0; bloc < bloc_count; bloc++){
                    printf("%02d : ", bloc);
                    // Each blocks is 16-bytes wide
                    for (offset = 0; offset < 16; offset++){
                        printf("%02X ", data[16 * bloc + offset]);
                    }
                    for (offset = 0; offset < 16; offset++){
                        if (data[16 * bloc + offset] >= ' '){
                            printf("%c", data[16 * bloc + offset]);
                        } else
                            printf(".");

                    }
                    printf("\n");
                }
            }
        }
    }

    if (bench){
        t1 = clock();
        printf("Time elapsed: %ldms\n", (t1 - t0) / (CLOCKS_PER_SEC/1000));
    }
    return MI_OK;
}

void Window::end_program(int16_t status){
    // Display last error
    if (status == MI_OK)
    {
      printf("Done\n");
    } else
    {
      printf("%s (%d)\n", GetErrorMessage(status), status);
    }
}

void Window::close_reader(){
    // Close the reader

      RF_Power_Control(&MonLecteur, FALSE, 0);


      CloseCOM(&MonLecteur);
}

void Window::on_connectButton_clicked()
{

    char s_buffer[64];
    int16_t status = MI_OK;

    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 5;

    // Open reader
      status = OpenCOM(&MonLecteur);
      if (status != MI_OK){
          printf("Reader not found\n");
          end_program(status);
      }
      else{
          switch(MonLecteur.Type)
          {
              case ReaderTCP:
                  sprintf(s_buffer, "IP : %s", MonLecteur.IPReader);
              break;
              case ReaderCDC:
                  sprintf(s_buffer, "COM%d", MonLecteur.device);
              break;

          }
          printf("Reader found on %s\n", s_buffer);
      }


      status = Version(&MonLecteur);
      if (status == MI_OK){
          printf("Reader firwmare is %s\n", MonLecteur.version);
          printf("Reader serial is %02X%02X%02X%02X\n", MonLecteur.serial[0], MonLecteur.serial[1], MonLecteur.serial[2], MonLecteur.serial[3]);
          printf("Reader stack is %s\n", MonLecteur.stack);
      }

      status = LEDBuzzer(&MonLecteur, LED_YELLOW_ON);
      if (status != MI_OK){
          printf("LED [FAILED]\n");
          close_reader();
      }

      // RF field ON
      RF_Power_Control(&MonLecteur, TRUE, 0);

    //set the label to the cart version
    status = Version(&MonLecteur);
    ui->versionLabel->setText(MonLecteur.version);
    ui->versionLabel->update();


    readInfo(2);
}

