#include "creatingwidgets.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreatingWidget w;
    w.show();
    return a.exec();
}
