#define pinSensorA 14
#define pinSensorD 1

void setup() {
  pinMode(pinSensorA, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(pinSensorA)); 
 Serial.print("Digital:"); 
  if (digitalRead(pinSensorD)) {
     Serial.print("SEM UMIDADE ");
  } else {
     Serial.print("COM UMIDADE ");
  }

  Serial.print("  Analogico:");
  Serial.print(analogRead(pinSensorA)); 
  Serial.print("  ");

  Serial.print("  Atuador:");
  if (analogRead(pinSensorA) > 3200) {
     Serial.println("SOLENOIDE LIGADO");
     //digitalWrite(pinSolenoide, HIGH);
  } else {
    Serial.println("SOLENOIDE DESLIGADO");
     //digitalWrite(pinSolenoide, LOW);
  }
}
