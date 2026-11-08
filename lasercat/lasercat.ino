//lasercat.ino - toplevel file


// CatSeeking Laser source code. Written by Adam Bateman.
// November 7th, 2026


#include "cat.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;

//Make interrupts for button presses!!!! start with serial

void setup() {
  // put your setup code here, to run once:
  // Initialize the lcd
  lcd.init(); 
  // Turn on the Backlight
  lcd.backlight();

  Serial.begin(9600);

  pinMode(LEFT_BTN, INPUT); //left
  pinMode(CENT_BTN, INPUT); //center
  pinMode(RIGHT_BTN, INPUT); //right
  pinMode(BACK_BTN, INPUT); //back

  pinMode(MOTION, INPUT);

  pinMode(PIN_Servo_xy, OUTPUT); //servo lateral
  pinMode(PIN_Servo_z, OUTPUT); //servo vertical

}



void loop() {
  executeSM();
}
