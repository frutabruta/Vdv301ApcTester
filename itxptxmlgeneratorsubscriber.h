#ifndef ITXPTXMLGENERATORSUBSCRIBER_H
#define ITXPTXMLGENERATORSUBSCRIBER_H

#include <QtXml>
#include <QHostAddress>
class ITxPTxmlGeneratorSubscriber
{
public:
    ITxPTxmlGeneratorSubscriber();
    QDomProcessingInstruction createProcessingInformation(QDomDocument &xmlDocument, QString encoding);
    QDomElement value(QDomDocument &xmlDocument, QString elementName, QString content);
    QString createSubscribeRequest(QHostAddress clientIpAddress, int port);
    QString createUnsubscribeRequest(QHostAddress clientIpAddress, int port);
};

#endif // ITXPTXMLGENERATORSUBSCRIBER_H
