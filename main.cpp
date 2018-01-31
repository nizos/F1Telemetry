#include <QApplication>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "telemetryapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<TelemetryApp>("TelemetryApp.Classes.Core", 1, 0, "TelemetryApp");
    TelemetryApp telemetryApp;

    QQmlContext *ctxt0 = engine.rootContext();
    ctxt0->setContextProperty("telemetryApp", &telemetryApp);
    QQmlContext *ctxt1 = engine.rootContext();
    ctxt1->setContextProperty("mousePosition", telemetryApp.getMousePosProvider());
    QQmlContext *ctxt2 = engine.rootContext();
    ctxt2->setContextProperty("telemetry", telemetryApp.getTelemetry());



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQuickWindow *wnd1 = engine.rootObjects()[0]->findChild<QQuickWindow *>("mainWindow");
        if(wnd1)
            wnd1->setTitle("TELEMETRY HUD");
        QQuickWindow *wnd2 = engine.rootObjects()[0]->findChild<QQuickWindow *>("overlayWindow");
        if(wnd2)
            wnd2->setTitle("TELEMETRY HUD OVERLAY");
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
