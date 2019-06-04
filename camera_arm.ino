#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 150
#define SERVOMAX 600
#define CENTER 375

void setup() {
    pwm.begin();
    pwm.setPWMFreq(60);
    Serial.begin(9600);
    Serial.println();
}

void loop() {
    if (Serial.available() > 0) {
        int ch = Serial.parseInt();
        int value = Serial.parseInt();
        int angle = 180;
        angle = map(value, 0, 180, SERVOMIN, SERVOMAX);
        Serial.readStringUntil('\n');
        Serial.println(String("servo[") + ch + "].write(" + value + ")" );
        pwm.setPWM(ch, 0, angle);
        delay(500);
        }
    }
