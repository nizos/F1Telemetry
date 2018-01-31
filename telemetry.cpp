#include <QtNetwork>
#include "telemetry.h"

Telemetry::Telemetry(QObject *parent)
    : QObject(parent)
{

    udpPacket = new UDPPacket;
    carUDPData = new CarUDPData[20];

    time = 0.00;
    lapTime = 0.00;
    lapDistance = 0.00;
    totalDistance = 0.00;
    worldSpacePositionX = 0.00;
    worldSpacePositionY = 0.00;
    worldSpacePositionZ = 0.00;
    speedInKPH = 0.00;
    speedInMPH = 0.00;
    worldSpaceVelocityX = 0.00;
    worldSpaceVelocityY = 0.00;
    worldSpaceVelocityZ = 0.00;
    worldSpaceRightDirectionX = 0.00;
    worldSpaceRightDirectionY = 0.00;
    worldSpaceRightDirectionZ = 0.00;
    worldSpaceForwardDirectionX = 0.00;
    worldSpaceForwardDirectionY = 0.00;
    worldSpaceForwardDirectionZ = 0.00;
    suspPositionRearLeft = 0.00;
    suspPositionRearRight = 0.00;
    suspPositionFrontLeft = 0.00;
    suspPositionFrontRight = 0.00;
    suspVelocityRearLeft = 0.00;
    suspVelocityRearRight = 0.00;
    suspVelocityFrontLeft = 0.00;
    suspVelocityFrontRight = 0.00;
    wheelSpeedRearLeft = 0.00;
    wheelSpeedRearRight = 0.00;
    wheelSpeedFrontLeft = 0.00;
    wheelSpeedFrontRight = 0.00;
    throttle = 0.00;
    steer = 0.00;
    brake = 0.00;
    clutch = 0.00;
    gear = 0.00;
    gForceLatitude = 0.00;
    gForceLongitude = 0.00;
    lap = 0.00;
    engineRate = 0.00;
    sliProNativeSupport = 0.00;
    carPosition = 0.00;
    kersLevel = 0.00;
    kersMaxLevel = 0.00;
    drs = 0.00;
    tractionControl = 0.00;
    antiLockBrakes = 0.00;
    fuelInTank = 0.00;
    fuelCapacity = 0.00;
    inPits = 0.00;
    sector = 0.00;
    sectorOneTime = 0.00;
    sectorTwoTime = 0.00;
    brakeTemperatureRearLeft = 0.00;
    brakeTemperatureRearRight = 0.00;
    brakeTemperatureFrontLeft = 0.00;
    brakeTemperatureFrontRight = 0.00;
    tyrePressureRearLeft = 0.00;
    tyrePressureRearRight = 0.00;
    tyrePressureFrontLeft = 0.00;
    tyrePressureFrontRight = 0.00;
    teamInfo = 0.00;
    totalLaps = 0.00;
    trackSize = 0.00;
    lastLapTime = 0.00;
    maxRPM = 0.00;
    idleRPM = 0.00;
    maxGears = 0.00;
    sessionType = 0.00;
    drsAllowed = 0.00;
    trackNumber = 0.00;
    vehicleFIAFlags = 0.00;
    era = 0.00;
    engineTemperature = 0.00;
    gForceVertical = 0.00;
    angularVelocityX = 0.00;
    angularVelocityY = 0.00;
    angularVelocityZ = 0.00;
    tyresTemperatureRearLeft = 0;
    tyresTemperatureRearRight = 0;
    tyresTemperatureFrontLeft = 0;
    tyresTemperatureFrontRight = 0;
    tyresWearRearLeft = 0;
    tyresWearRearRight = 0;
    tyresWearFrontLeft = 0;
    tyresWearFrontRight = 0;
    tyreCompound = 0;
    frontBrakeBias = 0;
    fuelMix = 0;
    currentLapInvalid = 0;
    tyresDamageRearLeft = 0;
    tyresDamageRearRight = 0;
    tyresDamageFrontLeft = 0;
    tyresDamageFrontRight = 0;
    frontLeftWingDamage = 0;
    frontRightWingDamage = 0;
    rearWingDamage = 0;
    engineDamage = 0;
    gearBoxDamage = 0;
    exhaustDamage = 0;
    pitLimiterStatus = 0;
    pitSpeedLimit = 0;
    sessionTimeLeft = 0.00;
    revLightsPercent = 0;
    isSpectating = 0;
    spectatorCarIndex = 0;

    // Car data
    numberOfCars = 0;
    playerCarIndex = 0;

    // carUDPData
    for(int i = 0; i < 20; i++)
    {
        carUDPDataLocal[i].m_worldPosition[0] = 0.000;
        carUDPDataLocal[i].m_worldPosition[1] = 0.000;
        carUDPDataLocal[i].m_worldPosition[2] = 0.000;
        carUDPDataLocal[i].m_lastLapTime = 0.000;
        carUDPDataLocal[i].m_currentLapTime = 0.000;
        carUDPDataLocal[i].m_bestLapTime = 0.000;
        carUDPDataLocal[i].m_sector1Time = 0.000;
        carUDPDataLocal[i].m_sector2Time = 0.000;
        carUDPDataLocal[i].m_lapDistance = 0.000;
        carUDPDataLocal[i].m_driverId = 0;
        carUDPDataLocal[i].m_teamId = 0;
        carUDPDataLocal[i].m_carPosition = 0;
        carUDPDataLocal[i].m_currentLapNum = 0;
        carUDPDataLocal[i].m_tyreCompound = 0;
        carUDPDataLocal[i].m_inPits = 0;
        carUDPDataLocal[i].m_sector = 0;
        carUDPDataLocal[i].m_currentLapInvalid = 0;
        carUDPDataLocal[i].m_penalties = 0;
    }

    yaw = 0.00;
    pitch = 0.00;
    roll = 0.00;
    localSpaceVelocityX = 0.00;
    localSpaceVelocityY = 0.00;
    localSpaceVelocityZ = 0.00;
    suspAccelerationRearLeft = 0.00;
    suspAccelerationRearRight = 0.00;
    suspAccelerationFrontLeft = 0.00;
    suspAccelerationFrontRight = 0.00;
    angularAccelerationX = 0.00;
    angularAccelerationY = 0.00;
    angularAccelerationZ = 0.00;

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(20777, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

Telemetry::~Telemetry()
{

}

void Telemetry::processPendingDatagrams()
{
    QByteArray datagram;
    while (udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        udpPacket = reinterpret_cast<UDPPacket*>(datagram.data());
//        carUDPData = reinterpret_cast<CarUDPData*>(udpPacket->m_car_data);

//        for(int i = 0; i < 20; i++)
//        {
//            carUDPData[i] = udpPacket->m_car_data[i];
//        }

//        for(int i = 0; i < 20; i++)
//        {
//            qDebug();
//        }


        time = udpPacket->m_time;
        lapTime = udpPacket->m_lapTime;
        lapDistance = udpPacket->m_lapDistance;
        totalDistance = udpPacket->m_totalDistance;
        worldSpacePositionX =  udpPacket->m_x;
        worldSpacePositionY = udpPacket->m_y;
        worldSpacePositionZ = udpPacket->m_z;
        speedInKPH = udpPacket->m_speed*3.6;
        speedInMPH = udpPacket->m_speed*2.23694;
        worldSpaceVelocityX = udpPacket->m_xv;
        worldSpaceVelocityY = udpPacket->m_yv;
        worldSpaceVelocityZ = udpPacket->m_zv;
        worldSpaceRightDirectionX = udpPacket->m_xr;
        worldSpaceRightDirectionY = udpPacket->m_yr;
        worldSpaceRightDirectionZ = udpPacket->m_zr;
        worldSpaceForwardDirectionX = udpPacket->m_xd;
        worldSpaceForwardDirectionY = udpPacket->m_yd;
        worldSpaceForwardDirectionZ = udpPacket->m_zd;
        suspPositionRearLeft = udpPacket->m_susp_pos[0];
        suspPositionRearRight = udpPacket->m_susp_pos[1];
        suspPositionFrontLeft = udpPacket->m_susp_pos[2];
        suspPositionFrontRight = udpPacket->m_susp_pos[3];
        suspVelocityRearLeft = udpPacket->m_susp_vel[0];
        suspVelocityRearRight = udpPacket->m_susp_vel[1];
        suspVelocityFrontLeft = udpPacket->m_susp_vel[2];
        suspVelocityFrontRight = udpPacket->m_susp_vel[3];
        wheelSpeedRearLeft = udpPacket->m_wheel_speed[0];
        wheelSpeedRearRight = udpPacket->m_wheel_speed[1];
        wheelSpeedFrontLeft = udpPacket->m_wheel_speed[2];
        wheelSpeedFrontRight = udpPacket->m_wheel_speed[3];
        throttle = udpPacket->m_throttle;
        steer = udpPacket->m_steer;
        brake = udpPacket->m_brake;
        clutch = udpPacket->m_clutch;
        gear = udpPacket->m_gear;
        gForceLatitude = udpPacket->m_gforce_lat;
        gForceLongitude = udpPacket->m_gforce_lon;
        lap = udpPacket->m_lap;
        engineRate = udpPacket->m_engineRate;
        sliProNativeSupport = udpPacket->m_sli_pro_native_support;
        carPosition = udpPacket->m_car_position;
        kersLevel = udpPacket->m_kers_level;
        kersMaxLevel = udpPacket->m_kers_max_level;
        drs = udpPacket->m_drs;
        tractionControl = udpPacket->m_traction_control;
        antiLockBrakes = udpPacket->m_anti_lock_brakes;
        fuelInTank = udpPacket->m_fuel_in_tank;
        fuelCapacity = udpPacket->m_fuel_capacity;
        inPits = udpPacket->m_in_pits;
        sector = udpPacket->m_sector;
        sectorOneTime = udpPacket->m_sector1_time;
        sectorTwoTime = udpPacket->m_sector2_time;
        brakeTemperatureRearLeft = udpPacket->m_brakes_temp[0];
        brakeTemperatureRearRight = udpPacket->m_brakes_temp[1];
        brakeTemperatureFrontLeft = udpPacket->m_brakes_temp[2];
        brakeTemperatureFrontRight = udpPacket->m_brakes_temp[3];
        tyrePressureRearLeft = udpPacket->m_tyres_pressure[0];
        tyrePressureRearRight = udpPacket->m_tyres_pressure[1];
        tyrePressureFrontLeft = udpPacket->m_tyres_pressure[2];
        tyrePressureFrontRight = udpPacket->m_tyres_pressure[3];
        teamInfo = udpPacket->m_team_info;
        totalLaps = udpPacket->m_total_laps;
        trackSize = udpPacket->m_track_size;
        lastLapTime = udpPacket->m_last_lap_time;
        maxRPM = udpPacket->m_max_rpm;
        idleRPM = udpPacket->m_idle_rpm;
        maxGears = udpPacket->m_max_gears;
        sessionType = udpPacket->m_sessionType;
        drsAllowed = udpPacket->m_drsAllowed;
        trackNumber = udpPacket->m_track_number;
        vehicleFIAFlags = udpPacket->m_vehicleFIAFlags;
        era = udpPacket->m_era;
        engineTemperature = udpPacket->m_engine_temperature;
        gForceVertical = udpPacket->m_gforce_vert;
        angularVelocityX = udpPacket->m_ang_vel_x;
        angularVelocityY = udpPacket->m_ang_vel_y;
        angularVelocityZ = udpPacket->m_ang_vel_z;
        tyresTemperatureRearLeft = udpPacket->m_tyres_temperature[0];
        tyresTemperatureRearRight = udpPacket->m_tyres_temperature[1];
        tyresTemperatureFrontLeft = udpPacket->m_tyres_temperature[2];
        tyresTemperatureFrontRight = udpPacket->m_tyres_temperature[3];
        tyresWearRearLeft = udpPacket->m_tyres_wear[0];
        tyresWearRearRight = udpPacket->m_tyres_wear[1];
        tyresWearFrontLeft = udpPacket->m_tyres_wear[2];
        tyresWearFrontRight = udpPacket->m_tyres_wear[3];
        tyreCompound = udpPacket->m_tyre_compound;
        frontBrakeBias = udpPacket->m_front_brake_bias;
        fuelMix = udpPacket->m_fuel_mix;
        currentLapInvalid = udpPacket->m_currentLapInvalid;
        tyresDamageRearLeft = udpPacket->m_tyres_damage[0];
        tyresDamageRearRight = udpPacket->m_tyres_damage[1];
        tyresDamageFrontLeft = udpPacket->m_tyres_damage[2];
        tyresDamageFrontRight = udpPacket->m_tyres_damage[3];
        frontLeftWingDamage = udpPacket->m_front_left_wing_damage;
        frontRightWingDamage = udpPacket->m_front_right_wing_damage;
        rearWingDamage = udpPacket->m_rear_wing_damage;
        engineDamage = udpPacket->m_engine_damage;
        gearBoxDamage = udpPacket->m_gear_box_damage;
        exhaustDamage = udpPacket->m_exhaust_damage;
        pitLimiterStatus = udpPacket->m_pit_limiter_status;
        pitSpeedLimit = udpPacket->m_pit_speed_limit;
        sessionTimeLeft = udpPacket->m_session_time_left;
        revLightsPercent = udpPacket->m_rev_lights_percent;
        isSpectating = udpPacket->m_is_spectating;
        spectatorCarIndex = udpPacket->m_spectator_car_index;

        // Car data
        numberOfCars = udpPacket->m_num_cars;
        playerCarIndex = udpPacket->m_player_car_index;
//        carUDPDataLocal = udpPacket->m_car_data;

        for(int i = 0; i < 20; i++)
        {
            carUDPData[i] = udpPacket->m_car_data[i];
        }

//        for(int i = 0; i < 20; i++)
//        {
//            qDebug() << "carUDPDataLocal[" << i << "].m_worldPosition[0]: " << carUDPDataLocal[i].m_worldPosition[0];
//            qDebug() << "carUDPDataLocal[" << i << "].m_worldPosition[1]: " << carUDPDataLocal[i].m_worldPosition[1];
//            qDebug() << "carUDPDataLocal[" << i << "].m_worldPosition[2]: " << carUDPDataLocal[i].m_worldPosition[2];
//            qDebug() << "carUDPDataLocal[" << i << "].m_lastLapTime: " << carUDPDataLocal[i].m_lastLapTime;
//            qDebug() << "carUDPDataLocal[" << i << "].m_currentLapTime: " << carUDPDataLocal[i].m_currentLapTime;
//            qDebug() << "carUDPDataLocal[" << i << "].m_bestLapTime: " << carUDPDataLocal[i].m_bestLapTime;
//            qDebug() << "carUDPDataLocal[" << i << "].m_sector1Time: " << carUDPDataLocal[i].m_sector1Time;
//            qDebug() << "carUDPDataLocal[" << i << "].m_sector2Time: " << carUDPDataLocal[i].m_sector2Time;
//            qDebug() << "carUDPDataLocal[" << i << "].m_lapDistance: " << carUDPDataLocal[i].m_lapDistance;
//            qDebug() << "carUDPDataLocal[" << i << "].m_driverId: " << carUDPDataLocal[i].m_driverId;
//            qDebug() << "carUDPDataLocal[" << i << "].m_teamId: " << carUDPDataLocal[i].m_teamId;
//            qDebug() << "carUDPDataLocal[" << i << "].m_carPosition: " << carUDPDataLocal[i].m_carPosition;
//            qDebug() << "carUDPDataLocal[" << i << "].m_currentLapNum: " << carUDPDataLocal[i].m_currentLapNum;
//            qDebug() << "carUDPDataLocal[" << i << "].m_tyreCompound: " << carUDPDataLocal[i].m_tyreCompound;
//            qDebug() << "carUDPDataLocal[" << i << "].m_inPits: " << carUDPDataLocal[i].m_inPits;
//            qDebug() << "carUDPDataLocal[" << i << "].m_sector: " << carUDPDataLocal[i].m_sector;
//            qDebug() << "carUDPDataLocal[" << i << "].m_currentLapInvalid: " << carUDPDataLocal[i].m_currentLapInvalid;
//            qDebug() << "carUDPDataLocal[" << i << "].m_penalties: " << carUDPDataLocal[i].m_penalties;
//        }



//        for(int i = 0; i < 20; i++)
//        {
//            carUDPData[i].m_worldPosition[0] = udpPacket->m_car_data[i].m_worldPosition[0];

//            carUDPData[i].m_worldPosition[1] = udpPacket->m_car_data[i].m_worldPosition[1];

//            carUDPData[i].m_worldPosition[2] = udpPacket->m_car_data[i].m_worldPosition[2];

//            carUDPData[i].m_lastLapTime = udpPacket->m_car_data[i].m_lastLapTime;

//            carUDPData[i].m_currentLapTime = udpPacket->m_car_data[i].m_currentLapTime;

//            carUDPData[i].m_bestLapTime = udpPacket->m_car_data[i].m_bestLapTime;

//            carUDPData[i].m_sector1Time = udpPacket->m_car_data[i].m_sector1Time;

//            carUDPData[i].m_sector2Time = udpPacket->m_car_data[i].m_sector2Time;

//            carUDPData[i].m_lapDistance = udpPacket->m_car_data[i].m_lapDistance;

//            carUDPData[i].m_driverId = udpPacket->m_car_data[i].m_driverId;

//            carUDPData[i].m_teamId = udpPacket->m_car_data[i].m_teamId;

//            carUDPData[i].m_carPosition = udpPacket->m_car_data[i].m_carPosition;

//            carUDPData[i].m_currentLapNum = udpPacket->m_car_data[i].m_currentLapNum;

//            carUDPData[i].m_tyreCompound = udpPacket->m_car_data[i].m_tyreCompound;

//            carUDPData[i].m_inPits = udpPacket->m_car_data[i].m_inPits;

//            carUDPData[i].m_sector = udpPacket->m_car_data[i].m_sector;

//            carUDPData[i].m_currentLapInvalid = udpPacket->m_car_data[i].m_currentLapInvalid;

//            carUDPData[i].m_penalties = udpPacket->m_car_data[i].m_penalties;

//        }


        yaw = udpPacket->m_yaw;
        pitch = udpPacket->m_pitch;
        roll = udpPacket->m_roll;
        localSpaceVelocityX = udpPacket->m_x_local_velocity;
        localSpaceVelocityY = udpPacket->m_y_local_velocity;
        localSpaceVelocityZ = udpPacket->m_z_local_velocity;
        suspAccelerationRearLeft = udpPacket->m_susp_acceleration[0];
        suspAccelerationRearRight = udpPacket->m_susp_acceleration[1];
        suspAccelerationFrontLeft = udpPacket->m_susp_acceleration[2];
        suspAccelerationFrontRight = udpPacket->m_susp_acceleration[3];
        angularAccelerationX = udpPacket->m_ang_acc_x;
        angularAccelerationY = udpPacket->m_ang_acc_y;
        angularAccelerationZ = udpPacket->m_ang_acc_z;


    }
}


double Telemetry::getTime() const
{
    return static_cast<double>(this->time);
}

double Telemetry::getLapTime() const
{
    return static_cast<double>(this->lapTime);
}

double Telemetry::getLapDistance() const
{
    return static_cast<double>(this->lapDistance);
}

double Telemetry::getTotalDistance() const
{
    return static_cast<double>(this->totalDistance);
}


double Telemetry::getWorldSpacePositionX() const
{
    return static_cast<double>(this->worldSpacePositionX);
}

double Telemetry::getWorldSpacePositionY() const
{
    return static_cast<double>(this->worldSpacePositionY);
}

double Telemetry::getWorldSpacePositionZ() const
{
    return static_cast<double>(this->worldSpacePositionZ);
}

double Telemetry::getSpeedInKPH() const
{

    return this->speedInKPH;
}

double Telemetry::getSpeedInMPH() const
{
    return this->speedInMPH;
}

double Telemetry::getWorldSpaceVelocityX() const
{
    return static_cast<double>(this->worldSpaceVelocityX);
}

double Telemetry::getWorldSpaceVelocityY() const
{
    return static_cast<double>(this->worldSpaceVelocityY);
}

double Telemetry::getWorldSpaceVelocityZ() const
{
    return static_cast<double>(this->worldSpaceVelocityZ);
}

double Telemetry::getWorldSpaceRightDirectionX() const
{
    return static_cast<double>(this->worldSpaceRightDirectionX);
}

double Telemetry::getWorldSpaceRightDirectionY() const
{
    return static_cast<double>(this->worldSpaceRightDirectionY);
}

double Telemetry::getWorldSpaceRightDirectionZ() const
{
    return static_cast<double>(this->worldSpaceRightDirectionZ);
}

double Telemetry::getWorldSpaceForwardDirectionX() const
{
    return static_cast<double>(this->worldSpaceForwardDirectionX);
}

double Telemetry::getWorldSpaceForwardDirectionY() const
{
    return static_cast<double>(this->worldSpaceForwardDirectionY);
}

double Telemetry::getWorldSpaceForwardDirectionZ() const
{
    return static_cast<double>(this->worldSpaceForwardDirectionZ);
}

double Telemetry::getSuspPositionRearLeft() const
{
    return static_cast<double>(this->suspPositionRearLeft);
}

double Telemetry::getSuspPositionRearRight() const
{
    return static_cast<double>(this->suspPositionRearRight);
}

double Telemetry::getSuspPositionFrontLeft() const
{
    return static_cast<double>(this->suspPositionFrontLeft);
}

double Telemetry::getSuspPositionFrontRight() const
{
    return static_cast<double>(this->suspPositionFrontRight);
}

double Telemetry::getSuspVelocityRearLeft() const
{
    return static_cast<double>(this->suspVelocityRearLeft);
}

double Telemetry::getSuspVelocityRearRight() const
{
    return static_cast<double>(this->suspVelocityRearRight);
}

double Telemetry::getSuspVelocityFrontLeft() const
{
    return static_cast<double>(this->suspVelocityFrontLeft);
}

double Telemetry::getSuspVelocityFrontRight() const
{
    return static_cast<double>(this->suspVelocityFrontRight);
}

double Telemetry::getWheelSpeedRearLeft() const
{
    return static_cast<double>(this->wheelSpeedRearLeft);
}

double Telemetry::getWheelSpeedRearRight() const
{
    return static_cast<double>(this->wheelSpeedRearRight);
}

double Telemetry::getWheelSpeedFrontLeft() const
{
    return static_cast<double>(this->wheelSpeedFrontLeft);
}

double Telemetry::getWheelSpeedFrontRight() const
{
    return static_cast<double>(this->wheelSpeedFrontRight);
}

double Telemetry::getThrottle() const
{
    return static_cast<double>(this->throttle);
}

double Telemetry::getSteer() const
{
    return static_cast<double>(this->steer);
}

double Telemetry::getBrake() const
{
    return static_cast<double>(this->brake);
}

double Telemetry::getClutch() const
{
    return static_cast<double>(this->clutch);
}

double Telemetry::getGear() const
{
    return static_cast<double>(this->gear);
}

double Telemetry::getGForceLatitude() const
{
    return static_cast<double>(this->gForceLatitude);
}

double Telemetry::getGForceLongitude() const
{
    return static_cast<double>(this->gForceLongitude);
}

double Telemetry::getLap() const
{
    return static_cast<double>(this->lap);
}

double Telemetry::getEngineRate() const
{
    return static_cast<double>(this->engineRate);
}

double Telemetry::getSLIProNativeSupport() const
{
    return static_cast<double>(this->sliProNativeSupport);
}

double Telemetry::getCarPosition() const
{
    return static_cast<double>(this->carPosition);
}

double Telemetry::getKersLevel() const
{
    return static_cast<double>(this->kersLevel);
}

double Telemetry::getKersMaxLevel() const
{
    return static_cast<double>(this->kersMaxLevel);
}

double Telemetry::getDRS() const
{
    return static_cast<double>(this->drs);
}

double Telemetry::getTractionControl() const
{
    return static_cast<double>(this->tractionControl);
}

double Telemetry::getAntiLockBrakes() const
{
    return static_cast<double>(this->antiLockBrakes);
}

double Telemetry::getFuelInTank() const
{
    return static_cast<double>(this->fuelInTank);
}

double Telemetry::getFuelCapacity() const
{
    return static_cast<double>(this->fuelCapacity);
}

double Telemetry::getInPits() const
{
    return static_cast<double>(this->inPits);
}

double Telemetry::getSector() const
{
    return static_cast<double>(this->sector);
}

double Telemetry::getSectorOneTime() const
{
    return static_cast<double>(this->sectorOneTime);
}

double Telemetry::getSectorTwoTime() const
{
    return static_cast<double>(this->sectorTwoTime);
}

double Telemetry::getBrakeTemperatureRearLeft() const
{
    return static_cast<double>(this->brakeTemperatureRearLeft);
}

double Telemetry::getBrakeTemperatureRearRight() const
{
    return static_cast<double>(this->brakeTemperatureRearRight);
}

double Telemetry::getBrakeTemperatureFrontLeft() const
{
    return static_cast<double>(this->brakeTemperatureFrontLeft);
}

double Telemetry::getBrakeTemperatureFrontRight() const
{
    return static_cast<double>(this->brakeTemperatureFrontRight);
}

double Telemetry::getTyrePressureRearLeft() const
{
    return static_cast<double>(this->tyrePressureRearLeft);
}

double Telemetry::getTyrePressureRearRight() const
{
    return static_cast<double>(this->tyrePressureRearRight);
}

double Telemetry::getTyrePressureFrontLeft() const
{
    return static_cast<double>(this->tyrePressureFrontLeft);
}

double Telemetry::getTyrePressureFrontRight() const
{
    return static_cast<double>(this->tyrePressureFrontRight);
}

double Telemetry::getTeamInfo() const
{
    return static_cast<double>(this->teamInfo);
}

double Telemetry::getTotalLaps() const
{
    return static_cast<double>(this->totalLaps);
}

double Telemetry::getTrackSize() const
{
   return static_cast<double>(this->trackSize);
}

double Telemetry::getLastLapTime() const
{
    return static_cast<double>(this->lastLapTime);
}

double Telemetry::getMaxRPM() const
{
    return static_cast<double>(this->maxRPM);
}

double Telemetry::getIdleRPM() const
{
    return static_cast<double>(this->idleRPM);
}

double Telemetry::getMaxGears() const
{
    return static_cast<double>(this->maxGears);
}

double Telemetry::getSessionType() const
{
    return static_cast<double>(this->sessionType);
}

double Telemetry::getDRSAllowed() const
{
    return static_cast<double>(this->drsAllowed);
}

double Telemetry::getTrackNumber() const
{
    return static_cast<double>(this->trackNumber);
}

double Telemetry::getVehicleFIAFlags() const
{
    return static_cast<double>(this->vehicleFIAFlags);
}

double Telemetry::getEra() const
{
    return static_cast<double>(this->era);
}

double Telemetry::getEngineTemperature() const
{
    return static_cast<double>(this->engineTemperature);
}

double Telemetry::getGForceVertical() const
{
    return static_cast<double>(this->gForceVertical);
}

double Telemetry::getAngularVelocityX() const
{
    return static_cast<double>(this->angularVelocityX);
}

double Telemetry::getAngularVelocityY() const
{
    return static_cast<double>(this->angularVelocityY);
}

double Telemetry::getAngularVelocityZ() const
{
    return static_cast<double>(this->angularVelocityZ);
}

int Telemetry::getTyresTemperatureRearLeft() const
{
    return static_cast<int>(this->tyresTemperatureRearLeft);
}

int Telemetry::getTyresTemperatureRearRight() const
{
    return static_cast<int>(this->tyresTemperatureRearRight);
}

int Telemetry::getTyresTemperatureFrontLeft() const
{
    return static_cast<int>(this->tyresTemperatureFrontLeft);
}

int Telemetry::getTyresTemperatureFrontRight() const
{
    return static_cast<int>(this->tyresTemperatureFrontRight);
}

int Telemetry::getTyresWearRearLeft() const
{
    return static_cast<int>(this->tyresWearRearLeft);
}

int Telemetry::getTyresWearRearRight() const
{
    return static_cast<int>(this->tyresWearRearRight);
}

int Telemetry::getTyresWearFrontLeft() const
{
    return static_cast<int>(this->tyresWearFrontLeft);
}

int Telemetry::getTyresWearFrontRight() const
{
    return static_cast<int>(this->tyresWearFrontRight);
}

int Telemetry::getTyreCompound() const
{
    return static_cast<int>(this->tyreCompound);
}

int Telemetry::getFrontBrakeBias() const
{
    return static_cast<int>(this->frontBrakeBias);
}

int Telemetry::getFuelMix() const
{
    return static_cast<int>(this->fuelMix);
}

int Telemetry::getCurrentLapInvalid() const
{
    return static_cast<int>(this->currentLapInvalid);
}

int Telemetry::getTyresDamageRearLeft() const
{
    return static_cast<int>(this->tyresDamageRearLeft);
}

int Telemetry::getTyresDamageRearRight() const
{
    return static_cast<int>(this->tyresDamageRearRight);
}

int Telemetry::getTyresDamageFrontLeft() const
{
    return static_cast<int>(this->tyresDamageFrontLeft);
}

int Telemetry::getTyresDamageFrontRight() const
{
    return static_cast<int>(this->tyresDamageFrontRight);
}

int Telemetry::getFrontLeftWingDamage() const
{
    return static_cast<int>(this->frontLeftWingDamage);
}

int Telemetry::getFrontRightWingDamage() const
{
    return static_cast<int>(this->frontRightWingDamage);
}

int Telemetry::getRearWingDamage() const
{
    return static_cast<int>(this->rearWingDamage);
}

int Telemetry::getEngineDamage() const
{
    return static_cast<int>(this->engineDamage);
}

int Telemetry::getGearBoxDamage() const
{
    return static_cast<int>(this->gearBoxDamage);
}

int Telemetry::getExhaustDamage() const
{
    return static_cast<int>(this->exhaustDamage);
}

int Telemetry::getPitLimiterStatus() const
{
    return static_cast<int>(this->pitLimiterStatus);
}

int Telemetry::getPitSpeedLimit() const
{
    return static_cast<int>(this->pitSpeedLimit);
}

double Telemetry::getSessionTimeLeft() const
{
    return static_cast<double>(this->sessionTimeLeft);
}

int Telemetry::getRevLightsPercent() const
{
    return static_cast<int>(this->revLightsPercent);
}

int Telemetry::getIsSpectating() const
{
    return static_cast<int>(this->isSpectating);
}

int Telemetry::getSpectatorCarIndex() const
{
    return static_cast<int>(this->spectatorCarIndex);
}


// Car data
int Telemetry::getNumberOfCars() const
{
    return static_cast<int>(this->numberOfCars);
}

int Telemetry::getPlayerCarIndex() const
{
    return static_cast<int>(this->playerCarIndex);
}

double Telemetry::getYaw() const
{
    return static_cast<double>(this->yaw);
}

double Telemetry::getPitch() const
{
    return static_cast<double>(this->pitch);
}

double Telemetry::getRoll() const
{
    return static_cast<double>(this->roll);
}

double Telemetry::getLocalSpaceVelocityX() const
{
    return static_cast<double>(this->localSpaceVelocityX);
}

double Telemetry::getLocalSpaceVelocityY() const
{
    return static_cast<double>(this->localSpaceVelocityY);
}

double Telemetry::getLocalSpaceVelocityZ() const
{
    return static_cast<double>(this->localSpaceVelocityZ);
}

double Telemetry::getSuspAccelerationRearLeft() const
{
    return static_cast<double>(this->suspAccelerationRearLeft);
}

double Telemetry::getSuspAccelerationRearRight() const
{
    return static_cast<double>(this->suspAccelerationRearRight);
}

double Telemetry::getSuspAccelerationFrontLeft() const
{
    return static_cast<double>(this->suspAccelerationFrontLeft);
}

double Telemetry::getSuspAccelerationFrontRight() const
{
    return static_cast<double>(this->suspAccelerationFrontRight);
}

double Telemetry::getAngularAccelerationX() const
{
    return static_cast<double>(this->angularAccelerationX);
}

double Telemetry::getAngularAccelerationY() const
{
    return static_cast<double>(this->angularAccelerationY);
}

double Telemetry::getAngularAccelerationZ() const
{
    return static_cast<double>(this->angularAccelerationZ);
}


// CarUDPData
double Telemetry::getWorldPositionXForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_worldPosition[0]);
}

