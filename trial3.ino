#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include  <ArduinoJson.h>


const char* WIFI_SSID = "Yasmine's iphone";
const char* WIFI_PASSWORD = "123456789";

//CNC Firebase
#define FIREBASE_HOST "cnc-database.firebaseio.com"
#define FIREBASE_AUTH "qfIuyunctYn6RCfqEcVY0NwYbhulmjmj0Qk7OVMe"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int GStatus = Firebase.getInt("Status");
  if(GStatus == 1){
    String GCode = Firebase.getString("GCode");
    Serial.println(GCode);
    Firebase.setInt("Status", 0);
  } else {
    //Do nothing
  }

  //set data:
  //Firebase.set(Status, "1");
}
