#include <Arduino.h>
#include <BleGamepad.h>

BleGamepad gamepad("HID Glove", "Caleb, Maika", 100);

#define LED_PIN 23
#define SEARCHING_BLINK_RATE 2000
#define CONNECTED_BLINK_RATE 200

#define JOINT_1 15
#define JOINT_2 2
#define JOINT_3 4

long lastBlink = 0;
bool currentLEDState = false;

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");
    gamepad.begin();

    pinMode(LED_PIN, OUTPUT);

    pinMode(JOINT_1, INPUT);
    pinMode(JOINT_2, INPUT);
    pinMode(JOINT_3, INPUT);
}


void toggleLed(){
    currentLEDState = !currentLEDState;
    lastBlink = millis();
    digitalWrite(LED_PIN, currentLEDState ? HIGH : LOW);
}

void loop() {
    if(gamepad.isConnected()){
        int joint1 = analogRead(JOINT_1);
        int joint2 = analogRead(JOINT_2);
        int joint3 = analogRead(JOINT_3);
        gamepad.setLeftThumb(joint1 * 8, joint2 * 8);
        gamepad.setLeftTrigger(joint3 * 8);
        gamepad.sendReport();
        Serial.print(joint1);
        Serial.print(" - ");
        Serial.print(joint2);
        Serial.print(" - ");
        Serial.println(joint3);
        delay(200);

        if (millis() - lastBlink > CONNECTED_BLINK_RATE)
            toggleLed();
    }else{
        if (millis() - lastBlink > SEARCHING_BLINK_RATE)
            toggleLed();
    }
}