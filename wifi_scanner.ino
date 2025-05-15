#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("WiFi scanner starting...");

  // Set WiFi mode to station so it doesn't try to connect
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  Serial.println("Scanning for WiFi networks...");

  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("No networks found");
  } else {
    Serial.printf("%d networks found:\n", n);
    for (int i = 0; i < n; ++i) {
      Serial.printf("%d: %s, RSSI: %d dBm, Encryption: %s\n", 
        i + 1, 
        WiFi.SSID(i).c_str(), 
        WiFi.RSSI(i), 
        translateEncryptionType(WiFi.encryptionType(i))
      );
    }
  }
  Serial.println("--------------------------------");
  delay(10000); // Wait 10 seconds before next scan
}

const char* translateEncryptionType(wifi_auth_mode_t encryptionType) {
  switch (encryptionType) {
    case WIFI_AUTH_OPEN: return "Open";
    case WIFI_AUTH_WEP: return "WEP";
    case WIFI_AUTH_WPA_PSK: return "WPA-PSK";
    case WIFI_AUTH_WPA2_PSK: return "WPA2-PSK";
    case WIFI_AUTH_WPA_WPA2_PSK: return "WPA/WPA2-PSK";
    case WIFI_AUTH_WPA2_ENTERPRISE: return "WPA2-Enterprise";
    default: return "Unknown";
  }
}
