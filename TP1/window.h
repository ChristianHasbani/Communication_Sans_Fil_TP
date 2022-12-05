#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_connectButton_clicked();
    void close_reader();
    void on_readCardBtn_clicked();
    void initCard();
    void on_quitBtn_clicked();
    void on_disconnectButton_clicked();
    void on_updateButton_clicked();
    void on_payBtn_clicked();

    void updateSuccessLEDBuzzer(int16_t status);
    void updateFailedLEDBuzzer(int16_t status);

    void on_chargeBtn_clicked();

private:
    Ui::Window *ui;
    char * prenom;
    char * nom;
};
#endif // WINDOW_H