double Telemetry::getWorldPositionYForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_worldPosition[1]);
}

double Telemetry::getWorldPositionZForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_worldPosition[2]);
}

double Telemetry::getLastLapTimeForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_lastLapTime);
}

double Telemetry::getCurrentLapTimeForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_currentLapTime);
}

double Telemetry::getBestLapTimeForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_bestLapTime);
}

double Telemetry::getSectorOneTimeForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_sector1Time);
}

double Telemetry::getSectorTwoTimeForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_sector2Time);
}

double Telemetry::getLapDistanceForCar(int carIndex) const
{
    return static_cast<double>(this->carUDPData[carIndex].m_lapDistance);
}

int Telemetry::getDriverIdForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_driverId);
}

int Telemetry::getTeamIdForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_teamId);
}

int Telemetry::getCarPositionForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_carPosition);
}

int Telemetry::getCurrentLapNumberForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_currentLapNum);
}

int Telemetry::getTyreCompoundForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_tyreCompound);
}

int Telemetry::getInPitsForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_inPits);
}

int Telemetry::getSectorForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_sector);
}

int Telemetry::getCurrentLapInvalidForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_currentLapInvalid);
}

int Telemetry::getPenaltiesForCar(int carIndex) const
{
    return static_cast<int>(this->carUDPData[carIndex].m_penalties);
}

