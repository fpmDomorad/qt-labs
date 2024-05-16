#include "datingservices.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    datingServices w;
    w.writeJsonFile();
    w.show();
    return a.exec();
}
