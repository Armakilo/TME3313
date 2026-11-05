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
  // Clear the display buffer
  // lcd.clear(); 
  // // Set cursor (Column, Row)
  // lcd.setCursor(0, 0);
  // // print "Hello" at (0, 0)        
  // lcd.print("Hello"); 
  // // Set cursor (Column, Row)
  // lcd.setCursor(0,1);
  // // print "Geek" at (0, 1)
  // lcd.print("Geek");
  // delay(100);

  
  StartMenu();
  delay(1000);
  // put your main code here, to run repeatedly:
}
