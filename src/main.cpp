#include <Arduino.h>
#include <BleGamepad.h>

BleGamepad gamepad("HID Glove", "Caleb, Maika", 100);

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");
    gamepad.begin();
}

void loop() {
  if (gamepad.isConnected())
    {
        Serial.println("Press buttons 5, 16 and start. Move all enabled axes to max. Set DPAD (hat 1) to down right.");
        gamepad.press(BUTTON_5);
        gamepad.press(BUTTON_16);
        gamepad.pressStart();
        gamepad.setAxes(32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767);
        gamepad.setHat1(HAT_DOWN_RIGHT);
        // All axes, sliders, hats etc can also be set independently. See the IndividualAxes.ino example
        delay(500);

        Serial.println("Release button 5 and start. Move all axes to min. Set DPAD (hat 1) to centred.");
        gamepad.release(BUTTON_5);
        gamepad.releaseStart();
        gamepad.setHat1(HAT_CENTERED);
        gamepad.setAxes(0, 0, 0, 0, 0, 0, 0, 0);
        delay(500);
    }
}