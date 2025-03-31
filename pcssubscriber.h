#ifndef PCSSUBSCRIBER_H
#define PCSSUBSCRIBER_H

#include "VDV301subscriber/ibisipsubscriberonepublisher.h"
#include "xmlgeneratorsubscriberpcs.h"


class PcsSubscriber : public IbisIpSubscriberOnePublisher
{
 Q_OBJECT


public:

 explicit PcsSubscriber(QString serviceName, QString structureName, QString version, QString serviceType, int portNumber);

    void startCounting(int doorNumber);
    void stopCounting(int doorNumber);
public slots:
    void slotStartCountingFinished(QString input);
private:
    XmlGeneratorSubscriberPcs xmlGeneratorSubscriber;

signals:
    void responseReceived(QString data);




};

#endif // PCSSUBSCRIBER_H
