#include <QApplication>
#include <DEMOSrv.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DEMOSrv *Srv = new DEMOSrv(9090);

    return a.exec();
}
