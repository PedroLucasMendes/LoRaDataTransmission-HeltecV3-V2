# Experimento de Transmissão de Dados LoRa com Heltec V3 e Heltec V2

Este repositório contém o código e a documentação relacionados ao experimento de transmissão de dados utilizando a tecnologia LoRa com os módulos Heltec V3 e Heltec V2. O experimento tem como objetivo caracterizar a transmissão de dados em diferentes cenários, incluindo distâncias variadas e obstáculos simulados, como um bloco de sala de aula.

## Material Utilizado

- Raspberry Pi 4 Model
- 1 módulo ESP32 Heltec V2 equipado com o transceptor LoRa SX1276
- 1 módulo ESP32 Heltec V3 equipado com o transceptor LoRa SX1264
- 1 PowerBank para fornecimento de energia
- 1 script em Python para a aquisição de dados recebidos pela porta serial
- 2 scripts em C++ para a transmissão de dados via LoRa.
- Biblioteca RadioLib

## Estrutura do Repositório

- `src/`: Contém os scripts em C++ para a transmissão de dados com os módulos Heltec V3 e Heltec V2.
- `python_script/`: Inclui o script em Python para a aquisição de dados recebidos pela porta serial.
- `img/`: Pode conter documentação adicional, diagramas e imagens relacionadas ao experimento.

## Executando o Experimento


1. Certifique-se de ter o módulo Heltec V2 corretamente configurado e conectado ao PowerBank.
2. Certifique-se de ter o módulo Heltec V3 corretamente configurado e conectado ao Raspberry Pi.
3. Execute o script em Python no Raspberry Pi logo após conectar o Heltec V3 no mesmo, para aquisição e análise dos dados recebidos.

![Diagrama da transmissão](https://raw.githubusercontent.com/PedroLucasMendes/LoRaDataTransmission-HeltecV3-V2/main/img/Transmiss%C3%A3oLoRa.png)

## Contribuições

Contribuições e melhorias são bem-vindas. Sinta-se à vontade para abrir problemas (issues) e enviar pull requests para este repositório.


