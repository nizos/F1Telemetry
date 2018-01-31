#ifndef APP_H
#define APP_H
#include <QObject>
#include <QDebug>
#include <QtQml>
#include "telemetry.h"
#include "timetable.h"

class App: public QObject
{
    Q_OBJECT
    Q_PROPERTY(Telemetry* telemetry READ getTelemetry)
    Q_PROPERTY(TimeTable* timeTable READ getTimeTable)

public:
    // Constructor
    explicit App(QObject *parent = 0);

    // Destructor
    ~App();

    // Getters
    Telemetry* getTelemetry() const;
    TimeTable* getTimeTable() const;

private:
    Telemetry* telemetry;
    TimeTable* timeTable;
};

#endif // APP_H
