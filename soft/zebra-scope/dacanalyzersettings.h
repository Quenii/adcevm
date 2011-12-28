#pragma once

#include "AdcBoardTypes.hpp"

#include <QSettings>

class AdcAnalyzerSettings
{
public:
	AdcAnalyzerSettings(void);
	virtual ~AdcAnalyzerSettings(void);

public:
	AdcTypeSettings adcTypeSettings() const;
	void setAdcTypeSettings(const AdcTypeSettings& val);
	
	AdcTypeSettings storedAdcTypeSettings(const QString& adcType) const;
	void setStoredAdcTypeSettings(const AdcTypeSettings& val);
	
	StaticTestSettings staticTestSettings() const;
	void setStaticTestSettings(const StaticTestSettings& val);

	SignalSettings signalSettings() const;
	void setSignalSettings(const SignalSettings& val);

	RegAccessSettings regAccessSettings() const;
	void setRegAccessSettings(const RegAccessSettings& val);

	float clockFreq() const;
	void setClockFreq(const float& val);
	
	QPoint powerMonitorWidgetPos() const;
	void setPowerMonitorWidgetPos(const QPoint& val);

	bool powerMonitorWidgetVisible() const;
	void setPowerMonitorWidgetVisible(const bool& val);

private:
	QSettings m_s;
};
