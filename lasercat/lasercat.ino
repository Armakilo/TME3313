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

  pinMode(13, INPUT); //left
  pinMode(12, INPUT); //center
  pinMode(11, INPUT); //right
  pinMode(10, INPUT); //back

}



void loop() {
  executeSM();
}
