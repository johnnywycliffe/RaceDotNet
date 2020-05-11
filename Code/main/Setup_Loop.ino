void setup() {
  //Serial Debug init
  Serial.begin(115200);
  
  //Display
  if(!display.init()) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setContrast(255);
  
  // Callbacks
  //esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop(){
  m.runMenu(); //Run menu command
  //Menu should launch everything else. ESP-NOW signals should be on core 0, so it shouldn't block.
}
