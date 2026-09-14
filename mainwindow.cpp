#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pcsSubscriber("PassengerCountingService","AllData","2.1","_ibisip_http._tcp",45479)//puvodni port 48479, novy 59631

{
    ui->setupUi(this);

    //    pcsSubscriber.isSubscriptionActive=false ;

    //   pcsSubscriber.newSubscribeRequest();

    allConnects();
    pcsSubscriber.ignoreSubscribeError=true;
    pcsSubscriber.setSubnetMask(23);
    pcsSubscriber.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::allConnects()
{
    qDebug() <<  Q_FUNC_INFO;

    connect(&pcsSubscriber, &IbisIpSubscriber::signalDataReceived  ,this, &MainWindow::slotDataReceived);
    //    connect(&pcsSubscriber, &IbisIpSubscriber::signalSubscriptionSuccessful,this, &MainWindow::slotSubscribed);
    connect(&pcsSubscriber, &IbisIpSubscriber::signalError,this, &MainWindow::slotResponseReceived);
    //   connect(&pcsSubscriber, &PcsSubscriber::signal ,this, &MainWindow::slotResponseReceived);
}


void MainWindow::slotDataReceived(QString data)
{
    qDebug()<<Q_FUNC_INFO;
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

    if(!pcsSubscriber.pcsPublisherList.isEmpty())
    {
        pcsSubscriber.startCounting(pcsSubscriber.pcsPublisherList.first());
    }
}


void MainWindow::on_pushButton_stopCounting_clicked()
{
    if(!pcsSubscriber.pcsPublisherList.isEmpty())
    {
        pcsSubscriber.stopCounting(pcsSubscriber.pcsPublisherList.first());
    }

}


void MainWindow::on_pushButton_unsubscribe_clicked()
{
    if(!pcsSubscriber.pcsPublisherList.isEmpty())
    {
        pcsSubscriber.unsubscribe(pcsSubscriber.pcsPublisherList.first());
    }

}


void MainWindow::on_pushButton_manualAddService_clicked()
{
    PcsPublisherStruct selectedPcsPublisher;
    selectedPcsPublisher.hostAddress=QHostAddress(ui->lineEdit_serviceIp->text());
    selectedPcsPublisher.portNumber=ui->lineEdit_servicePort->text().toInt();
    selectedPcsPublisher.serviceName=ui->lineEdit_serviceName->text();
    selectedPcsPublisher.ibisIpVersion= ui->lineEdit_serviceVersion->text();
    selectedPcsPublisher.doorNumber=1;

    pcsSubscriber.slotAddServiceManual(selectedPcsPublisher);
}


void MainWindow::on_pushButton_manualAddServiceForce_clicked()
{
    PcsPublisherStruct selectedPcsPublisher;
    selectedPcsPublisher.hostAddress=QHostAddress(ui->lineEdit_serviceIp->text());
    selectedPcsPublisher.portNumber=ui->lineEdit_servicePort->text().toInt();
    selectedPcsPublisher.serviceName=ui->lineEdit_serviceName->text();
    selectedPcsPublisher.ibisIpVersion= ui->lineEdit_serviceVersion->text();
    selectedPcsPublisher.doorNumber=1;

    pcsSubscriber.slotAddServiceManualForce(selectedPcsPublisher);
}


void MainWindow::on_pushButton_setData0_clicked()
{
    if(!pcsSubscriber.pcsPublisherList.isEmpty())
    {
        pcsSubscriber.setCountersZero(pcsSubscriber.pcsPublisherList.first());
    }
}


void MainWindow::on_pushButton_purgeSubscribers_clicked()
{
    pcsSubscriber.pcsPublisherList.clear();
}

