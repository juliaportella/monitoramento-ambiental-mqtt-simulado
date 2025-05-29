## Monitoramento Ambiental Inteligente com IoT - Protótipo Simulado (Wokwi)

Este repositório contém o código e a documentação de um protótipo de sistema de **monitoramento ambiental inteligente** baseado em Internet das Coisas (IoT).

O projeto é **totalmente desenvolvido e simulado na plataforma online Wokwi**, utilizando um microcontrolador **ESP32 virtual**, um **sensor de temperatura e umidade DHT22 simulado**, e um **LED virtual** como atuador.

A comunicação dos dados de temperatura e umidade é realizada via protocolo **MQTT**, enviando as leituras para o *broker* público `test.mosquitto.org`. O sistema também demonstra o acionamento do LED virtual quando a temperatura simulada excede um limite pré-definido.

## 🚀 Funcionalidades

* Coleta de dados de temperatura e umidade (simulados).
* Publicação de dados via MQTT.
* Acionamento de atuador (LED) com base em condição do sensor.
* Comunicação Wi-Fi (simulada).
* **Totalmente simulado em ambiente online (Wokwi).**

## 🛠️ Tecnologias Utilizadas

* **Simulador:** Wokwi
* **Microcontrolador:** ESP32 (virtual)
* **Sensor:** DHT22 (simulado)
* **Atuador:** LED (simulado)
* **Protocolo de Comunicação:** MQTT
* **Linguagem:** C++ (Framework Arduino)
* **Broker MQTT:** `test.mosquitto.org`

## ▶️ Como Rodar a Simulação

1.  Acesse o projeto diretamente no Wokwi através deste link: [**INSERIR SEU LINK DIRETO DO PROJETO NO WOKWI AQUI**]
2.  Clique no botão "Start Simulation" (Play).
3.  Observe a saída no Monitor Serial e interaja com o sensor DHT22 virtual para ver o LED acender/apagar.
4.  Para verificar os dados MQTT, conecte um cliente MQTT (ex: MQTT Explorer) ao `test.mosquitto.org` na porta 1883 e assine os tópicos `mackenzie/iot/temperatura` e `mackenzie/iot/umidade`.
