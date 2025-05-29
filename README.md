# Monitoramento Ambiental Inteligente com IoT - Protótipo Simulado (Wokwi)

Este repositório contém a documentação e o software de um protótipo de sistema de **monitoramento ambiental inteligente** baseado em Internet das Coisas (IoT). O projeto é **totalmente desenvolvido e simulado na plataforma online Wokwi**, demonstrando o uso de sensores, atuadores e comunicação MQTT em um ambiente virtual.

## 📝 Descrição do Funcionamento e Uso

Este protótipo realiza a leitura simulada de temperatura e umidade através de um sensor DHT22 conectado a um microcontrolador ESP32. Os dados coletados são enviados para um *broker* MQTT na internet. Um LED atua como alerta visual, acendendo quando a temperatura simulada excede 30°C.

**Para reproduzir:**
1.  Acesse o projeto diretamente no Wokwi: https://wokwi.com/projects/432241999730915329
2.  Clique em "Start Simulation" (Play).
3.  Observe o Monitor Serial para o fluxo de dados e interaja com o sensor DHT22 virtual para acionar o LED.
4.  Para visualizar os dados MQTT, conecte um cliente MQTT (ex: MQTT Explorer) ao `test.mosquitto.org` (porta 1883) e assine os tópicos `mackenzie/iot/temperatura` e `mackenzie/iot/umidade`.

## 💻 Software Desenvolvido (Código-Fonte)

O *firmware* (código-fonte) para o microcontrolador ESP32 virtual está localizado no arquivo `sketch.ino` (ou `main.ino`) neste repositório. Ele foi desenvolvido em C++ utilizando o *framework* Arduino.

* [`sketch.ino`](./sketch.ino) - Código principal do projeto.

## 🛠️ Hardware Utilizado (Virtual)

Este projeto utiliza **componentes virtuais** simulados no Wokwi para prototipagem didática:

* **Plataforma de Desenvolvimento:** ESP32 Devkit C V4 (simulado)
* **Sensor:** DHT22 Temperature/Humidity Sensor (simulado)
* **Atuador:** LED Vermelho (simulado) com Resistor

## 🌐 Interfaces, Protocolos e Módulos de Comunicação

O protótipo emprega os seguintes elementos para comunicação:

* **Módulo de Comunicação:** O próprio ESP32 virtual com sua conectividade Wi-Fi integrada no ambiente Wokwi.
* **Protocolo de Comunicação:** MQTT (Message Queuing Telemetry Transport). Utilizado para a troca de mensagens leve e eficiente entre o ESP32 (publicador) e o *broker* online.
* **Serviço MQTT Broker:** `test.mosquitto.org` (broker público para testes).
* **Tópicos MQTT:** `mackenzie/iot/temperatura` e `mackenzie/iot/umidade` para publicação de dados.
