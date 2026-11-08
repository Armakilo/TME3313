//driverset.cpp - set basic functions

#include "cat.h"

Button menuoptions(const char * menuName, const char * optionName, uint8_t * quality){
  char modstr[17];
  sprintf(modstr, "%s %d", optionName, *quality);; // pass global variable, cant do a pointer
  lcdwrite((const char *)modstr, menuName);
  Button input = Button::None;
  while((input != Button::Back) && (input != Button::Left) && (input != Button::Right)){
    input = wait_until();
    if(input == Button::Enter){
      *quality++;
      if(*quality > 3) *quality = 1; // HES GOT LOOPS!!
      sprintf(modstr, "%s %d", optionName, *quality); // pass global variable, cant do a pointer
      lcdwrite((const char *)modstr, menuName);
    }
  }
  return input;
}

Button menuoptions(const char * menuName, const char * optionName, bool * tf){ // overloading > parametrization
//pass values by reference, get de-referenced.
//function overloading only exists in C++, not portable back to C.  
  char modstr[17];
  char quality = *tf ? 'Y' : 'N'; //deref adress
  sprintf(modstr, "%s %d", optionName, quality); // pass global variable, cant do a pointer
  lcdwrite((const char *)modstr, menuName);
  Button input = wait_until();
  while((input != Button::Back) || (input != Button::Left) || (input != Button::Right)){
    input = wait_until();
    if(input == Button::Enter){
      *tf = !(*tf);

      quality = *tf ? 'Y' : 'N';
      
      sprintf(modstr, "%s %d", optionName, quality); // pass global variable, cant do a pointer
      lcdwrite((const char *)modstr, menuName);
    }
  }
  return input;

}

Button delay_in(uint32_t ms){
  Button input = Button::None;
  uint32_t tim = millis();

  while (millis()-tim < ms){
    delay(20);
    input = checkInput();
    if(input != Button::None){
      return input;
    }
  }

  return Button::None;
}

Button wait_until(){ //waits until a button is pressed
  Button input = Button::None;
  while(1){
    input = checkInput();
    delay(50);
    if(input != Button::None){
      return input;
      }
  }
}

void lcdwrite(const char* message, const char* header){ //dont need the default here default is a cpp feature.
  uint8_t m_len = strlen(message);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print(header);

  lcd.setCursor(0,1);
  lcd.print(message);
  
  delay(500);

}

// void initMenuMode(const char * message, void (*enterBehav)(), void (*leftBehav)(), void (*rightBehav)()){ //unused, keep around for now
//   lcdwrite(message);
//   uint8_t c_in
//   while(c_in == none) c_in = delay_in(5000);

//   switch(c_in){
//     case enter: enterBehav(); break;
//     case left: leftBehav(); break;
//     case right: rightBehav(); break;
//     default: break; 
//   }
// }

//from elegoo smartrobotcar v4
void Servo_move(unsigned int Position_angle, uint8_t pin)
{
  
  myservo.attach(pin);
  myservo.write(Position_angle); //sets the servo position according to the 90（middle）
  delay(500); // could implemt wdt stuff
  myservo.detach();
}

Button checkInput(){
  char rx_info;
  Button dir = Button::None;
  
  // if(digitalRead(LEFT_BTN) == HIGH) dir = left; //you are saved... for now.
  // else if(digitalRead(CENT_BTN) == HIGH) dir = enter;
  // else if(digitalRead(RIGHT_BTN) == HIGH) dir = right;

  if(Serial.available()) {
    rx_info = Serial.read();
    if(rx_info == 'l') dir = Button::Left;
    else if (rx_info == 'e') dir = Button::Enter;
    else if (rx_info == 'r') dir = Button::Right;
    else if (rx_info == 'b') dir = Button::Back;
  }

  uint8_t dirint = static_cast<uint8_t>(dir); //have to do this as enum class is a cpp thing
  //Serial.println("get got");
  Serial.println(dirint);
  return dir;
}