int Telemetry::getCarIndexForCarInPosition(int carPosition) const
{
    int carIndex = 0;
    for(int i = 0; i < numberOfCars; i++)
    {
        if(carUDPData[i].m_carPosition == carPosition)
        {
            carIndex = i;
        }
    }
    return static_cast<int>(carIndex);
}


// Get string
QString Telemetry::getDRSInString() const
{
    QString drs = "Unknown";
    switch(int(this->drs))
    {
        case 0 : drs = "Off";
        break;
        case 1 : drs = "On";
        break;
    }
    return drs;
}

QString Telemetry::getTractionControlInString() const
{
    QString tractionControl = "Unknown";
    switch(int(this->tractionControl))
    {
        case 0 : tractionControl = "Off";
        break;
        case 1 : tractionControl = "Medium";
        break;
        case 2 : tractionControl = "High";
        break;
    }
    return tractionControl;
}

QString Telemetry::getAntiLockBrakesInString() const
{
    QString antiLockBrakes = "Unknown";
    switch(int(this->antiLockBrakes))
    {
        case 0 : antiLockBrakes = "Off";
        break;
        case 1 : antiLockBrakes = "On";
        break;
    }
    return antiLockBrakes;
}

QString Telemetry::getInPitsInString() const
{
    QString inPits = "Unknown";
    switch(int(this->inPits))
    {
        case 0 : inPits = "None";
        break;
        case 1 : inPits = "Pitting";
        break;
        case 2 : inPits = "In pit area";
        break;
    }
    return inPits;
}

