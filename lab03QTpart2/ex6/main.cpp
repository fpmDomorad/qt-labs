#include "carefulpositioning.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CarefulPos widget;
    widget.show();
    return app.exec();
}
