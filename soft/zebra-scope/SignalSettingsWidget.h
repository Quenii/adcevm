#ifndef SIGNALSETTINGSWIDGET_H
#define SIGNALSETTINGSWIDGET_H

#include <QWidget>
#include "ui_SignalSettingsWidget.h"

using namespace Ui;

class SignalSettingsWidget : public QWidget, public SignalSettingsWidgetClass
{
	Q_OBJECT

public:
	SignalSettingsWidget(QWidget *parent = 0);
	~SignalSettingsWidget();

public:
	void setSettings(const SignalSettings& settings);
	void settings(SignalSettings& settings);

private slots:
	void on_pushButtonChangeSettings_clicked();

};

#endif // SIGNALSETTINGSWIDGET_H
