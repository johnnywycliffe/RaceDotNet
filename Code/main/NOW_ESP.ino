//Initialization for ESP NOW
void ConnectionSetup(bool APMode = false){
  int8_t initCnt = 0;
  if (APMode){
    WiFi.mode(WIFI_AP);
    String Prefix = "RDN-";
    String user = WiFi.macAddress(); //TODO: Repace with $USER-#### format once in place
    String SSID = Prefix + user;
    String Password = "123456789"; //TODO: Randomize a password to make thi smode harder to screw with
    bool result = WiFi.softAP(SSID.c_str(), Password.c_str(), CHANNEL, 0);
    if (!result) {
      Serial.println("AP Config failed.");
      return; //Exit setup
    } else {
      Serial.println("AP Config Success. Broadcasting with AP: " + String(SSID));
    }
  } else {
    WiFi.mode(WIFI_STA);
  }
  //Clean up WiFi connection
  WiFi.disconnect();
  while (esp_now_init() != ESP_OK){
    Serial.println("ESPNow Init Failed");
    initCnt++;
    if (initCnt > MAXRETRIES){
      Serial.println("Aborting");
      //Send warning to screen for end user
    }
  }
  //Setup callbacks
  //esp_now_register_send_cb(OnDataSent);
  esp_now_register_recv_cb(OnDataRecv);
  memset(peerList, 0, sizeof(peerList));
  totalPeers = 0;
  Serial.println("ESPNow Init Success");
}

//Deactivate ESP NOW
void ConnectionEnd(){
  esp_now_deinit();
  Serial.println("ESP NOW disabled");
}
/*
// Sent data callback
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print("Last Packet Sent to: "); Serial.println(macStr);
  Serial.print("Last Packet Send Status: "); Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}*/

// Recv data callback
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *newData, int data_len) {
  //DEBUG INFO
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print("Last Packet Recv from: "); Serial.println(macStr);
  Serial.print("Last Packet Recv Data: "); Serial.println(*newData);
  Serial.println("");

  //Handle Data
  memcpy(&incomingData, newData, sizeof(incomingData));
  processMsg();
}

//Discovery mode
void lookForDrivers(){
  int8_t scanResults = WiFi.scanNetworks();
  int8_t currPeer = 0;
  if (scanResults == 0) {
    //No other drivers found
  } else {
    for (int i = 0; i < scanResults; ++i) {
      String SSID = WiFi.SSID(i);
      int32_t RSSI = WiFi.RSSI(i);
      String BSSIDstr = WiFi.BSSIDstr(i);
      if (SSID.indexOf("RDN-") == 0) {//Only grab RDN devices
        if(esp_now_is_peer_exist(peerList[i].peer_addr)){
          continue; //Don't process already connected devices
        }
        //TODO: Check blacklist
        int mac[6];
        if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x",  &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5] ) ) {
          for (int ii = 0; ii < 6; ++ii ) {
            peerList[currPeer].peer_addr[ii] = (uint8_t) mac[ii];
          }
        }
        peerList[currPeer].channel = CHANNEL; // pick a channel
        peerList[currPeer].encrypt = 0; // no encryption
        esp_err_t addStatus = esp_now_add_peer(&peerList[currPeer]);
        if(addStatus != ESP_OK){
          //Peer was not added. Send error message?
        }
        totalPeers++;
        currPeer++;
      }
    }
  }
  WiFi.scanDelete();
}
