#include "cat.h"
#include "Arduino.h"

#define PIN_Servo_z 9
#define PIN_Servo_y //fix these


//globals that settings will change

enum class calibration{
  l_cl,
  l_far,
  r_cl,
  r_far,
  cent,
}


uint32_t speed = 10;
bool noise = false;
bool mocap = false;

calibration a = calibration::cent; //calibration starts at the center





uint8_t delay_in(uint32_t ms){
  uint8_t input;
  uint32_t tim = millis();

  while (millis()-tim > ms){
    delay(20);
    input = checkInput();
    if(input != 0){
      return input;
    }
  }

  return 0;
}

void lcdwrite(const char* message){
  uint8_t m_len = strlen(message);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("CatSeeking Laser");

  lcd.setCursor(0,1);
  lcd.print(message);
  

  delay(500);

}



void initMenuMode(const char * message, void (*enterBehav)(), void (*leftBehav)(), void (*rightBehav)()){
  lcdwrite(message);
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  switch(c_in){
    case enter: enterBehav(); break;
    case left: leftBehav(); break;
    case right: rightBehav(); break;
    default: break; 
  }

}

//from elegoo smartrobotcar v4
void Servo_move(unsigned int Position_angle)
{
  
  myservo.attach(PIN_Servo_z);
  myservo.write(Position_angle); //sets the servo position according to the 90（middle）
  delay(500); // could implemt wdt stuff
  myservo.detach();
}



uint8_t checkInput(){
  char rx_info;
  enum direction dir = none;
  

  // if(digitalRead(LEFT_BTN) == HIGH) dir = left; //you are saved... for now.
  // else if(digitalRead(CENT_BTN) == HIGH) dir = enter;
  // else if(digitalRead(RIGHT_BTN) == HIGH) dir = right;

  if(Serial.available()) {
    rx_info = Serial.read();
    if(rx_info == 'l') dir = left;
    else if (rx_info == 'e') dir = enter;
    else if (rx_info == 'r') dir = right;
    else if (rx_info == 'b') dir = back;

  }

  //Serial.println("get got");
  Serial.println(dir);
  return dir;

}



void StartMenu(){
  lcdwrite("> Start Play?");
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  void (*funcArr[])(void) = {Play, CalArea, Settings}; //enter, left, right
  if(c_in != back){
    funcArr[c_in]();
  }

  
  

}

void Settings(){
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  initMenuMode("Settings")

  void (*funcArr[])(void) = {Play, CalArea, Settings}; //enter, left, right
  if(c_in != back){
    funcArr[c_in]();
  }

}

void CalArea(){




}

void Play(){
  lcdwrite("> Playing")
  uint32_t timestart = millis();
  uint8_t c_in
  while((c_in == none) && (millis() - timestart < 200000)){ //timeout is at a 3rd of a minute
    c_in = delay_in(100); //checking for user input

    //servo commands based on 

  } 

  StartMenu()

  //servo routine in here


  }
  
}