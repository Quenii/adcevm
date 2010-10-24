#include "stdafx.h"
#include "gkhy/qplotlib/FFTWnd.hpp"
#include "gkhy/qplotlib/plotlab/CSLScope.h"

using namespace gkhy::QPlotLab;

FFTWnd::FFTWnd(QWidget *parent /*= 0*/, Qt::WindowFlags f /*= 0*/) : QScope(parent, f)
{
	rawScope().Title.Visible = false;

	rawScope().XAxis.AxisLabel.Text = _T("Frequency (MHz)");
	rawScope().YAxis.AxisLabel.Text = _T("Amplitude (dB)");

	//rawScope().YAxis.Max.Value = 5;
	//rawScope().YAxis.Min.Value = -120;
	//rawScope().YAxis.Min.AutoScale = FALSE;
	//rawScope().YAxis.Max.AutoScale = FALSE;
}

FFTWnd::~FFTWnd()
{

}

void FFTWnd::update(const std::vector<float> & xdata, const std::vector<float> & ydata)
{
	CTSLScope& scope = rawScope();
	if (scope.Channels.Count < 1)
		scope.Channels.Add(1);

	//scope.Channels[0].Data.SetYData(&data[0], (int)data.size());
	scope.Channels[0].Data.SetXYData(&xdata[0], &ydata[0], (int)xdata.size());
	scope.Channels[0].Name = _T("FFT");

}