#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(u8"ClassmateNameEncoder");
#ifdef Q_OS_ANDROID
    w.showMaximized();
#else
    w.resize(250,155);
    w.show();
#endif

    return a.exec();
}
