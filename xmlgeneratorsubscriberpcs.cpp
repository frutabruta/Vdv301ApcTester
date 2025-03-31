#include "xmlgeneratorsubscriberpcs.h"

XmlGeneratorSubscriberPcs::XmlGeneratorSubscriberPcs() {}


QString XmlGeneratorSubscriberPcs::startCounting(int doorNumber)
{
    QString result="";
    result+="<PassengerCountingService.StartCountingRequest>"
              "<DoorIdList>"
              "<DoorID>"
              "<Value>";
    result+=QString::number(doorNumber);
    result+="</Value>"
              "</DoorID>"
              "</DoorIdList>"
              "</PassengerCountingService.StartCountingRequest>";
    return result;
}


QString XmlGeneratorSubscriberPcs::stopCounting(int doorNumber)
{
    QString result="";
    result+="<PassengerCountingService.StopCountingRequest>"
              "<DoorIdList>"
              "<DoorID>"
              "<Value>";
    result+=QString::number(doorNumber);
    result+="</Value>"
              "</DoorID>"
              "</DoorIdList>"
              "</PassengerCountingService.StopCountingRequest>";
    return result;
}
