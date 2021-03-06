#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QtGui/QMainWindow>
#include <QPointer>
#include "AdcBoardTypes.hpp"

#include <vector>
using namespace std;

namespace gkhy
{
	namespace QPlotLab
	{
		class WaveWnd;
		class LogicWaveWnd;
		class FFTWnd;
		class DynamicPowerWnd;
	}
}
class QSplitter;
class ControlPanel;
class QTimerEvent;
class AdcBoard;
class RegAccess;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

private:
	void createMenus();

signals:
	void settingsLoaded(const AdcSettings& data);
	void settingsLoaded(const SignalSettings& data);
	void adcBoardReportLoaded(const AdcBoardReport& data);

private slots:
	void on_menuSettings_hovered(QAction * action);
	void on_actionLoadData_triggered(bool checked = false);
	void on_actionSaveData_triggered(bool checked = false);
	void on_actionSpiCtrl_triggered(bool checked = false);
	void on_actionSpectrum_toggled(bool checked = false);
	void on_actionLogic_toggled(bool checked = false);
	void on_action_Thermal_toggled(bool checked);
	
 	void slotShowWaveWnd();
 	void slotShowFFtWnd();
 	void slotShowControlPanel();
	void slotShowAbout();
	void slotShowBoardReport(const AdcBoardReport& report);
	void slotAddMarkers(const vector<float>& data);

private:
	Ui::MainWindowClass ui;
	gkhy::QPlotLab::WaveWnd* waveWnd;
	gkhy::QPlotLab::FFTWnd* fftWnd;
	gkhy::QPlotLab::LogicWaveWnd* logicWaveWnd;
	gkhy::QPlotLab::DynamicPowerWnd* dynamicPowerWnd;
	QPointer<RegAccess> regAccess;
	AdcBoard* adcBoard;
};

#endif // MAINWINDOW_H
