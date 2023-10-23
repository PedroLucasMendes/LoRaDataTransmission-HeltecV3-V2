// Incluindo a biblioteca RadioLib
#include <RadioLib.h>

// SX1276 conexões:
// NSS pin:   18
// DIO1 pin:  26
// NRST pin:  14
// BUSY pin:  35
SX1276 radio = new Module(18, 26, 14, 35);

void setup() {
  //Inicializando o Serial na velocidade 115200
  Serial.begin(115200);

  // Inicializando SX1276 com as configurações padrão
  Serial.print(F("[SX1276] Initializing ... "));
  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
  //Configurando a frequencia para 915MHz
  if (radio.setFrequency(915.0) == RADIOLIB_ERR_INVALID_FREQUENCY) {
    Serial.println(F("Selected frequency is invalid for this module!"));
    while (true);
  }
  //Configuração dos parametros
  radio.setCodingRate(8);
  radio.setSpreadingFactor(12);
  radio.setBandwidth(3);

}

void loop() {
  // Inicializando o ESP32 para receber informações
  String str;
  int state = radio.receive(str);

  if (state == RADIOLIB_ERR_NONE) {
    // Pacote recebido com sucesso
    Serial.println(F("[SX1276] Received packet!"));

    // print do pacote 
    Serial.print(F("[SX1276] Data:\t\t"));
    Serial.println(str);

    // print do RSSI (Received Signal Strength Indicator)
    Serial.print(F("[SX1276] RSSI:\t\t"));
    Serial.print(radio.getRSSI());
    Serial.println(F(" dBm"));

    // print do SNR (Signal-to-Noise Ratio)
    Serial.print(F("[SX1276] SNR:\t\t"));
    Serial.print(radio.getSNR());
    Serial.println(F(" dB"));

    //Após o ESP32 receber uma mensagem ele manda a mesma mensagem confirmando que ele a recebeu
    String str_trans = str;
    int state = radio.transmit(str_trans);

  }

  
  
}
