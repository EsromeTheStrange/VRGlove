#include "vr_glove.h"

VRGloveDevice* pInstance;
NimBLEHIDDevice* pHidDevice;

VRGloveDevice::VRGloveDevice(std::string _gloveName, std::string _gloveManufacturer) : gloveName(_gloveName), gloveManufacturer(_gloveManufacturer) {
    pInstance = this;
    xTaskCreate(this->taskCreateServer, "server", 20000, (void *)this, 1, NULL);
}

void VRGloveDevice::taskCreateServer(void* pvParameter){
    NimBLEDevice::init(pInstance->gloveName);
    //TODO NimBLEDevice::setPower();
    NimBLEServer *pServer = NimBLEDevice::createServer();
    //TODO pServer->setCallbacks()

    //TODO Get Input Report

    //TODO Get Output Report

    //TODO Custom HID Report Stuff Here

    pHidDevice = new NimBLEHIDDevice(pServer);
    pHidDevice->setManufacturer(pInstance->gloveManufacturer);

    SetDeviceInfo(pServer);

    pHidDevice->setHidInfo(0x00, 0x01);
    //TODO pHidDevice->setPnp

    NimBLEDevice::setSecurityAuth(true, false, true);

    pHidDevice->startServices();
  
    NimBLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->setAppearance(HID_GAMEPAD);
    pAdvertising->setName(pInstance->gloveName);
    pAdvertising->addServiceUUID(pHidDevice->getHidService()->getUUID());
    pAdvertising->enableScanResponse(true);
    pAdvertising->start();
}