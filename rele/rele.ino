int Rele = 4;

void setup() {
  // put your setup code here, to run once:

pinMode(Rele, OUTPUT);
}

void loop() {
  digitalWrite(Rele, HIGH);
  delay(1000);
  digitalWrite(Rele, LOW);
  delay(1000);
}
