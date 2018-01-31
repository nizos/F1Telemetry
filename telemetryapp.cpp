#include "telemetryapp.h"

// Default Constructor
TelemetryApp::TelemetryApp(QObject *parent): QObject(parent)
{
    // Register Types
    qmlRegisterType<CursorPosProvider>("TelemetryApp.Classes.Core", 1, 0, "CursorPosProvider");
    qmlRegisterType<Telemetry>("TelemetryApp.Classes.Core", 1, 0, "telemetry");
//    qmlRegisterType<TimeTable>("App.Classes.Core", 1, 0, "timeTable");

    // Initialize
    this->mousePosProvider = new CursorPosProvider();
    this->telemetry = new Telemetry();
//    this->timeTable = new TimeTable();

//    // Connect Classes
//    this->timeTable->setTelemetry(telemetry);
}

// Getters
CursorPosProvider* TelemetryApp::getMousePosProvider() const
{
    return mousePosProvider;
}

Telemetry* TelemetryApp::getTelemetry() const
{
    return this->telemetry;
}

//TimeTable* App::getTimeTable() const
//{
//    return this->timeTable;
//}

// Destructor
TelemetryApp::~TelemetryApp()
{

}