QString Telemetry::getSectorInString() const
{
    QString sector = "Unknown";
    switch(int(this->sector))
    {
        case 0 : sector = "S1";
        break;
        case 1 : sector = "S2";
        break;
        case 2 : sector = "S3";
        break;
    }
    return sector;
}

QString Telemetry::getTeamIdInString() const
{
    QString team = "Unknown";
    switch(int(this->teamInfo))
    {
        case 0 : team = "Redbull";
        break;
        case 1 : team = "Ferrari";
        break;
        case 2 : team = "McLaren";
        break;
        case 3 : team = "Renault";
        break;
        case 4 : team = "Mercedes";
        break;
        case 5 : team = "Sauber";
        break;
        case 6 : team = "Force India";
        break;
        case 7 : team = "Williams";
        break;
        case 8 : team = "Toro Rosso";
        break;
        case 11 : team = "Haas";
        break;
    }
    return team;
}

QString Telemetry::getSessionTypeInString() const
{
    QString sessionType = "Unknown";
    switch(int(this->sessionType))
    {
        case 1 : sessionType = "Practice";
        break;
        case 2 : sessionType = "Qualifying";
        break;
        case 3 : sessionType = "Race";
        break;
    }
    return sessionType;
}

QString Telemetry::getDRSAllowedInString() const
{
    QString drsAllowed = "Unknown";
    switch(int(this->drsAllowed))
    {
        case 0 : drsAllowed = "No";
        break;
        case 1 : drsAllowed = "Yes";
        break;
    }
    return drsAllowed;
}

