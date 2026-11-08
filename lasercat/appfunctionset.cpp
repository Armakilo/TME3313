#include "cat.h"
#include "Arduino.h"




//globals that settings will change

uint8_t speed = 1; //1,2,3
bool noise = false;
bool mocap = false;

//globals for SM integration

Button Startf(){
  lcdwrite("> Start Play?");
  return wait_until();
  // uint8_t c_in;
  // while(c_in == Button::None) c_in = delay_in(5000);
}

  
Button Playf(){
  lcdwrite("> Playing");
  uint32_t timestart = millis();
  Button c_in = Button::None;
  while((c_in == Button::None) && (millis() - timestart < 300000)){ //timeout is at 30s
    c_in = delay_in(100); //checking for user input

    //servo commands based on current selected calibration and settings
    //TODO write servo running function

  } 

}

Button Settingsf(){
  lcdwrite("> Settings");
  return wait_until();
}


Button SpdSetf(){

  menuoptions("Settings", "Speed", speed);
  

}

Button NoiseSetf(){

}

Button PatternSetf(){

}

Button MoCapSetf(){

}

Button CalibMenf(){
  lcdwrite("> Calibrate");
  return wait_until();

}

Button CalibLf(){

}

Button CalibRf(){

}

Button CalibCf(){

}

