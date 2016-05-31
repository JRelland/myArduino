#include <ESP8266WiFi.h>

// valeurs pour le WiFi
const char* ssid     = "wifi";
const char* password = "toto";

// valeurs pour le serveur Web
const char* host     = "api.openweathermap.org";
const char* apikey   = "your API key";
const char* town     = "Rennes,fr"; 

String keyword = String("\"temp\":"); //chaÃ®ne que l'on recherche dans le JSON
void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.print("Connexion au WiFi ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);    // On se connecte
  
  while (WiFi.status() != WL_CONNECTED) { // On attend
    delay(500);
    Serial.print(".");
  }

  Serial.println("");  // on affiche les paramÃ¨tres 
  Serial.println("WiFi connectÃ©");  
  Serial.print("Adresse IP du module EPC: ");  
  Serial.println(WiFi.localIP());
  Serial.print("Adresse IP de la box : ");
  Serial.println(WiFi.gatewayIP());
}


// drapeau indiquant pendant l'analyse de la rÃ©ponse du serveur
// si on est dans l'en-tÃªte HTTP (false) ou dans le contenu de 
// la ressource.
bool inBody = false;


void loop() {
  float temperature = 0; /* lue du fichier JSON reÃ§u */

  Serial.print("Connexion au serveur : ");
  Serial.println(host);
  
  // On se place dans le rÃ´le du  client en utilisant WifiClient
  WiFiClient client;

  // le serveur Web attend tradionnellement sur le port 80
  const int httpPort = 80;

  // Si la connexio Ã©choue ca sera pour la prochaine fois
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  
  // La connexion a rÃ©ussie on forme le chemin 
  // URL  complexe composÃ© du chemin et de deux 
  // questions contenant le nom de ville et l'API key
  
  String url = String("/data/2.5/weather?q=") + town + "&appid=" + apikey;
  
  Serial.print("demande URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  // On attend 1 seconde
  delay(10000);
  
  inBody = false; // on est dans l'en-tÃªte
  
  // On lit les donnÃ©es reÃ§ues, s'il y en a
  while(client.available()){
    String line = client.readStringUntil('\r');
        
    if (line.length() == 1) inBody = true; /* passer l'en-tÃªte jusqu'Ã  une ligne vide */
    if (inBody) {  // ligne du corps du message, on cherche le mot clÃ©
       int pos = line.indexOf(keyword);

      if (pos > 0) { /* mot clÃƒÂ© trouvÃƒÂ© */
       // indexOf donne la position du dÃ©but du mot clÃ©, en ajoutant sa longueur
       // on se place Ã  la fin.
       pos += keyword.length(); 

       Serial.println (&line[pos]);

       temperature = atof(&line[pos]); 

     } /* fin rÃ©cupÃ©ration du flotant */
    } /* fin de la recherche du mot clÃ© */
  } /* fin data avalaible */
  
  Serial.println();Serial.print ("Temperature = "); Serial.println(temperature-273.15); // temp en Kelvin

  Serial.println("connexion fermÃ©e");

  delay(120000); // 2 minutes
}
