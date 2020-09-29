#include "formal_pro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    formal_pro w;
    w.show();
    return a.exec();
}
