#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <QObject>
#include <QtNetwork>
#include <QtWidgets>
#include <QApplication>

class QUdpSocket;
class QAction;

#pragma pack(push,1)
struct CarUDPData
{
    float m_worldPosition[3];
    float m_lastLapTime;
    float m_currentLapTime;
    float m_bestLapTime;
    float m_sector1Time;
    float m_sector2Time;
    float m_lapDistance;
    byte  m_driverId;
    byte  m_teamId;
    byte  m_carPosition;
    byte  m_currentLapNum;
    byte  m_tyreCompound;
    byte  m_inPits;
    byte  m_sector;
    byte  m_currentLapInvalid;
    byte  m_penalties;
};
#pragma pack(pop)

#pragma pack(push,1)
struct UDPPacket
{
    float m_time;
    float m_lapTime;
    float m_lapDistance;
    float m_totalDistance;
    float m_x;	// World space position
    float m_y;	// World space position
    float m_z;	// World space position
    float m_speed;	// Speed of car in MPH
    float m_xv;	// Velocity in world space
    float m_yv;	// Velocity in world space
    float m_zv;	// Velocity in world space
    float m_xr;	// World space right direction
    float m_yr;	// World space right direction
    float m_zr;	// World space right direction
    float m_xd;	// World space forward direction
    float m_yd;	// World space forward direction
    float m_zd;	// World space forward direction
    float m_susp_pos[4];	// Note: All wheel arrays have the order:
    float m_susp_vel[4];	// RL, RR, FL, FR
    float m_wheel_speed[4];
    float m_throttle;
    float m_steer;
    float m_brake;
    float m_clutch;
    float m_gear;
    float m_gforce_lat;
    float m_gforce_lon;
    float m_lap;
    float m_engineRate;
    float m_sli_pro_native_support;	// SLI Pro support
    float m_car_position;	// car race position
    float m_kers_level;	// kers energy left
    float m_kers_max_level;	// kers maximum energy
    float m_drs;	// 0 = off, 1 = on
    float m_traction_control;	// 0 (off) - 2 (high)
    float m_anti_lock_brakes;	// 0 (off) - 1 (on)
    float m_fuel_in_tank;	// current fuel mass
    float m_fuel_capacity;	// fuel capacity
    float m_in_pits;	// 0 = none, 1 = pitting, 2 = in pit area
    float m_sector;	// 0 = sector1, 1 = sector2, 2 = sector3
    float m_sector1_time;	// time of sector1 (or 0)
    float m_sector2_time;	// time of sector2 (or 0)
    float m_brakes_temp[4];	// brakes temperature (centigrade)
    float m_tyres_pressure[4];	// tyres pressure PSI
    float m_team_info;	// team ID
    float m_total_laps;	// total number of laps in this race
    float m_track_size;	// track size meters
    float m_last_lap_time;	// last lap time
    float m_max_rpm;	// cars max RPM, at which point the rev limiter will kick in
    float m_idle_rpm;	// cars idle RPM
    float m_max_gears;	// maximum number of gears
    float m_sessionType;	// 0 = unknown, 1 = practice, 2 = qualifying, 3 = race
    float m_drsAllowed;	// 0 = not allowed, 1 = allowed, -1 = invalid / unknown
    float m_track_number;	// -1 for unknown, 0-21 for tracks
    float m_vehicleFIAFlags;	// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
    float m_era;                    	// era, 2017 (modern) or 1980 (classic)
    float m_engine_temperature;  	// engine temperature (centigrade)
    float m_gforce_vert;	// vertical g-force component
    float m_ang_vel_x;	// angular velocity x-component
    float m_ang_vel_y;	// angular velocity y-component
    float m_ang_vel_z;	// angular velocity z-component
    char  m_tyres_temperature[4];	// tyres temperature (centigrade)
    char  m_tyres_wear[4];	// tyre wear percentage
    char  m_tyre_compound;	// compound of tyre – 0 = ultra soft, 1 = super soft, 2 = soft, 3 = medium, 4 = hard, 5 = inter, 6 = wet
    char  m_front_brake_bias;         // front brake bias (percentage)
    char  m_fuel_mix;                 // fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
    char  m_currentLapInvalid;    	// current lap invalid - 0 = valid, 1 = invalid
    char  m_tyres_damage[4];	// tyre damage (percentage)
    char  m_front_left_wing_damage;	// front left wing damage (percentage)
    char  m_front_right_wing_damage;	// front right wing damage (percentage)
    char  m_rear_wing_damage;	// rear wing damage (percentage)
    char  m_engine_damage;	// engine damage (percentage)
    char  m_gear_box_damage;	// gear box damage (percentage)
    char  m_exhaust_damage;	// exhaust damage (percentage)
    char  m_pit_limiter_status;	// pit limiter status – 0 = off, 1 = on
    char  m_pit_speed_limit;	// pit speed limit in mph
    float m_session_time_left;  // NEW: time left in session in seconds
    char  m_rev_lights_percent;  // NEW: rev lights indicator (percentage)
    char  m_is_spectating;  // NEW: whether the player is spectating
    char  m_spectator_car_index;  // NEW: index of the car being spectated

