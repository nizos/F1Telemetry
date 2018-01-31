#include "timetable.h"

// Default constructor
TimeTable::TimeTable()
{
    this->drivers = 20;
    this->laps = 100;
    this->checkPoints = 10;
    this->trackSize = 4000.0000;

    this->driver = new driver[this->drivers];
    for(int i = 0; i < this->drivers; i++)
    {
        this->driver[i] = -1;
    }

    this->lap = new lap[this->drivers];
    for(int i = 0; i < this->drivers; i++)
    {
        this->lap[i] = 1;
    }

    this->checkPoint = new checkPoint[this->drivers];
    for(int i = 0; i < this->drivers; i++)
    {
        this->checkPoint[i] = 1;
    }

    this->timeTable = new timeTable[this->laps*this->checkPoints][this->drivers];
    for(int i = 0; i < (this->laps*this->checkPoints); i++)
    {
        for(int j = 0; j < this->drivers; j++)
        {
            this->timeTable[i][j] = -1.00000;
        }
    }
}

// Overloaded constructor
TimeTable::TimeTable(int drivers, int laps, int checkPoints, double trackSize)
{
    this->drivers = drivers;
    this->laps = laps;
    this->checkPoints = checkPoints;
    this->trackSize = trackSize;

    this->driver = new driver[this->drivers];
    for(int i = 0; i < this->drivers; i++)
    {
        this->driver[i] = -1;
    }

    this->lap = new lap[this->drivers];
    for(int i = 0; i < this->drivers; i++)
    {
        this->lap[i] = 1;
    }

    this->checkPoint = new checkPoint[this->drivers];
    for(int i = 0; i < this->drivers; i++)
    {
        this->checkPoint[i] = 1;
    }

    this->timeTable = new timeTable[this->laps*this->checkPoints][this->drivers];
    for(int i = 0; i < (this->laps*this->checkPoints); i++)
    {
        for(int j = 0; j < this->drivers; j++)
        {
            this->timeTable[i][j] = -1.00000;
        }
    }
}

void TimeTable::setDrivers(int drivers, int driver[])
{
    for(int i = 0; i < this->drivers; i++)
    {
        this->driver[i] = -1;
    }

    for(int i = 0; i < drivers; i++)
    {
        this->driver[i] = driver[i];
    }
}

// Update
void TimeTable::update()
{
    for(int i = 0; i < this->drivers; i++)
    {
        this->driver[i] = -1;
    }

    for(int i = 0; i < drivers; i++)
    {
        this->driver[i] = driver[i];
    }
}





