QString Telemetry::getTrackNameInString() const
{
    QString track = "Unknown";
    switch(int(this->trackNumber))
    {
        case 0 : track = "Melbourne";
        break;
        case 1 : track = "Sepang";
        break;
        case 2 : track = "Shanghai";
        break;
        case 3 : track = "Sakhir";
        break;
        case 4 : track = "Catalunya";
        break;
        case 5 : track = "Monaco";
        break;
        case 6 : track = "Montreal";
        break;
        case 7 : track = "Silverstone";
        break;
        case 8 : track = "Hockenheim";
        break;
        case 9 : track = "Hungaroring";
        break;
        case 10 : track = "Spa";
        break;
        case 11 : track = "Monza";
        break;
        case 12 : track = "Singapore";
        break;
        case 13 : track = "Suzuka";
        break;
        case 14 : track = "Abu Dhabi";
        break;
        case 15 : track = "Texas";
        break;
        case 16 : track = "Brazil";
        break;
        case 17 : track = "Austria";
        break;
        case 18 : track = "Sochi";
        break;
        case 19 : track = "Mexico";
        break;
        case 20 : track = "Baku";
        break;
        case 21 : track = "Sakhir Short";
        break;
        case 22 : track = "Silverstone Short";
        break;
        case 23 : track = "Texas Short";
        break;
        case 24 : track = "Suzuka Short";
        break;
    }
    return track;
}

