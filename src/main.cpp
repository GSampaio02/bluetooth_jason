// #include <Arduino.h>
// #include <ArduinoJson.h>

// // String mensagem = "ESP32 - STRING E JSON";
// // String mensagemAlterada;

// void setup() {
//   Serial.begin(115200);

//   // Serial.println("Digite uma mensagem: ");


//   //Cria o objeto JSON
//   JsonDocument doc;

//   //Adiciona os dados ao objeto
//   doc["Temp"] = 25.5;
//   doc["Umi"] = 60;
//   doc["sensor"] = "DHT22";


//   //Manda para serial
//   serializeJsonPretty(doc, Serial);

//   //Acesso os valores do json
//   float temperatura = doc["Temp"];
//   float umidade = doc["Umi"];
//   String sensor = doc["Sensor"];


//   //Exibe os dados
//   Serial.println(temperatura);
// }

// void loop() {
//   // if(Serial.available()){
//   //   mensagem = Serial.readStringUntil('\n');
//   // }

//   // Serial.println(mensagem);
//   // mensagemAlterada = "Mensagem Recebida: " + mensagem + "!";

//   // Serial.println(mensagemAlterada);
//   // Serial.println(mensagemAlterada.length());

//   // String parte = mensagemAlterada.substring(19, 24);
//   // Serial.println(parte);

//   // String msg = "Temp: 25.5";

//   // if(msg.startsWith("Temp")){
//   //   Serial.println("Temperatura recebida");
//   // }


// //   Json - JavaScript Object Notation
// // {
// //   "Temperatura" : 25.5,
// //   "Umidade:": 50,
// //   "Chovendo": true,
// //   "ceu": "nublado"

// // }

//   //delay(3000);



// }

//Código de quem manda


#include<Arduino.h>


BluetoothSerial BT;
uint8_t adress[6] = {0xF4,0x65,0x0B,0x56,0x51,0x5A};

JsonDocument doc;

#define DHTPIN 15
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

bool i = true;

float tempera;
float umida;

float umiAn;
float tempAn;

void setup(){
  Serial.begin(115200);
  dht.begin();

  //Inicia o Bluetooth

  if(BT.begin("Bluetooth", true)){
    Serial.println("Bluetooth iniciado com sucesso");
  }
  else{
    Serial.println("Erro ao iniciar o bluetooth");
  }

  if(BT.connect(adress)){
    Serial.println("Conectado com Sucesso");
  }
  else{
    Serial.println("Erro ao conectar");
  }

}

void loop(){
  String mensagem;
  
  tempera = dht.readTemperature();
  umida = dht.readHumidity();

  Serial.println(tempera);
  Serial.println(umida);
  delay(2000);

  // doc["temp"] = tempera;
  // doc["umi"] = umida;

  // serializeJson(doc, mensagem);

  // if(i){
  //   BT.println(mensagem);
  //   Serial.println(mensagem);
  //   i = false;
  // }
  
  // if(tempera != tempAn || umida != umiAn){
  //   BT.println(mensagem);
  //   Serial.println(mensagem);
  // }

  //  tempAn = tempera;
  //   umiAn = umida;
}








//Quem recebe os dados

//Recebeu os dados do Bluetooth

// JsonDocument doc;
// String mensagem;
// DeserializationError erro = deserializeJson(doc,mensagem);

// if (erro) {
//   Serial.println("Erro ao interpletar o JSON");
// }

// float temperatura = doc["Temp"];