    // Car data
    char  m_num_cars;              	// number of cars in data
    char  m_player_car_index;        	// index of player's car in the array
    CarUDPData  m_car_data[20];   // data for all cars on track

    float m_yaw;  // NEW (v1.8)
    float m_pitch;  // NEW (v1.8)
    float m_roll;  // NEW (v1.8)
    float m_x_local_velocity;          // NEW (v1.8) Velocity in local space
    float m_y_local_velocity;          // NEW (v1.8) Velocity in local space
    float m_z_local_velocity;          // NEW (v1.8) Velocity in local space
    float m_susp_acceleration[4];   // NEW (v1.8) RL, RR, FL, FR
    float m_ang_acc_x;                 // NEW (v1.8) angular acceleration x-component
    float m_ang_acc_y;                 // NEW (v1.8) angular acceleration y-component
    float m_ang_acc_z;                 // NEW (v1.8) angular acceleration z-component
};
#pragma pack(pop)

class Telemetry : public QObject
{
    Q_OBJECT

public:
    Telemetry(QObject *parent = 0);
    ~Telemetry();

    // Getters
    Q_INVOKABLE double getTime() const;
    Q_INVOKABLE double getLapTime() const;
    Q_INVOKABLE double getLapDistance() const;
    Q_INVOKABLE double getTotalDistance() const;
    Q_INVOKABLE double getWorldSpacePositionX() const;
    Q_INVOKABLE double getWorldSpacePositionY() const;
    Q_INVOKABLE double getWorldSpacePositionZ() const;
    Q_INVOKABLE double getSpeedInKPH() const;
    Q_INVOKABLE double getSpeedInMPH() const;
    Q_INVOKABLE double getWorldSpaceVelocityX() const;
    Q_INVOKABLE double getWorldSpaceVelocityY() const;
    Q_INVOKABLE double getWorldSpaceVelocityZ() const;
    Q_INVOKABLE double getWorldSpaceRightDirectionX() const;
    Q_INVOKABLE double getWorldSpaceRightDirectionY() const;
    Q_INVOKABLE double getWorldSpaceRightDirectionZ() const;
    Q_INVOKABLE double getWorldSpaceForwardDirectionX() const;
    Q_INVOKABLE double getWorldSpaceForwardDirectionY() const;
    Q_INVOKABLE double getWorldSpaceForwardDirectionZ() const;
    Q_INVOKABLE double getSuspPositionRearLeft() const;
    Q_INVOKABLE double getSuspPositionRearRight() const;
    Q_INVOKABLE double getSuspPositionFrontLeft() const;
    Q_INVOKABLE double getSuspPositionFrontRight() const;
    Q_INVOKABLE double getSuspVelocityRearLeft() const;
    Q_INVOKABLE double getSuspVelocityRearRight() const;
    Q_INVOKABLE double getSuspVelocityFrontLeft() const;
    Q_INVOKABLE double getSuspVelocityFrontRight() const;
    Q_INVOKABLE double getWheelSpeedRearLeft() const;
    Q_INVOKABLE double getWheelSpeedRearRight() const;
    Q_INVOKABLE double getWheelSpeedFrontLeft() const;
    Q_INVOKABLE double getWheelSpeedFrontRight() const;
    Q_INVOKABLE double getThrottle() const;
    Q_INVOKABLE double getSteer() const;
    Q_INVOKABLE double getBrake() const;
    Q_INVOKABLE double getClutch() const;
    Q_INVOKABLE double getGear() const;
    Q_INVOKABLE double getGForceLatitude() const;
    Q_INVOKABLE double getGForceLongitude() const;
    Q_INVOKABLE double getLap() const;
    Q_INVOKABLE double getEngineRate() const;
    Q_INVOKABLE double getSLIProNativeSupport() const;
    Q_INVOKABLE double getCarPosition() const;
    Q_INVOKABLE double getKersLevel() const;
    Q_INVOKABLE double getKersMaxLevel() const;
    Q_INVOKABLE double getDRS() const;
    Q_INVOKABLE double getTractionControl() const;
    Q_INVOKABLE double getAntiLockBrakes() const;
    Q_INVOKABLE double getFuelInTank() const;
    Q_INVOKABLE double getFuelCapacity() const;
    Q_INVOKABLE double getInPits() const;
    Q_INVOKABLE double getSector() const;
    Q_INVOKABLE double getSectorOneTime() const;
    Q_INVOKABLE double getSectorTwoTime() const;
    Q_INVOKABLE double getBrakeTemperatureRearLeft() const;
    Q_INVOKABLE double getBrakeTemperatureRearRight() const;
    Q_INVOKABLE double getBrakeTemperatureFrontLeft() const;
    Q_INVOKABLE double getBrakeTemperatureFrontRight() const;
    Q_INVOKABLE double getTyrePressureRearLeft() const;
    Q_INVOKABLE double getTyrePressureRearRight() const;
    Q_INVOKABLE double getTyrePressureFrontLeft() const;
    Q_INVOKABLE double getTyrePressureFrontRight() const;
    Q_INVOKABLE double getTeamInfo() const;
    Q_INVOKABLE double getTotalLaps() const;
    Q_INVOKABLE double getTrackSize() const;
    Q_INVOKABLE double getLastLapTime() const;
    Q_INVOKABLE double getMaxRPM() const;
    Q_INVOKABLE double getIdleRPM() const;
    Q_INVOKABLE double getMaxGears() const;
    Q_INVOKABLE double getSessionType() const;
    Q_INVOKABLE double getDRSAllowed() const;
    Q_INVOKABLE double getTrackNumber() const;
    Q_INVOKABLE double getVehicleFIAFlags() const;
    Q_INVOKABLE double getEra() const;
    Q_INVOKABLE double getEngineTemperature() const;
    Q_INVOKABLE double getGForceVertical() const;
    Q_INVOKABLE double getAngularVelocityX() const;
    Q_INVOKABLE double getAngularVelocityY() const;
    Q_INVOKABLE double getAngularVelocityZ() const;
    Q_INVOKABLE int getTyresTemperatureRearLeft() const;
    Q_INVOKABLE int getTyresTemperatureRearRight() const;
    Q_INVOKABLE int getTyresTemperatureFrontLeft() const;
    Q_INVOKABLE int getTyresTemperatureFrontRight() const;
    Q_INVOKABLE int getTyresWearRearLeft() const;
    Q_INVOKABLE int getTyresWearRearRight() const;
    Q_INVOKABLE int getTyresWearFrontLeft() const;
    Q_INVOKABLE int getTyresWearFrontRight() const;
    Q_INVOKABLE int getTyreCompound() const;
    Q_INVOKABLE int getFrontBrakeBias() const;
    Q_INVOKABLE int getFuelMix() const;
    Q_INVOKABLE int getCurrentLapInvalid() const;
    Q_INVOKABLE int getTyresDamageRearLeft() const;
    Q_INVOKABLE int getTyresDamageRearRight() const;
    Q_INVOKABLE int getTyresDamageFrontLeft() const;
    Q_INVOKABLE int getTyresDamageFrontRight() const;
    Q_INVOKABLE int getFrontLeftWingDamage() const;
    Q_INVOKABLE int getFrontRightWingDamage() const;
    Q_INVOKABLE int getRearWingDamage() const;
    Q_INVOKABLE int getEngineDamage() const;
    Q_INVOKABLE int getGearBoxDamage() const;
    Q_INVOKABLE int getExhaustDamage() const;
    Q_INVOKABLE int getPitLimiterStatus() const;
    Q_INVOKABLE int getPitSpeedLimit() const;
    Q_INVOKABLE double getSessionTimeLeft() const;
    Q_INVOKABLE int getRevLightsPercent() const;
    Q_INVOKABLE int getIsSpectating() const;
    Q_INVOKABLE int getSpectatorCarIndex() const;

