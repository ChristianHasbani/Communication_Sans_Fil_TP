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


}

