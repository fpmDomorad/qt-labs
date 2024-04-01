#include <QApplication>
#include "click.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Click w;
    w.show();
    return a.exec();
}
