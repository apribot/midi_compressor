boolean byteReady; 
unsigned char midiByte;

void setup() {
    Serial.begin(31250);
    byteReady = false;
    midiByte = 0;  
}

void loop() {
   if (byteReady) {
        byteReady = false;
        Serial.write(midiByte);
    }
}

void serialEvent() {
  if (Serial.available()) {
    midiByte = (unsigned char)Serial.read();
    byteReady = true;
  }
}
