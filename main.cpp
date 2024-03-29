#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QThreadPool>
#include "candevice.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int res=0;
    // try {
    //     auto server = std::make_shared<canDevice>();

    //     QtExecutor executor;
    //     executor.add_node(server);

    //     executor.start();

    //     res = a.exec();
    // } catch (std::exception& e) {
    //     res = 1;
    // }


    return a.exec();
}
