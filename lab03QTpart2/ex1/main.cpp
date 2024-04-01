#include "button.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Button w;
    w.show();
    return a.exec();
}
