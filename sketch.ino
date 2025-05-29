#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_client_id = "ESP32Monitor_Julia";
const char* mqtt_topic_temp = "mackenzie/iot/temperatura";
const char* mqtt_topic_humidity = "mackenzie/iot/umidade";

#define DHTPIN 4
#define LEDPIN 25
#define DHTTYPE DHT22

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

long lastMsg = 0;
int ledState = LOW;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect(mqtt_client_id)) {
      Serial.println("conectado!");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);

  dht.begin();

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect_mqtt();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
      Serial.println("Falha na leitura do sensor DHT!");
      return;
    }

    if (t > 30.0) {
      digitalWrite(LEDPIN, HIGH);
      Serial.println("Temperatura > 30C. LED LIGADO!");
      ledState = HIGH;
    } else {
      digitalWrite(LEDPIN, LOW);
      Serial.println("Temperatura <= 30C. LED DESLIGADO.");
      ledState = LOW;
    }

    char tempString[8];
    dtostrf(t, 1, 2, tempString);
    Serial.print("Publicando temperatura: ");
    Serial.println(tempString);
    client.publish(mqtt_topic_temp, tempString);

    char humString[8];
    dtostrf(h, 1, 2, humString);
    Serial.print("Publicando umidade: ");
    Serial.println(humString);
    client.publish(mqtt_topic_humidity, humString);
  }
}