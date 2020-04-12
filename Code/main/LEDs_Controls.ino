//Input and LEDS

//Gets input from buttons
int8_t getInput6Button(){
  uint8_t output = 0;
  //Check buttons
  if (button1.uniquePress()){
    bitSet(output, BUTTON1);
  }
  if (button2.uniquePress()){
    bitSet(output, BUTTON2);
  }
  if (buttonUp.uniquePress()){
    bitSet(output, BUP);
  }
  if (buttonDown.uniquePress()){
    bitSet(output, BDOWN);
  }
  if (buttonLeft.uniquePress()){
    bitSet(output, BLEFT);
  }
  if (buttonRight.uniquePress()){
    bitSet(output, BRIGHT);
  }
  return output;
}

//Gets input from buttons + joystick
/*
int8_t getInputJoystick(){
  int8_t output = 0;
  //Check buttons
  if (digitalRead(BUTTON1_PIN)==HIGH){
    output = output|FLAG_BUTTON1;
  }
  if (digitalRead(BUTTON2_PIN)==HIGH){
    output = output|FLAG_BUTTON2;
  }
  //Check joystick
  int16_t axis = analogRead(UD_PIN);
  if (axis < DEADZONE_LO){
    output = output|FLAG_DOWN;
  } else if (axis > DEADZONE_HI) {
    output = output|FLAG_UP;
  }
  axis = analogRead(LR_PIN);
  if (axis < DEADZONE_LO){
    output = output|FLAG_LEFT;
  } else if (axis > DEADZONE_HI) {
    output = output|FLAG_RIGHT;
  }
  return output;
}
*/

//Handles drawing menu and getting inputs to make selection
int8_t input(int8_t &sel, int8_t arrLen){
  int8_t in = 0;
  //DEMO
  sel++;
  if (sel>=arrLen){
    sel=0;
  }
  return sel;
  //END DEMO
  while(in == 0){in = getInput6Button();} //Wait for input
  if (bitRead(in,BUP) == 1){
    sel--;
    if (sel < 0){
      sel = 0;
    }
    return sel;
  }
  else if (bitRead(in,BDOWN) == 1){
    sel++;
    if (sel >= (arrLen)){
      sel = (arrLen);
    }
    return sel;
  }
  else if (bitRead(in,BUTTON1) == 1 || bitRead(in,BRIGHT) == 1){
    return SELECT;
  }
  else if (bitRead(in,BUTTON2) == 1||bitRead(in,BLEFT) == 1){
    return BACK;
  }
}
