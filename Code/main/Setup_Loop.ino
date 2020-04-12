void setup() {
  Serial.begin(115200);
  if(!display.init()) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setContrast(255);
}

void loop(){
  m.runMenu(); //Run menu command
  //Menu should launch everything else. ESP-NOW signals should be on core 0, so it shouldn't block.
}
