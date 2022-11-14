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
private slots:
    void close_reader();
private slots:
   void end_program(int16_t status);


private:
    Ui::Window *ui;
};
#endif // WINDOW_H
