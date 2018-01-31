#include "timetable.h"

// Default constructor
TimeTable::TimeTable()
{
//    this->drivers = 20;
//    this->laps = 100;
//    this->checkPoints = 10;
//    this->trackSize = 4000.0000;
//    this->telemetry = new Telemetry();

//    this->driver = new driver[this->drivers];
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->driver[i] = -1;
//    }

//    this->lap = new lap[this->drivers];
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->lap[i] = 1;
//    }

//    this->checkPoint = new checkPoint[this->drivers];
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->checkPoint[i] = 1;
//    }

//    this->timeTable = new timeTable[this->laps*this->checkPoints][this->drivers];
//    for(int i = 0; i < (this->laps*this->checkPoints); i++)
//    {
//        for(int j = 0; j < this->drivers; j++)
//        {
//            this->timeTable[i][j] = -1.00000;
//        }
//    }
}

//// Overloaded constructor
//TimeTable::TimeTable(int drivers, int laps, int checkPoints, double trackSize)
//{
//    this->drivers = drivers;
//    this->laps = laps;
//    this->checkPoints = checkPoints;
//    this->trackSize = trackSize;
//    this->telemetry = new Telemetry();

//    this->driver = new driver[this->drivers];
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->driver[i] = -1;
//    }

//    this->lap = new lap[this->drivers];
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->lap[i] = 1;
//    }

//    this->checkPoint = new checkPoint[this->drivers];
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->checkPoint[i] = 1;
//    }

//    this->timeTable = new timeTable[this->laps*this->checkPoints][this->drivers];
//    for(int i = 0; i < (this->laps*this->checkPoints); i++)
//    {
//        for(int j = 0; j < this->drivers; j++)
//        {
//            this->timeTable[i][j] = -1.00000;
//        }
//    }
//}

//void TimeTable::setTelemetry(Telemetry* telemetry)
//{
//    this->telemetry = telemetry;
//}

//void TimeTable::setDrivers(int drivers, int driver[])
//{
//    for(int i = 0; i < this->drivers; i++)
//    {
//        this->driver[i] = -1;
//    }

//    for(int i = 0; i < drivers; i++)
//    {
//        this->driver[i] = driver[i];
//    }
//}

//void TimeTable::setTrackSize(double trackSize)
//{
//    // Set new track Distance
//    this->trackSize = trackSize;

//    // Clear Time Table
//    this->timeTable = new timeTable[this->laps*this->checkPoints][this->drivers];
//    for(int i = 0; i < (this->laps*this->checkPoints); i++)
//    {
//        for(int j = 0; j < this->drivers; j++)
//        {
//            this->timeTable[i][j] = -1.00000;
//        }
//    }


//    // Set Check Point Distance
//    // Set Check Point Positions
//}

//// Methods
//void TimeTable::initializeTable()
//{
//    // Time Table
//    this->timeTable = new timeTable[this->nrOfLaps*this->nrOfCheckPoints][this->nrOfDrivers];
//    for(int i = 0; i < (this->nrOfLaps*this->nrOfCheckPoints); i++)
//    {
//        for(int j = 0; j < this->nrOfDrivers; j++)
//        {
//            this->timeTable[i][j] = 0.00000;
//        }
//    }

//    // Drivers




//}

//void TimeTable::updateTable()
//{

//}

//void TimeTable::clearTable()
//{

//}

//int TimeTable::getTableColumnNr(int lapNumber, int checkPointNumber, int nrOfCheckPoints)
//{
//    return ((lapNumber * nrOfCheckPoints) - nrOfCheckPoints) + (checkPointNumber - 1);
//}

//void TimeTable::registerTime(int driver, int lapNumber, int checkPointNumber, int nrOfCheckPoints, double raceTime)
//{
//    this->timeTable[getTableColumnNr(lapNumber, checkPointNumber, nrOfCheckPoints)][driver] = raceTime;
//}

//void TimeTable::findCheckPoint(int driver)
//{
//    double lapDistance = telemetry->getLapDistanceForCar(driver);
//    double raceTime = telemetry->getTime();

//    if(lapDistance > checkPointPosition[0] && dlapDistance < checkPointPosition[1])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 1;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[1] && lapDistance < checkPointPosition[2])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 2;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[2] && lapDistance < checkPointPosition[3])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 3;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[3] && lapDistance < checkPointPosition[4])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 4;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[4] && lapDistance < checkPointPosition[5])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 5;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[5] && lapDistance < checkPointPosition[6])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 6;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[6] && lapDistance < checkPointPosition[7])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 7;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[7] && lapDistance < checkPointPosition[8])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 8;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[8] && lapDistance < checkPointPosition[9])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 9;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//    else if(lapDistance > checkPointPosition[9])
//    {
//        prevCheckPoint[driver] = checkPoint[driver];
//        checkPoint[driver] = 10;
//        if(prevCheckPoint[driver] != checkPoint[driver])
//        {
//            registerTime(driver, lapNumber, checkPointNumber, nrOfCheckPoints, raceTime);
//        }
//    }
//}





































