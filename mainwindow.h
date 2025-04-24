#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "VDV301subscriber/pcssubscriber.h"
#include "VDV301subscriber/xmlparserpcs.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotDataReceived(QString data);
    void on_pushButton_startCounting_clicked();

    void slotResponseReceived(QString data);
    void on_pushButton_stopCounting_clicked();

    void slotSubscribed(QZeroConfService zcs);
    void on_pushButton_unsubscribe_clicked();

    void on_pushButton_manualAddService_clicked();

    void on_pushButton_manualAddServiceForce_clicked();

    void on_pushButton_setData0_clicked();

    void on_pushButton_purgeSubscribers_clicked();

private:
    Ui::MainWindow *ui;

    PcsSubscriber pcsSubscriber;
    void allConnects();

    XmlParserPcs xmlParserPcs;


//    PcsPublisherStruct selectedPcsPublisher;

};
#endif // MAINWINDOW_H
