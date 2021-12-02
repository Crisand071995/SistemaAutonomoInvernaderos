const int QRD1114_PIN = A0; // Sensor output voltage

void setup() 
{
  Serial.begin(9600);
  pinMode(QRD1114_PIN, INPUT);
}

void loop() 
{
  // Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  Serial.println(proximityV);
  if (proximityV>0.05) {
    digitalWrite(6,1);
  delay(100);
  }
  else digitalWrite(6,0);
  delay(100);
}
