#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "telemetry.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Telemetry>("Telemetry.Classes.Core", 1, 0, "Telemetry");
    Telemetry telemetry;
    QQmlContext *ctxt0 = engine.rootContext();
    ctxt0->setContextProperty("telemetry", &telemetry);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
