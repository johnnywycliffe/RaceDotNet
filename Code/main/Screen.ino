//Drawing functions
void scrprnt(String temp){
  
}

//Draws the menu screen
void drawMenuScreen(String title, String subtitle, bool upArrow, bool downArrow) {
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawStringMaxWidth(0,12,128,title);
  display.setFont(ArialMT_Plain_10);
  display.drawStringMaxWidth(0,28,128,subtitle);
  //up arrow
  if(upArrow){
    display.drawFastImage(60,0,8,8,upArrowBitmap);
  }
  //down arrow
  if(downArrow){
    display.drawFastImage(60,56,8,8,downArrowBitmap);
  }
  display.display();
}
