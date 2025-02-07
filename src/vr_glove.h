#include <NimBLEHIDDevice.h>
#include <NimBLEDevice.h>
#include <string>

#include "vr_glove_device_info.h"
#include "vr_glove_logger.h"

class VRGloveDevice {
private:
    static void taskCreateServer(void* pvParameter);
public:
    VRGloveDevice(std::string _gloveName, std::string _gloveManufacturer);
    void initialize();
    std::string gloveName;
    std::string gloveManufacturer;
};