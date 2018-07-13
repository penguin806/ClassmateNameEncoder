#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(u8"ClassmateNameEncoder");
    w.resize(250,155);
    w.show();

    return a.exec();
}
