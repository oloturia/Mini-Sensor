#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(6,7);

void setup() {
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  Bluetooth.begin(9600);
  pinMode(A0,INPUT);  
}

void loop() {
  if (Bluetooth.available()) {
    Serial.print(Bluetooth.read());
    Serial.print(" ");
    int data_sensor = analogRead(A0);
    Serial.println(data_sensor);
    byte buf[2];
    buf[0] = data_sensor & 255;
    buf[1] = (data_sensor >> 8) & 255;
    Bluetooth.write(buf,sizeof(buf));
  }
}
