#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "app.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    // Initialize
    QGuiApplication app(argc, argv);
    App mainApp;
    QQmlApplicationEngine engine;

    // Register QML Types
    qmlRegisterType<App>("App.Classes.Core", 1, 0, "App");
    QQmlContext *ctxt0 = engine.rootContext();
    ctxt0->setContextProperty("telemetry", mainApp.getTelemetry());
    QQmlContext *ctxt1 = engine.rootContext();
    ctxt1->setContextProperty("timeTable", mainApp.getTimeTable());

    // Load Engine
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
