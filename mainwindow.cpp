#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("1");
    connectDevice();
    connect(m_canDevice, &QCanBusDevice::framesReceived,
            this, &MainWindow::processReceivedFrames);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processReceivedFrames()
{   while(m_canDevice->framesAvailable()){
        const QCanBusFrame frame = m_canDevice->readFrame();
        QString data;
        data = QString::fromLatin1(frame.payload().toHex(' ').toUpper());
        qDebug() << data;
        ui->label->setText(data);
    }


}

void MainWindow::connectDevice()
{
    QString errorString;
    const QList<QCanBusDeviceInfo> devices = QCanBus::instance()->availableDevices(
        QStringLiteral("socketcan"), &errorString);
    if (!errorString.isEmpty())
        qDebug() << errorString;
    int i=0;

    //while(devices.)
    qDebug() << devices[i].name();
    int val=500000;
    m_canDevice= QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("vcan0"), &errorString);
    if(!m_canDevice)
        qDebug()  << errorString;
    else
        m_canDevice->connectDevice();
    // QCanBusFrame a(QCanBusFrame::FrameId(123), QByteArray("1234"));
    // m_canDevice->writeFrame(a);
}
