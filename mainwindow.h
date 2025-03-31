#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "pcssubscriber.h"
#include "xmlparserpcs.h"


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

private:
    Ui::MainWindow *ui;

    PcsSubscriber pcsSubscriber;
    void allConnects();

    XmlParserPcs xmlParserPcs;

};
#endif // MAINWINDOW_H
