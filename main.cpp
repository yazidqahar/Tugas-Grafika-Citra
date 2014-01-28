#include <QtGui/QApplication>
#include "ocrneural.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OCRNeural w;
    w.show();

    return a.exec();
}
