
#include <ESP8266WiFi.h>
const char* ssid = "rede_AP";//o esp8266 cria esta rede wifi, não é a rede do roteador local
const char* password = "abcd1234";//senha passa acessar a rede
WiFiServer server(502);
char data[250], dcr[250];//variáveis para armazenar o caracteres da transmissão/recepção
int ind = 0 , icd=0;
WiFiClient client;
void setup() {
Serial.begin(9600);//taxa de transmissão
IPAddress staticIP(192, 168, 4, 2); // IP estático do dispositivo
IPAddress gateway(192, 168, 4, 1);// Endereço gateway 
IPAddress subnet(255, 255, 255, 0);// Máscara de subrede
WiFi.mode(WIFI_AP);// Trabalhando como Access Point
WiFi.softAP(ssid, password, 2, 0);
WiFi.config(staticIP, gateway, subnet);
server.begin();
delay(5000);
Serial.println("Server started");
Serial.println(WiFi.softAPIP());//mostra o IP pela serial - opcional
}
void loop()
{
if(!client.connected()){  //verifica a conexão com um client
client= server.available();
}
else {
//********INICIO DA ROTINA SERIAL - WIFI***********
if(Serial.available()>0){
while(Serial.available()){ //aguarda dados da serial
dcr[icd] = Serial.read();  //armazena em um vetor
icd++;
}
for(int j=0;j<icd;j++){ //laço for para transmitir os dados para o client
client.print(dcr[j]); //transmite dados do vetor para o client
}
}
//********INICIO DA ROTINA WIFI - SERIAL***********
if(client.available()>0){
while(client.available()){ //aguarda dados do client
data[ind] = client.read(); //armazena em um vetor
ind++;
}
client.flush();
for(int j=0;j<ind;j++){ //laço for para transmitir os dados pela serial
Serial.print(data[j]); //transmite dados do vetor para a serial
}
}
icd=0;
ind=0;
}
}
