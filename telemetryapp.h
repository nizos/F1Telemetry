#ifndef TELEMETRYAPP_H
#define TELEMETRYAPP_H
#include <QObject>
#include <QDebug>
#include <QtQml>
#include "telemetry.h"
//#include "timetable.h"
#include "curssorprovider.h"

class TelemetryApp: public QObject
{
    Q_OBJECT
    Q_PROPERTY(CursorPosProvider *mousePosProvider READ getMousePosProvider)
    Q_PROPERTY(Telemetry* telemetry READ getTelemetry)
//    Q_PROPERTY(TimeTable* timeTable READ getTimeTable)

public:
    // Constructor
    explicit TelemetryApp(QObject *parent = 0);

    // Destructor
    ~TelemetryApp();

    // Getters
    CursorPosProvider* getMousePosProvider() const;
    Telemetry* getTelemetry() const;
//    TimeTable* getTimeTable() const;

private:
    CursorPosProvider* mousePosProvider;
    Telemetry* telemetry;
//    TimeTable* timeTable;
};

#endif // TELEMETRYAPP_H
