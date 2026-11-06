#include "cat.h"
#include "Arduino.h"

#define PIN_Servo_z 9
#define PIN_Servo_y //fix these


//globals that settings will change

uint32_t speed = 10;
bool noise = false;
bool mocap = false;

//globals for SM integration

Button Startf(){
  lcdwrite("> Start Play?");
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);


  
Button Playf(){
  lcdwrite("> Playing")
  uint32_t timestart = millis();
  uint8_t c_in
  while((c_in == none) && (millis() - timestart < 300000)){ //timeout is at 30s
    c_in = delay_in(100); //checking for user input

    //servo commands based on current selected calibration and settings
    //TODO write servo running function

  } 

}

Button Settingsf(){
  Button ret = Button::None
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

}


Button SpdSetf(){

}

Button NoiseSetf(){

}

Button PatternSetf(){

}

Button MoCapSetf(){

}

Button CalibMenf(){

}

Button CalibLf(){

}

Button CalibRf(){

}

Button CalibCf(){

}

