#include <WiFiManager.h>

#define RESET_PIN 0          // BOOT button
WiFiManager wm;

void setup() {
  Serial.begin(115200);
  pinMode(RESET_PIN, INPUT_PULLUP);


  wm.setConfigPortalTimeout(180);          // restart after 3 min if setup isn't completed
  bool ok = wm.autoConnect("BCA188-ESP32-07");

  if (!ok) {
    Serial.println("Setup timed out, restarting...");
    ESP.restart();
  }
  Serial.println("Connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Debug: show BOOT pin state twice a second (1 = not pressed, 0 = pressed)
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) {
    lastPrint = millis();
    Serial.print("BOOT pin: ");
    Serial.println(digitalRead(RESET_PIN));
  }

  // Hold BOOT for 3 seconds to erase saved Wi-Fi and restart
  static unsigned long pressStart = 0;
  if (digitalRead(RESET_PIN) == LOW) {
    if (pressStart == 0) pressStart = millis();
    if (millis() - pressStart > 3000) {
      Serial.println("Resetting Wi-Fi settings...");
      delay(200);
      wm.resetSettings();
      ESP.restart();
    }
  } else {
    pressStart = 0;
  }
}