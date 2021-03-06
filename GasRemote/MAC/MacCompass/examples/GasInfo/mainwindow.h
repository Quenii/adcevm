#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gasinfosettings.h"
#include "locationmanager.h"

#include <QMainWindow>
#include <QCloseEvent>
#include <QModelIndexList>


namespace Ui {
    class MainWindow;
}

class QModelIndex;
class CentralModel;
class QMdiSubWindow;
class QTimerEvent;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:


protected:
    void closeEvent(QCloseEvent *event);
    void timerEvent(QTimerEvent *);

private:
    void saveSettings();
    void readSettings();
    QMdiSubWindow* terminalSubwindow(int terminalId);
    void initMap();

    void clearAllData();

public slots:
    void applicationModelChanged();
    void addData(const GasInfoItem& item);
    void archiveCentralModel();

private slots:  
    void openCloseTerminals(const QMap<int, int> &idList, bool open);
    void deleteTerminals(const QList<int>& idList);

    void on_actionSave_triggered(bool checked = false);
    void on_actionLoad_triggered(bool checked = false);
    void on_actionOption_triggered(bool checked = false);
    void on_actionExit_triggered(bool checked = false);

    void optionsApplied();

private:
    Ui::MainWindow *ui;
    CentralModel* m_centralModel;
    LocationManager* m_locationManager;
};

#endif // MAINWINDOW_H
