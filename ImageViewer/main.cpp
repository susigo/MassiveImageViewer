#undef UNICODE

#include "mainwidget.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_win;
    main_win.show();
    return a.exec();
}
