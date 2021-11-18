/*
 * 
hx711 pins
DOUT - 3
CLK - 2

*/

#include "HX711.h"
#define calibration_factor -380000 // เอาค่าที่ได้จากการปรับ มาใส่ตรงนี้
#define DOUT  A3
#define CLK  A2
HX711 scale(DOUT, CLK);

#define weight_setpoint 4 //set weight 4kg


void setup() {
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  Serial.println("Calibrating...");
  scale.set_scale(calibration_factor); // ปรับค่า calibration factor
  scale.tare(); //รีเซตน้ำหนักเป็น 0
  Serial.println("OK Start :");
}
void loop() {
  Serial.print("Reading: ");
  float weight = scale.get_units();
  Serial.print(weight, 2); //แสดงผลน้ำหนัก 2 ตำแหน่ง
  Serial.println(" kg");
  if(weight_setpoint >= 0.3){
    Serial.println("-- Overweight !! --");
    digitalWrite(7, HIGH);
  }
  else{
    Serial.println("-- Weight OK --");
    digitalWrite(7, LOW);
  }
  delay(100);
}
