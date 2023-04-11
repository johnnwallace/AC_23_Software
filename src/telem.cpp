#include "utils.h"
#include "telem.h"

Telem::Telem(Adafruit_BNO055 *imu, Adafruit_BMP3XX *baro)
    : imu(imu), baro(baro) {

}

ReturnType Telem::init() {
    if(!imu->begin()) { return FAILURE; }
    imu->setExtCrystalUse(true);

    return SUCCESS;
}