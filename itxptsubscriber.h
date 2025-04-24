#ifndef ITXPTSUBSCRIBER_H
#define ITXPTSUBSCRIBER_H

#include "VDV301subscriber/ibisipsubscriberonepublisher.h"
#include "itxptxmlgeneratorsubscriber.h"

class ITXPTsubscriber : public IbisIpSubscriberOnePublisher
{
public:
    ITXPTsubscriber(QString serviceName, QString structureName, QString version, QString serviceType, int portNumber);

    void postSubscribe(QUrl subscriberAddress, QString postRequestContent);
    void postUnsubscribe(QUrl subscriberAddress, QString postRequestContent);

    ITxPTxmlGeneratorSubscriber xmlGeneratorSubscriber;

private:

  //   QString mServiceType="_itxpt_http._tcp";

public slots:
     void slotAddService(QZeroConfService zcs);
     void slotAddServiceManual(QString serviceName, QString ipAddress, QString version, int portNumber);
};

#endif // ITXPTSUBSCRIBER_H
