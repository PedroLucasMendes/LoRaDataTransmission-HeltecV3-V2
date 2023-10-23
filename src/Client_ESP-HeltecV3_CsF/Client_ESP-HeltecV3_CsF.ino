// Incluindo a biblioteca RadioLib
#include <RadioLib.h>

// SX1262 conexões:
// NSS pin:   8
// DIO1 pin:  14
// NRST pin:  12
// BUSY pin:  13
SX1262 radio = new Module(8, 14, 12, 13);

void setup() {
  //Inicializando o Serial na velocidade 115200
  Serial.begin(115200);

  // Inicializando SX1262 com as configurações padrão
  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
  } else {
    while (true);
  }
  //Configurando a frequencia para 915MHz
  if (radio.setFrequency(915.0) == RADIOLIB_ERR_INVALID_FREQUENCY) {
    while (true);
  }
  //Configuração dos parametros
  radio.setCodingRate(8);
  radio.setSpreadingFactor(12);
  radio.setBandwidth(3);

  //Função de envio de pacote
  sendData();
}

void loop() {}

void sendData(){
  
  
  for(int i = 0; i < 51; i++){
    //Inicialização da variavel str com o valor de i
    String str = String(i);
    int state = radio.transmit(str);

    //Caso queira ter um log de envio com sucesso
    if (state == RADIOLIB_ERR_NONE) {
      //Serial.println("Dado Enviado com sucesso");
    }
    else {
      //Serial.println("Erro no envio");
    }

    //Após o envio do dado, ele fica esperando o end-device responder com o mesmo pacote
    String str_read;
    state = radio.receive(str_read);
    if (state == RADIOLIB_ERR_NONE) {
      
      // print do dado recebido
      Serial.print(" "+str_read);
  
      // print do RSSI (Received Signal Strength Indicator)
      Serial.print(F(", "));
      Serial.println(radio.getRSSI());

      //Formato de print - Y,RSSI
    }
    
  }


}
