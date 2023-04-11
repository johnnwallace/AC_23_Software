#include <Adafruit_BNO055.h>
#include <Adafruit_BMP3XX.h>
#include <Orientation.h>

enum ReturnType {SUCCESS = 1, FAILURE = 0}; 

struct rawData{
    // system time
    unsigned int micros;

    // sensor data
    float altitude, velocity, acceleration, pressure, temp;
    sensors_event_t accelerometer, magnetometer, gyroscope, gravity;
};

class Telem{
    Adafruit_BNO055 *imu;
    Adafruit_BMP3XX *baro;

    unsigned int thisMicros, lastMicros;
    Orientation orientation;
    float velocity, acceleration;

    rawData thisData, lastData;

public:
    // Constructor takes sensor objects
    Telem(Adafruit_BNO055 *imu, Adafruit_BMP3XX *baro);

    // Calibrate initial orientation and altitude
    void calibrate(); 

    // Initialize IMU and barometer
    ReturnType init();

    // Collect sensor data
    void sensorEvent();

    // Return the rocket's current orientation in Euler angles
    EulerAngles getOrientation();

    // Return the rocket's current vertical velocity
    float getVelocity();

    // Return the rocket's current vertical acceleration
    float getAcceleration();
};
