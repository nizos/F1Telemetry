#include "app.h"

// Default Constructor
App::App(QObject *parent): QObject(parent)
{
    // Initialize
    this->telemetry = new Telemetry();
    this->timeTable = new TimeTable();

    // Register Types
    qmlRegisterType<Telemetry>("App.Classes.Core", 1, 0, "telemetry");
    qmlRegisterType<TimeTable>("App.Classes.Core", 1, 0, "timeTable");

    // Connect Classes
    this->timeTable->setTelemetry(telemetry);
}

// Getters
Telemetry* App::getTelemetry() const
{
    return this->telemetry;
}

TimeTable* App::getTimeTable() const
{
    return this->timeTable;
}

// Destructor
App::~App()
{

}
