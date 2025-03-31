#ifndef XMLGENERATORSUBSCRIBERPCS_H
#define XMLGENERATORSUBSCRIBERPCS_H

#include "VDV301subscriber/xmlgeneratorsubscriber.h"
class XmlGeneratorSubscriberPcs : public XmlGeneratorSubscriber
{
public:
    XmlGeneratorSubscriberPcs();
    QString startCounting(int doorNumber);
    QString stopCounting(int doorNumber);
};

#endif // XMLGENERATORSUBSCRIBERPCS_H
