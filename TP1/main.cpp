#include "qicon.h"
#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    a.setWindowIcon(QIcon("../IMGs/bigPic.png"));
    w.show();
    return a.exec();



}
