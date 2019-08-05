void setup() {
  Serial.begin(115200);
  digitalWrite(10,HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
}

void loop() {
  if( digitalRead(10) == LOW )
  {
    Serial.print("t4.txt=\"44\"");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    delay(1000);
  }
}
