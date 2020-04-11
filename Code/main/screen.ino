//Drawing functions
void scrprnt(String temp){
  
}

//Draws the menu screen
void drawMenuScreen(String title, String subheader, bool upArrow, bool downArrow) {
  display.clear();
  display.setFont(ArialMT_Plain_24);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawStringMaxWidth(0,0,128,title);
  display.setFont(ArialMT_Plain_24);
  display.drawStringMaxWidth(28,0,128,title);
  //up arrow
  if(upArrow){
    //display.fillTriangle(64,0,60,4,68,4,SSD1306_WHITE);
  }
  //down arrow
  if(downArrow){
    //display.fillTriangle(60,26,64,31,68,26,SSD1306_WHITE);
  }
  display.display();
  delay(5000);
}
