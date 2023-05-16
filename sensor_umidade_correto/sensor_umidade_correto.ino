int umidade;
int Rele = 4;
void setup() {
  pinMode(A9, INPUT);
  pinMode(Rele, OUTPUT);
  //pinMode(10, OUTPUT);
  //digitalWrite(10, LOW);
  Serial.begin(9600);
}

void loop() {
  umidade = map(analogRead(A9),17,1850,100,0);
    Serial.println("Nível da umidade: ");
    Serial.println(umidade);
    //Serial.println(umidade);
      if(umidade <= 40){
        Serial.println("Regando a planta !!!");
        digitalWrite(Rele, LOW);
        
      }
      else{
        Serial.println("A planta já está com água !!!");
        digitalWrite(Rele, HIGH);
      }
  delay(1000);
}
