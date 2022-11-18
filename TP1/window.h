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
    void end_program(int16_t status);
    void on_readCardBtn_clicked();

private:
    Ui::Window *ui;
};
#endif // WINDOW_H
