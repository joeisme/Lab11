#include <LWiFi.h>
#include "MCS.h"

char _lwifi_ssid[] = "05050422";
char _lwifi_pass[] = "87878787";
MCSDevice mcs("Dd1EPvKG", "nO2fBhPa7bq0GFpj");

MCSDisplayInteger  Temp("Temp");

void setup()
{
  Serial.begin(9600);

  Serial.println("Connect to Wifi");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) {
    Serial.println("Wifi Reconnecting..");
    delay(1000);
  }

  Serial.println("Connect to MCS...");
  while (!mcs.connected()) {
    Serial.println("MCS Reconnecting..");
    mcs.connect();
  }
  Serial.println("MCS Connected!");

  mcs.addChannel(Temp);

}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) {
      Serial.println("MCS Reconnect");
    }
  }
  mcs.process(1000);

  int sensor = analogRead(A0);
  
  Temp.set(sensor);
  Serial.println("Add sensor value.");
  delay(200);
}
