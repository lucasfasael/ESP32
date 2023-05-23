#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR   0x3C  // Endereço I2C do display OLED (pode variar)
#define OLED_SDA    16    // Pino SDA (data) do ESP32
#define OLED_SCL    15    // Pino SCL (clock) do ESP32
 
Adafruit_SSD1306 display(128, 64, &Wire, OLED_ADDR);

void setup() {
  // Inicialização da comunicação I2C
  Wire.begin(OLED_SDA, OLED_SCL);
  
  // Inicialização do display OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("Falha ao inicializar o display OLED");
    while (true);
  }

  // Limpa o buffer do display
  display.clearDisplay();
  
  // Configura o tamanho e o estilo do texto
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  // Exemplo de exibição de texto
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Olá, ESP32!");
  display.display();
  
  delay(1000);
}