QString Telemetry::getVehicleFIAFlagsInString() const
{
    QString flags = "Unknown";
    switch(int(this->vehicleFIAFlags))
    {
        case 0 : flags = "None";
        break;
        case 1 : flags = "Green";
        break;
        case 2 : flags = "Blue";
        break;
        case 3 : flags = "Yellow";
        break;
        case 4 : flags = "Red";
        break;
    }
    return flags;
}

QString Telemetry::getEraInString() const
{
    QString era = "Unknown";
    switch(int(this->era))
    {
        case 1980 : era = "Classic";
        break;
        case 2017 : era = "Modern";
        break;
    }
    return era;
}

QString Telemetry::getTyreCompoundInString() const
{
    QString compound = "Unknown";
    switch(int(this->tyreCompound))
    {
        case 0 : compound = "Ultra soft";
        break;
        case 1 : compound = "Super soft";
        break;
        case 2 : compound = "Soft";
        break;
        case 3 : compound = "Medium";
        break;
        case 4 : compound = "Hard";
        break;
        case 5 : compound = "Inter";
        break;
        case 6 : compound = "Wet";
        break;
    }
    return compound;
}

QString Telemetry::getPitLimiterStatusInString() const
{
    QString status = "Unknown";
    switch(int(this->pitLimiterStatus))
    {
        case 0 : status = "Off";
        break;
        case 1 : status = "On";
        break;
    }
    return status;
}

