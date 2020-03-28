//Drawing functions

//Draws the menu screen
void drawMenuScreen(char title[TEXT_H_LARGE], bool upArrow, bool downArrow) {
  //Title
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,8);
  display.println(title);
  //up arrow
  if(upArrow){
    display.fillTriangle(64,0,60,4,68,4,SSD1306_WHITE);
  }
  //down arrow
  if(downArrow){
    display.fillTriangle(60,26,64,31,68,26,SSD1306_WHITE);
  }
  display.display();
}
