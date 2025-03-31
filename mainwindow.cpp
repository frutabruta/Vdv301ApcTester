#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pcsSubscriber("PassengerCountingService","AllData","2.1","_ibisip_http._tcp",45479)//puvodni port 48479, novy 59631

{
    ui->setupUi(this);

    pcsSubscriber.isSubscriptionActive=false ;
    pcsSubscriber.start();
    pcsSubscriber.newSubscribeRequest();

    allConnects();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::allConnects()
{
    qDebug() <<  Q_FUNC_INFO;

    connect(&pcsSubscriber, &IbisIpSubscriber::signalDataReceived  ,this, &MainWindow::slotDataReceived);
    connect(&pcsSubscriber, &IbisIpSubscriberOnePublisher::signalSubscriptionSuccessful,this, &MainWindow::slotSubscribed);
    connect(&pcsSubscriber, &IbisIpSubscriberOnePublisher::signalError,this, &MainWindow::slotResponseReceived);
    //   connect(&pcsSubscriber, &PcsSubscriber::signal ,this, &MainWindow::slotResponseReceived);
}


void MainWindow::slotDataReceived(QString data)
{
    ui->plainTextEdit_receivedData->setPlainText(data);

    int inCount=0;

    int outCount=0;

    xmlParserPcs.parseBasicNumbers(data,inCount,outCount);

    ui->label_in->setText(QString::number(inCount));
    ui->label_out->setText(QString::number(outCount));


}

void MainWindow::slotResponseReceived(QString data)
{
    ui->plainTextEdit_response->setPlainText(data);
}

void MainWindow::slotSubscribed(QZeroConfService zcs)
{
    ui->label_publisherIp->setText(zcs->ip().toString());
}

void MainWindow::on_pushButton_startCounting_clicked()
{
    pcsSubscriber.startCounting(1);
}


void MainWindow::on_pushButton_stopCounting_clicked()
{

}


void MainWindow::on_pushButton_unsubscribe_clicked()
{
    pcsSubscriber.unsubscribe();
}