QString Telemetry::getDriverIdForCarInString(int carIndex) const
{
    QString driverID = "Unknown";
    int driver = static_cast<int>(this->carUDPData[carIndex].m_driverId);
    switch(driver)
    {
        case 0 : driverID = "Sebastian Vettel";
                break;
        case 1 : driverID = "Daniil Kvyat";
                break;
        case 2 : driverID = "Fernando Alonso";
                break;
        case 3 : driverID = "Felipe Massa";
                break;
        case 5 : driverID = "Sergio Perez";
                break;
        case 6 : driverID = "Kimi Räikkönen";
                break;
        case 7 : driverID = "Romain Grosjean";
                break;
        case 9 : driverID = "Lewis Hamilton";
                break;
        case 10 : driverID = "Nico Hulkenberg";
                break;
        case 14 : driverID = "Kevin Magnussen";
                break;
        case 15 : driverID = "Valtteri Bottas";
                break;
        case 16 : driverID = "Daniel Ricciardo";
                break;
        case 18 : driverID = "Marcus Ericsson";
                break;
        case 20 : driverID = "Jolyon Palmer";
                break;
        case 22 : driverID = "Max Verstappen";
                break;
        case 23 : driverID = "Carlos Sainz Jr.";
                break;
        case 31 : driverID = "Pascal Wehrlein";
                break;
        case 33 : driverID = "Esteban Ocon";
                break;
        case 34 : driverID = "Stoffel Vandoorne";
                break;
        case 35 : driverID = "Lance Stroll";
                break;
    }
    return driverID;
}

