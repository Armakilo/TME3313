//appfunctionset.cpp - set mode handler functions

#include "cat.h"

//globals that settings will change

uint8_t speed = 1; //1,2,3 for each setting
uint8_t pattern = 1;
uint8_t calibration = 1; //look at enum. spell this out in the user manual

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
  while((c_in == Button::None) && (millis() - timestart < 30000)){ //timeout is at 30s
    c_in = delay_in(100); //checking for user input

    //servo commands based on current selected calibration and settings
    
    Servo_move(0, PIN_Servo_z);
    Servo_move(180, PIN_Servo_z);

    

    Servo_move(0, PIN_Servo_xy);
    Servo_move(180, PIN_Servo_xy);

  } 
  return c_in;

}

Button Settingsf(){
  lcdwrite("> Settings");
  return wait_until();
}


Button SpdSetf(){

  return menuoptions("Settings", "Speed", &speed);

}

Button NoiseSetf(){
  return menuoptions("Settings", "Noise", &noise);
}

Button PatternSetf(){
  return menuoptions("Settings", "Pattern", &pattern); //my code is so clean ;)

}

Button MoCapSetf(){
  return menuoptions("Settings", "Motion Det.", &mocap);

}

Button CalibMenf(){
  lcdwrite("> Calibrate");
  return wait_until();

}

Button CalibSubf(){
  return menuoptions("Calibration", "Direction", &calibration);
}


