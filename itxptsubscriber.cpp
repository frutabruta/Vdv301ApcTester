#include "itxptsubscriber.h"



ITXPTsubscriber::ITXPTsubscriber(QString serviceName,QString structureName,QString version,QString serviceType, int portNumber): IbisIpSubscriberOnePublisher(serviceName,structureName,version, serviceType, portNumber)
{
        mServiceType="_itxpt_http._tcp";
}



void ITXPTsubscriber::slotAddService(QZeroConfService zcs)
{
    qDebug() <<  Q_FUNC_INFO;

    QString serviceName=zcs->name();
    QString ipAddress=zcs->ip().toString();
    QString version=zcs.data()->txt().value("ver");
    int portNumber=zcs->port();
    qDebug() <<"service name "<<serviceName<<" ip address "<<ipAddress<<" portNumber "<<QString::number(portNumber)<<" data" <<version;

    if(!serviceList.contains(zcs))
    {
        serviceList.append(zcs);
    }


    emit signalUpdateDeviceList();

    if (isTheServiceRequestedOne(mServiceName,mVersion,zcs))
    {
        if(this->isCandidateSelected==false)
        {
            if(this->isSubscriptionActive==false)
            {
                qDebug()<<"sending subscribe request to  "<<ipAddress<<":"<<QString::number(portNumber)<<" service "<<serviceName;

                QString addressAfterBackslash="/"+mServiceName+"/Subscribe"+mStructureName;
                QString addressComplete="http://"+zcs->ip().toString()+":"+QString::number(zcs->port())+addressAfterBackslash;
                qDebug()<<"adresaCile string "<<addressComplete;
                QUrl subscriptionDestination=QUrl(addressComplete);
                isCandidateSelected=true;
                subscribeServiceCandidate=zcs;
                /*
                if(!isIpSet() )
                {
                    //deviceAddress=selectNonLoopbackAddress();
                    deviceAddress=selectNonLoopbackAddressInSubnet(zcs->ip());
                }*/

                deviceAddress=selectNonLoopbackAddressInSubnet(zcs->ip(),mSubnetMask);
                postSubscribe(subscriptionDestination,xmlGeneratorSubscriber.createSubscribeRequest(deviceAddress,httpServerSubscriber.portNumber()));

            }
            else
            {
                qDebug()<<"isSubscriptionActive "<<isSubscriptionActive;
            }
        }
        else
        {
            qDebug()<<"isCandidateSelected "<<isCandidateSelected;
        }

    }
    else
    {
        qDebug()<<"service is not the requested one";
    }

    // emit nalezenaSluzba( zcs);

}



void  ITXPTsubscriber::slotAddServiceManual(QString serviceName, QString ipAddress, QString version, int portNumber)
{
    qDebug() <<  Q_FUNC_INFO;
    /*
    QString serviceName=zcs->name();
    QString ipAddress=zcs->ip().toString();
    QString version=zcs.data()->txt().value("ver");
    int portNumber=zcs->port();
*/
    qDebug() <<"service name "<<serviceName<<" ip address "<<ipAddress<<" portNumber "<<QString::number(portNumber)<<" data" <<version;

    /*
    if(!serviceList.contains(zcs))
    {
        serviceList.append(zcs);
    }
*/

    emit signalUpdateDeviceList();

    if (isTheServiceRequestedOne(mServiceName,mVersion,serviceName,version))
    {
        if(this->isCandidateSelected==false)
        {
            if(this->isSubscriptionActive==false)
            {
                qDebug()<<"sending subscribe request to  "<<ipAddress<<":"<<QString::number(portNumber)<<" service "<<serviceName;

                QString addressAfterBackslash="/"+mServiceName+"/Subscribe"+mStructureName;
                QString addressComplete="http://"+ipAddress+":"+QString::number( portNumber)+addressAfterBackslash;
                qDebug()<<"adresaCile string "<<addressComplete;
                QUrl subscriptionDestination=QUrl(addressComplete);
                isCandidateSelected=true;

                //subscribeServiceCandidate=zcs;

                /*
                if(!isIpSet() )
                {
                    //deviceAddress=selectNonLoopbackAddress();
                    deviceAddress=selectNonLoopbackAddressInSubnet(zcs->ip());
                }*/

                deviceAddress=selectNonLoopbackAddressInSubnet(QHostAddress(ipAddress),mSubnetMask);
                postSubscribe(subscriptionDestination,xmlGeneratorSubscriber.createSubscribeRequest(deviceAddress,httpServerSubscriber.portNumber()));

            }
            else
            {
                qDebug()<<"isSubscriptionActive "<<isSubscriptionActive;
            }
        }
        else
        {
            qDebug()<<"isCandidateSelected "<<isCandidateSelected;
        }

    }
    else
    {
        qDebug()<<"service is not the requested one";
    }

    // emit nalezenaSluzba( zcs);

}


void ITXPTsubscriber::postSubscribe(QUrl subscriberAddress, QString postRequestContent)
{
    qDebug() <<  Q_FUNC_INFO;
    qDebug().noquote()<<"posting to address: "<<subscriberAddress<<" "<<postRequestContent;

    QNetworkRequest postRequest(subscriberAddress);


    // https://stackoverflow.com/a/53556560

    postRequest.setTransferTimeout(30000);
    postRequest.setRawHeader("Content-Type", "text/xml");
    //postRequest.setRawHeader("Expect", "100-continue");
    //postRequest.setRawHeader("Connection", "keep-Alive");
    //postRequest.setRawHeader("Accept-Encoding", "gzip, deflate");

    QByteArray postRequestContentQByteArray=postRequestContent.toUtf8() ;

    reply=postManager.post(postRequest,postRequestContentQByteArray);
    connect(reply, &QNetworkReply::finished, this, &ITXPTsubscriber::slotHttpRequestSubscriptionFinished);

}


void ITXPTsubscriber::postUnsubscribe(QUrl subscriberAddress, QString postRequestContent)
{
    qDebug() <<  Q_FUNC_INFO;
    qDebug().noquote()<<"posting to address: "<<subscriberAddress<<" "<<postRequestContent;

    QNetworkRequest postRequest(subscriberAddress);


    // https://stackoverflow.com/a/53556560

    postRequest.setTransferTimeout(30000);
    postRequest.setRawHeader("Content-Type", "text/xml");
    //postRequest.setRawHeader("Expect", "100-continue");
    //postRequest.setRawHeader("Connection", "keep-Alive");
    //postRequest.setRawHeader("Accept-Encoding", "gzip, deflate");

    QByteArray postRequestContentQByteArray=postRequestContent.toUtf8() ;

    reply=postManager.post(postRequest,postRequestContentQByteArray);
    connect(reply, &QNetworkReply::finished, this, &ITXPTsubscriber::slotHttpRequestUnsubscriptionFinished);

}
