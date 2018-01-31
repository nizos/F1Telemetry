#ifndef TIMETABLE_H
#define TIMETABLE_H


class TimeTable
{
public:
    // Default constructor
    TimeTable();

    // Overloaded constructor
    TimeTable(int drivers, int laps, int checkPoints, double trackSize);


    // Update
    void update();


    // Getters


    // Setters
    void setDrivers(int drivers, int driver[]);



private:
    int laps;
    int drivers;
    int checkPoints;
    double trackSize;
    int lap[];
    int driver[];
    int checkPoint[];
    double timeTable[][];
};

#endif // TIMETABLE_H
