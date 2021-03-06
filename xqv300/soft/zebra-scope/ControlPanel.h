#pragma once

#include "ui_ControlPanel.h"
#include "AdcBoard.hpp"
#include "AdcBoardTypes.hpp"

#include <QWidget>
#include <QPointer>
#include <QList>

#include <vector>

using namespace std;
class QModelIndex;
class QStandardItemModel;

class ControlPanel : public QWidget
{
	Q_OBJECT

public:
	ControlPanel(QWidget *parent = 0, Qt::WFlags flags = 0);
	virtual ~ControlPanel();

public:
	void setUiPowerStatus(const PowerStatus& status);
	void timerEvent(QTimerEvent* event);

public slots:
	void setDevList(const QList<AdcBoardInfo>& lst);
	void updateReport(const AdcBoardReport& rpt);

signals:
	void devSelected(int usbAddr);
	void changeSettings(const AdcSettings& data);
	void changeSettings(const SignalSettings& data);
	void changeTest(const vector<float>& data);

private slots:	
	void devItemClicked(const QModelIndex& index);
	void on_adcSettingsWidget_settingsChanged();
	void on_signalSettingsWidget_settingsChanged();
		
	void on_pushButtonStartDynamicTest_clicked();
	void on_pushButtonStopDynamicTest_clicked();
	void on_pushButtonStartStaticTest_clicked();
	void on_pushButtonStopStaticTest_clicked();

	bool on_pushButtonJtagTest_clicked();
	void on_pushButtonLogicTest_clicked();
	void on_pushButtonThermal_clicked();
	void on_pushButtonDynPower_clicked();
	void on_comboBoxBank_activated(int);

	void on_pushButtonConfigTest_clicked();

private:
	Ui::ControlPanelClass ui;
	QStandardItemModel *devListModel;
	AdcSettings adcSettings;
	SignalSettings signalSettings;

 	QStandardItemModel *tdReportModel;
 	QStandardItemModel *rdReportModel;

	ThermalTestInfo m_thermalTestInfo;

	int m_timeId;

};

