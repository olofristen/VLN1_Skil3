#include "mainwindow.h"
#include <QApplication>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
