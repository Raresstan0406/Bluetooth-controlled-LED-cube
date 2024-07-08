#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
char recieve;
void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    Serial1.write(SerialBT.read());
  }
  delay(20); 
                       
}
