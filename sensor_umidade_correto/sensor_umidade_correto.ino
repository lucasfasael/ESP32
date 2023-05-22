#include <WiFi.h>
#include <PubSubClient.h>

int umidade;
int Rele = 4;

char convert[20];

const char *ssid = "Malu_2.4G"; 
const char *password = "bionica10"; 


const char *mqtt_broker = "192.168.101.8";
const char *topic = "umidade";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(A10, INPUT);
  pinMode(Rele, OUTPUT);
  //pinMode(10, OUTPUT);
  //digitalWrite(10, LOW);
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  client.setServer(mqtt_broker, mqtt_port);
   client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    Serial.print("Aguardando conexão MQTT...");                          
    if (client.connect("teste")) {                               
      Serial.println("conectado");                                       
    } else {                                                             
      Serial.print("falhou, rc=");                                       
      Serial.print(client.state());                                      
      Serial.println(" tente novamente ");                          
    }
   delay(2000);
   client.publish(topic, convert);
   client.subscribe(topic);
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
      Serial.print((char) payload[i]);
  }
  Serial.println();
  Serial.println("-----------------------");
}

void loop() {
  umidade = map(analogRead(A10),3350,3575,100,0);
    Serial.println("Nível da umidade: ");
    //Serial.println(analogRead(A10));
    Serial.println(umidade);
      if(umidade <= 40){
        Serial.println("Regando a planta !!!");
        digitalWrite(Rele, LOW);
        
      }
      else{
        Serial.println("A planta já está com água !!!");
        digitalWrite(Rele, HIGH);
      }
      itoa(umidade, convert, 10);
      client.publish(topic, convert);
      //Serial.println(itoa(umidade, convert, 4));
  delay(1000);
}
