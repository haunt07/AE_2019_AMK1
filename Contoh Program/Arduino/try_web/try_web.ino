#include <ESP8266WiFi.h>

const char* ssid = "wifi_ssid";
const char* password = "wifi_password";
const char* host = "server_host";

WiFiClient client;
void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(2, OUTPUT);
  digitalWrite(2, 0);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.setTimeout(10);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println("Server started");

  Serial.println(WiFi.localIP());
}

void loop() {
  if(client.connect(host,80)){
    String url = "control/getdata.php";
    client.print("GET /" + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n" + "\r\n");
    delay(100);
    String data;
    while(client.available()){
      data.concat(char(client.read()));
    }
    Serial.print(data);
    Serial.println(data.indexOf("led"));
    if(data.indexOf("led1")>=0){
      digitalWrite(2,0);
    }else if(data.indexOf("led0")>=0){
      digitalWrite(2,1);
    }
  }
  delay(50);
}

