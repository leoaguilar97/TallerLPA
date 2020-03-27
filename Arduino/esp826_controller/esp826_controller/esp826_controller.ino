#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

//CONFIGURACION DE LA RED
const char *ssid = "Leo"; // NOMBRE DE LA RED A CONECTARNOS
const char *password = "tallerlpa"; //CONTRASE;A DE LA RED

//setup del modulo esp_826
void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_OFF);
  delay(100);

  //PRENDEMOS EL MODULO
  WiFi.mode(WIFI_STA);
  //Conectarnos a la red
  WiFi.begin(ssid, password);
  //
  Serial.print("Conectando a internet");

  //SALE DE ACA CUANDO ESTE CONECTADO A LA RED (NO IMPORTA SI HAY INTERNET)
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");

  Serial.println("Conectado exitosamente a " + String(ssid));
  Serial.println("----------");
}

//realizar una peticion HTTP y retornar el valor que agrego en string
String GET_HTTP(String host, String link) {
  Serial.println(String("Iniciando peticion HTTP a ") + host + link);

  //si el modulo esta conectado a internet
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(String("Realizando peticion HTTP: ") + link);
    HTTPClient http;

    //realizar la peticion http
    http.begin(host + link);

    //variable que obtiene el codigo http retornado
    int httpCode = http.GET();

    //variable para guardar el resultado
    String result = "";

    //Si el codigo es mayor, el servicio de internet retornó algo
    if (httpCode > 0) {
      //concatenar el valor que se regreso en la peticion http
      result += http.getString();
    }

    //cerrar la conexion http
    http.end();

    return result;
  }

  return "";
}

// Funcion loop que se ejecuta cada vez que se termina un ciclo del programa
void loop() {
  //prueba 1, a google (HOST, LINK)

  if (Serial.available() > 0) {
    String url = Serial.readString();

    String resultado = GET_HTTP(url, "");

    Serial.println("Peticion a url: " + url);
    Serial.println(resultado);

    //esperar 10 segundos hasta la proxima peticion
    delay(10000);
  }

}
