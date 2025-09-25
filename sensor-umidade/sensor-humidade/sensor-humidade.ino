#include "DHT.h"

// Escolha o tipo de sensor
#define DHTTYPE DHT11   // DHT 11

// Pino do sensor
uint8_t DHTPin = 4; 

// Inicializa o DHT
DHT dht(DHTPin, DHTTYPE);                

float Temperature; 
float Humidity;

void setup() {
  // Inicializa e define a taxa de comunicação serial como 115200 bits por segundos
  Serial.begin(115200);
  delay(100);
  
  // define que o pino 4 será usado para ler dados
  pinMode(DHTPin, INPUT);

  // Inicializa o dht
  dht.begin();              
  Serial.println("Iniciando leitura do DHT...");
}

void loop() {
  // Lê temperatura
  Temperature = dht.readTemperature(); 
  // Lê umidade
  Humidity = dht.readHumidity();      

  // Verifica se o valor não é número e imprime a mensagem
  if (isnan(Temperature) || isnan(Humidity)) {
    Serial.println("Falha ao ler do sensor DHT!");
  } else {
    // Imprime os dados
    Serial.print("Temperatura: ");
    Serial.print(Temperature);
    Serial.println(" °C");

    Serial.print("Umidade: ");
    Serial.print(Humidity);
    Serial.println(" %");
  }

  // Aguarda 2 segundos entre leituras
  delay(2000); 
}