QString Telemetry::getClassicDriverIdForCarInString(int carIndex) const
{
    QString classicDriverID = "Unknown";
    switch(int(this->carUDPData[carIndex].m_driverId))
    {

        case 0 : classicDriverID = "Klimek Michalski";
        break;
        case 1 : classicDriverID = "Martin Giles";
        break;
        case 2 : classicDriverID = "Igor Correia";
        break;
        case 3 : classicDriverID = "Sophie Levasseur";
        break;
        case 4 : classicDriverID = "Alain Forest";
        break;
        case 5 : classicDriverID = "Santiago Moreno";
        break;
        case 6 : classicDriverID = "Esto Saari";
        break;
        case 7 : classicDriverID = "Peter Belousov";
        break;
        case 8 : classicDriverID = "Lars Kaufmann";
        break;
        case 9 : classicDriverID = "Yasar Atiyeh";
        break;
        case 10 : classicDriverID = "Howard Clarke";
        break;
        case 14 : classicDriverID = "Marie Laursen";
        break;
        case 15 : classicDriverID = "Benjamin Coppens";
        break;
        case 16 : classicDriverID = "Alex Murray";
        break;
        case 18 : classicDriverID = "Callisto Calabresi";
        break;
        case 20 : classicDriverID = "Jay Letourneau";
        break;
        case 22 : classicDriverID = "Naota Izum";
        break;
        case 23 : classicDriverID = "Arron Barnes";
        break;
        case 24 : classicDriverID = "Jonas Schiffer";
        break;
        case 31 : classicDriverID = "Flavio Nieves";
        break;
        case 32 : classicDriverID = "Noah Visser";
        break;
        case 33 : classicDriverID = "Gert Waldmuller";
        break;
        case 34 : classicDriverID = "Julian Quesada";
        break;
        case 68 : classicDriverID = "Lucas Roth";
        break;
    }
    return classicDriverID;
}

QString Telemetry::getTeamIdForCarInString(int carIndex) const
{
    QString team = "Unknown";
    switch(int(this->carUDPData[carIndex].m_teamId))
    {
        case 0 : team = "Redbull";
        break;
        case 1 : team = "Ferrari";
        break;
        case 2 : team = "McLaren";
        break;
        case 3 : team = "Renault";
        break;
        case 4 : team = "Mercedes";
        break;
        case 5 : team = "Sauber";
        break;
        case 6 : team = "Force India";
        break;
        case 7 : team = "Williams";
        break;
        case 8 : team = "Toro Rosso";
        break;
        case 11 : team = "Haas";
        break;
    }
    return team;
}

QString Telemetry::getTyreCompoundForCarInString(int carIndex) const
{
    QString tyreCompound = "Unknown";
    switch(int(this->carUDPData[carIndex].m_tyreCompound))
    {
        case 0 : tyreCompound = "Ultra soft";
        break;
        case 1 : tyreCompound = "Super soft";
        break;
        case 2 : tyreCompound = "Soft";
        break;
        case 3 : tyreCompound = "Medium";
        break;
        case 4 : tyreCompound = "Hard";
        break;
        case 5 : tyreCompound = "Inter";
        break;
        case 6 : tyreCompound = "Wet";
        break;
    }
    return tyreCompound;
}

QString Telemetry::getInPitsForCarInString(int carIndex) const
{
    QString inPits = "Unknown";
    switch(int(this->carUDPData[carIndex].m_inPits))
    {
        case 0 : inPits = "None";
        break;
        case 1 : inPits = "Pitting";
        break;
        case 2 : inPits = "In pit area";
        break;
    }
    return inPits;
}

QString Telemetry::getSectorForCarInString(int carIndex) const
{
    QString sector = "Unknown";
    switch(int(this->carUDPData[carIndex].m_sector))
    {
        case 0 : sector = "S1";
        break;
        case 1 : sector = "S2";
        break;
        case 2 : sector = "S3";
        break;
    }
    return sector;
}

QString Telemetry::getCurrentLapInvalidForCarInString(int carIndex) const
{
    QString currentLap = "Unknown";
    switch(int(this->carUDPData[carIndex].m_currentLapInvalid))
    {
        case 0 : currentLap = "Valid";
        break;
        case 1 : currentLap = "Invalid";
        break;
    }
    return currentLap;
}
