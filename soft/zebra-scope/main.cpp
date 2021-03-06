#include "mainwindow.h"
#include "histplot.h"
#include "../../../3rdparty/m2c/c/include/m2c.h"

#include <QMessageBox>
#include <QtSingleApplication>
#include <QThread>

#ifdef MATLAB    //defined in AdcBoardTypes.hpp
#include "libalgo.h"

#pragma comment(lib, "libalgo.lib")
#pragma comment(lib, "mclmcrrt.lib")
#endif // MATLAB

#define REGISTER_METATYPE_HELPER( type ) \
	qRegisterMetaType<type>(); \
	qRegisterMetaType<type>(#type); \
	qRegisterMetaTypeStreamOperators<type>(#type)

int main(int argc, char *argv[])
{
	LibInitializer init;
	QtSingleApplication app(argc, argv);

	QApplication::setOrganizationName("quenii-roc");
	QApplication::setOrganizationDomain("quenii-roc.com");
	QApplication::setApplicationName("ADC-Analyzer");

	REGISTER_METATYPE_HELPER(SignalSettings);
	REGISTER_METATYPE_HELPER(StaticTestSettings);
	REGISTER_METATYPE_HELPER(RegAccessSettings);
	REGISTER_METATYPE_HELPER(SpanSettings);
	REGISTER_METATYPE_HELPER(AdcTypeSettings);

#ifdef MATLAB
	if (!(mclInitializeApplication(NULL, 0) && libalgoInitialize()))
	{
		QMessageBox::critical(NULL, "", "Failed to initialize Matlab.");

	}
#endif // MATLAB

	MainWindow w;

	bool ok = app.connect(&app, SIGNAL(messageReceived (const QString &)), &app, SLOT(activateWindow()));
	Q_ASSERT(ok);

	app.setActivationWindow(&w);
	if (app.isRunning())
		return !app.sendMessage(" ");

	w.showMaximized();
	

	qDebug() << "Main thread Id: " << QThread::currentThreadId();
	int ret = app.exec();

#ifdef MATLAB
	libalgoTerminate();
	mclTerminateApplication();
#endif // MATLAB
	return ret;
}
