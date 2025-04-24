#include "itxptxmlgeneratorsubscriber.h"

ITxPTxmlGeneratorSubscriber::ITxPTxmlGeneratorSubscriber() {}




QDomProcessingInstruction ITxPTxmlGeneratorSubscriber::createProcessingInformation(QDomDocument &xmlDocument, QString encoding)
{
    return xmlDocument.createProcessingInstruction("xml","version=\"1.0\" encoding=\""+encoding+"\" ");
}

/*
<?xml version="1.0" encoding="utf-16"?>
<DeviceManagementService.SetDeviceConfigurationRequest xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">
  <DeviceID>
    <Value>722</Value>
  </DeviceID>
</DeviceManagementService.SetDeviceConfigurationRequest>
 */


QDomElement ITxPTxmlGeneratorSubscriber::value(QDomDocument &xmlDocument, QString elementName, QString content)
{
    QDomElement result=xmlDocument.createElement(elementName); //verze 2.2CZ1.0
    result.appendChild(xmlDocument.createElement("Value")).appendChild( xmlDocument.createTextNode(content));
    return result;
}


QString ITxPTxmlGeneratorSubscriber::createSubscribeRequest(QHostAddress clientIpAddress, int port)
{
    QDomDocument xmlDocument;
    QDomProcessingInstruction dProcessingInformation=xmlDocument.createProcessingInstruction("xml","version=\"1.0\" encoding=\"utf-8\" ");
    xmlDocument.appendChild(dProcessingInformation);

    QDomElement dSubscribeRequest =xmlDocument.createElement("SubscribeRequest");
    xmlDocument.appendChild(dSubscribeRequest);

    QDomElement dClientIPAddress=xmlDocument.createElement("Client-IP-Address");
    dClientIPAddress.appendChild(xmlDocument.createTextNode(clientIpAddress.toString()));
    dSubscribeRequest.appendChild(dClientIPAddress);

    QDomElement dReplyPort=xmlDocument.createElement("ReplyPort");
    dReplyPort.appendChild(xmlDocument.createTextNode(QString::number(port)));
    dSubscribeRequest.appendChild(dReplyPort);

    return xmlDocument.toString();
}

QString ITxPTxmlGeneratorSubscriber::createUnsubscribeRequest(QHostAddress clientIpAddress, int port)
{
    QDomDocument xmlDocument;
    QDomProcessingInstruction dProcessingInformation=xmlDocument.createProcessingInstruction("xml","version=\"1.0\" encoding=\"utf-8\" ");
    xmlDocument.appendChild(dProcessingInformation);
    QDomElement dSubscribeRequest =xmlDocument.createElement("UnsubscribeRequest");
    xmlDocument.appendChild(dSubscribeRequest);
    QDomElement dClientIPAddress=xmlDocument.createElement("Client-IP-Address");
    QDomElement dIpValue=xmlDocument.createElement("Value");
    dIpValue.appendChild(xmlDocument.createTextNode(clientIpAddress.toString()));
    dClientIPAddress.appendChild(dIpValue);
    dSubscribeRequest.appendChild(dClientIPAddress);
    QDomElement dReplyPort=xmlDocument.createElement("ReplyPort");
    QDomElement dPortValue=xmlDocument.createElement("Value");
    dPortValue.appendChild(xmlDocument.createTextNode(QString::number(port)));
    dReplyPort.appendChild(dPortValue);
    dSubscribeRequest.appendChild(dReplyPort);

    return xmlDocument.toString();
}