    // Car data
    Q_INVOKABLE int getNumberOfCars() const;
    Q_INVOKABLE int getPlayerCarIndex() const;
    Q_INVOKABLE double getYaw() const;
    Q_INVOKABLE double getPitch() const;
    Q_INVOKABLE double getRoll() const;
    Q_INVOKABLE double getLocalSpaceVelocityX() const;
    Q_INVOKABLE double getLocalSpaceVelocityY() const;
    Q_INVOKABLE double getLocalSpaceVelocityZ() const;
    Q_INVOKABLE double getSuspAccelerationRearLeft() const;
    Q_INVOKABLE double getSuspAccelerationRearRight() const;
    Q_INVOKABLE double getSuspAccelerationFrontLeft() const;
    Q_INVOKABLE double getSuspAccelerationFrontRight() const;
    Q_INVOKABLE double getAngularAccelerationX() const;
    Q_INVOKABLE double getAngularAccelerationY() const;
    Q_INVOKABLE double getAngularAccelerationZ() const;

    // CarUDPData
    Q_INVOKABLE double getWorldPositionXForCar(int carIndex) const;
    Q_INVOKABLE double getWorldPositionYForCar(int carIndex) const;
    Q_INVOKABLE double getWorldPositionZForCar(int carIndex) const;
    Q_INVOKABLE double getLastLapTimeForCar(int carIndex) const;
    Q_INVOKABLE double getCurrentLapTimeForCar(int carIndex) const;
    Q_INVOKABLE double getBestLapTimeForCar(int carIndex) const;
    Q_INVOKABLE double getSectorOneTimeForCar(int carIndex) const;
    Q_INVOKABLE double getSectorTwoTimeForCar(int carIndex) const;
    Q_INVOKABLE double getLapDistanceForCar(int carIndex) const;
    Q_INVOKABLE int getDriverIdForCar(int carIndex) const;
    Q_INVOKABLE int getTeamIdForCar(int carIndex) const;
    Q_INVOKABLE int getCarPositionForCar(int carIndex) const;
    Q_INVOKABLE int getCurrentLapNumberForCar(int carIndex) const;
    Q_INVOKABLE int getTyreCompoundForCar(int carIndex) const;
    Q_INVOKABLE int getInPitsForCar(int carIndex) const;
    Q_INVOKABLE int getSectorForCar(int carIndex) const;
    Q_INVOKABLE int getCurrentLapInvalidForCar(int carIndex) const;
    Q_INVOKABLE int getPenaltiesForCar(int carIndex) const;
    Q_INVOKABLE int getCarIndexForCarInPosition(int carPosition) const;

