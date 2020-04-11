//Handles drawing menu and getting inputs to make selection
int8_t input(int8_t &sel, int8_t arrLen){
  int8_t in = 0;
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
    return -2;
  }
  else if (bitRead(in,BUTTON2) == 1||bitRead(in,BLEFT) == 1){
    return -1;
  }
}
int8_t notmenu(int8_t selector, MenuItem* arr, int8_t arrLen){
  int8_t output = input(selector,arrLen);
  switch(output){
    case -2: //Selection made
      arr[selector].funcPtr("BLARGH");
      break;
    case -1: //Back button
      
      break;
    default: //Update screen
      String dTitle = arr[selector].title;
      String dSubtitle = arr[selector].subtitle;
      bool upArrow = true;
      bool downArrow = false;
      if (selector = 0){
        upArrow = false;
      }
      if (selector = arrLen){
        downArrow = false;
      }
      drawMenuScreen(dTitle,dSubtitle, upArrow, downArrow);
      break;
  }
  return selector;
}
