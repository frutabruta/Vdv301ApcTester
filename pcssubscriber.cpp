#include "pcssubscriber.h"


PcsSubscriber::PcsSubscriber(QString serviceName,QString structureName,QString version,QString serviceType, int portNumber): IbisIpSubscriberOnePublisher(serviceName,structureName,version, serviceType, portNumber)
{

}



void PcsSubscriber::startCounting(int doorNumber)
{
    qDebug() <<  Q_FUNC_INFO;

    qDebug() <<  Q_FUNC_INFO;
    if(!subscribedService.isNull())
    {
        QString addressAfterBackslash="/"+mServiceName+"/StartCounting";
        QString addressComplete="http://"+subscribedService->ip().toString()+":"+QString::number(subscribedService->port())+addressAfterBackslash;
        qDebug()<<"adresaCile string "<<addressComplete;
        QUrl subscriptionDestination=QUrl(addressComplete);
        postGenericRequest(subscriptionDestination,xmlGeneratorSubscriber.startCounting(doorNumber));
    }
    else
    {
        emit signalError("not subscribed");
    }



}


void PcsSubscriber::stopCounting(int doorNumber)
{
    qDebug() <<  Q_FUNC_INFO;
    if(!subscribedService.isNull())
    {
        QString addressAfterBackslash="/"+mServiceName+"/StopCounting";
        QString addressComplete="http://"+subscribedService->ip().toString()+":"+QString::number(subscribedService->port())+addressAfterBackslash;
        qDebug()<<"adresaCile string "<<addressComplete;
        QUrl subscriptionDestination=QUrl(addressComplete);
        postGenericRequest(subscriptionDestination,xmlGeneratorSubscriber.stopCounting(doorNumber));
    }
    else
    {
        emit signalError("not subscribed");
    }

}

/*
void IbisIpSubscriberOnePublisher::unsubscribe()
{

    qDebug() <<  Q_FUNC_INFO;
    QString addressAfterBackslash="/"+mServiceName+"/Unsubscribe"+mStructureName;
    QString addressComplete="http://"+subscribedService->ip().toString()+":"+QString::number(subscribedService->port())+addressAfterBackslash;
    qDebug()<<"adresaCile string "<<addressComplete;
    QUrl subscriptionDestination=QUrl(addressComplete);


    postUnsubscribe(subscriptionDestination,xmlGeneratorSubscriber.createUnsubscribeRequest(deviceAddress,httpServerSubscriber.portNumber()));
    isSubscriptionActive=false;
    isCandidateSelected=false;
}*/

void PcsSubscriber::slotStartCountingFinished(QString input)
{
    emit responseReceived(input);
}