    // Get string
    Q_INVOKABLE QString getDRSInString() const;
    Q_INVOKABLE QString getTractionControlInString() const;
    Q_INVOKABLE QString getAntiLockBrakesInString() const;
    Q_INVOKABLE QString getInPitsInString() const;
    Q_INVOKABLE QString getSectorInString() const;
    Q_INVOKABLE QString getTeamIdInString() const;
    Q_INVOKABLE QString getSessionTypeInString() const;
    Q_INVOKABLE QString getDRSAllowedInString() const;
    Q_INVOKABLE QString getTrackNameInString() const;
    Q_INVOKABLE QString getVehicleFIAFlagsInString() const;
    Q_INVOKABLE QString getEraInString() const;
    Q_INVOKABLE QString getTyreCompoundInString() const;
    Q_INVOKABLE QString getPitLimiterStatusInString() const;
    Q_INVOKABLE QString getDriverIdForCarInString(int carIndex) const;
    Q_INVOKABLE QString getClassicDriverIdForCarInString(int carIndex) const;
    Q_INVOKABLE QString getTeamIdForCarInString(int carIndex) const;
    Q_INVOKABLE QString getTyreCompoundForCarInString(int carIndex) const;
    Q_INVOKABLE QString getInPitsForCarInString(int carIndex) const;
    Q_INVOKABLE QString getSectorForCarInString(int carIndex) const;
    Q_INVOKABLE QString getCurrentLapInvalidForCarInString(int carIndex) const;

private slots:
    void processPendingDatagrams();

private:
    float time;
    float lapTime;
    float lapDistance;
    float totalDistance;
    float worldSpacePositionX;
    float worldSpacePositionY;
    float worldSpacePositionZ;
    float speedInKPH;
    float speedInMPH;
    float worldSpaceVelocityX;
    float worldSpaceVelocityY;
    float worldSpaceVelocityZ;
    float worldSpaceRightDirectionX;
    float worldSpaceRightDirectionY;
    float worldSpaceRightDirectionZ;
    float worldSpaceForwardDirectionX;
    float worldSpaceForwardDirectionY;
    float worldSpaceForwardDirectionZ;
    float suspPositionRearLeft;
    float suspPositionRearRight;
    float suspPositionFrontLeft;
    float suspPositionFrontRight;
    float suspVelocityRearLeft;
    float suspVelocityRearRight;
    float suspVelocityFrontLeft;
    float suspVelocityFrontRight;
    float wheelSpeedRearLeft;
    float wheelSpeedRearRight;
    float wheelSpeedFrontLeft;
    float wheelSpeedFrontRight;
    float throttle;
    float steer;
    float brake;
    float clutch;
    float gear;
    float gForceLatitude;
    float gForceLongitude;
    float lap;
    float engineRate;
    float sliProNativeSupport;
    float carPosition;
    float kersLevel;
    float kersMaxLevel;
    float drs;
    float tractionControl;
    float antiLockBrakes;
    float fuelInTank;
    float fuelCapacity;
    float inPits;
    float sector;
    float sectorOneTime;
    float sectorTwoTime;
    float brakeTemperatureRearLeft;
    float brakeTemperatureRearRight;
    float brakeTemperatureFrontLeft;
    float brakeTemperatureFrontRight;
    float tyrePressureRearLeft;
    float tyrePressureRearRight;
    float tyrePressureFrontLeft;
    float tyrePressureFrontRight;
    float teamInfo;
    float totalLaps;
    float trackSize;
    float lastLapTime;
    float maxRPM;
    float idleRPM;
    float maxGears;
    float sessionType;
    float drsAllowed;
    float trackNumber;
    float vehicleFIAFlags;
    float era;
    float engineTemperature;
    float gForceVertical;
    float angularVelocityX;
    float angularVelocityY;
    float angularVelocityZ;
    char tyresTemperatureRearLeft;
    char tyresTemperatureRearRight;
    char tyresTemperatureFrontLeft;
    char tyresTemperatureFrontRight;
    char tyresWearRearLeft;
    char tyresWearRearRight;
    char tyresWearFrontLeft;
    char tyresWearFrontRight;
    char tyreCompound;
    char frontBrakeBias;
    char fuelMix;
    char currentLapInvalid;
    char tyresDamageRearLeft;
    char tyresDamageRearRight;
    char tyresDamageFrontLeft;
    char tyresDamageFrontRight;
    char frontLeftWingDamage;
    char frontRightWingDamage;
    char rearWingDamage;
    char engineDamage;
    char gearBoxDamage;
    char exhaustDamage;
    char pitLimiterStatus;
    char pitSpeedLimit;
    float sessionTimeLeft;
    char revLightsPercent;
    char isSpectating;
    char spectatorCarIndex;

    // Car data
    char numberOfCars;
    char playerCarIndex;
    float yaw;
    float pitch;
    float roll;
    float localSpaceVelocityX;
    float localSpaceVelocityY;
    float localSpaceVelocityZ;
    float suspAccelerationRearLeft;
    float suspAccelerationRearRight;
    float suspAccelerationFrontLeft;
    float suspAccelerationFrontRight;
    float angularAccelerationX;
    float angularAccelerationY;
    float angularAccelerationZ;

    QUdpSocket *udpSocket;
    UDPPacket *udpPacket;
    CarUDPData *carUDPData;
    CarUDPData carUDPDataLocal[20];
};

#endif // TELEMETRY_H

