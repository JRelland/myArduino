/*  MOOC Fabriquer un objet connecté
    Mines-Télécom - Plateforme FUN
    TP2 - La servogirouette.
    
* Solution inspirée des programmes : 
 - WiFiScan.ino (pour le scan des réseaux WiFi)
 - WiFiClient_simple.ino (Connexion en client)
 - WiFiClient-compteur.ino (Connexion au serveur)
 - WiFiTemperature.ino (Retourne la valeur par l'api)
 
 Programme réalisé par José Relland le 24 mai 2016 
 dans le cadre du TP2 - La servogirouette.
 
 Objectif :
 Récupéré la direction du vent 
 sur le site web openweathermap.org
 pour sa/une ville
 Info ici :
 http://openweathermap.org/current

 API model :
 api.openweathermap.org/data/2.5/weather?q={city name},{country code}
 Mot-clé : \"deg\":"

Compte JRelland
 La clé "Défault" : e4bcaff37fdcebe73ea8bda899e655fd

**************************************
    Compilation vérifiée dans IDE Arduino
    mais pas testé sur un ESP8266 :(
**************************************
 
*/

  // Déclaration de l'ESP8266 pour le WiFi
  #include <ESP8266WiFi.h>

  // Déclaration pour le servomoteur
  #include <Servo.h> 

  // Pour la connexion internet de votre système
const char* mySSID = "Votre SSID" ;        // Le mien est WifiJRD !
const char* myPassword = "Mon PassWord" ;   // Confidentiel
      int ssidFlag = 0 ;                   // Mise à zéro flag vérifiant la présence de mon réseau

  // Pour la connexion au serveur distant
const char* myHost = "api.openweathermap.org" ;   // le serveur où aller chercher l'info
const int httpPort = 80 ;
const char* apiKey = "e4bcaff37fdcebe73ea8bda899e655fd" ;  // La clé de mon compte
const char* myTown = "Troyes, fr" ;                        // la ville et le pays

  // Construction de le requête pour questionner le site pour
  // (host)/data/2.5/weather?q={city name},{country code}
String url = String("/data/2.5/weather?q=") + myTown + "&appid=" + apiKey ;   

String myKeyword = String("\"deg\":") ;   // Chaîne caractère dans JSON pour "deg":
bool inBody = false ;      // Gestion de l'en-tête :)

int directionVent ;        // C'est un integer (me semble-t-il :)

  // Pour le pilotage du servomoteur
 Servo myServo ;          // Objet Servo
 const int servoPin = 9 ; // Pilotage du servomoteur


void setup() {
  // Vitesse imposée par l'ESP8266
  Serial.begin(115200) ;              // vitesse imposée par l'ESP8266


void listReseaux()




 // ************************************************************************ 
  // Connection à l'internet
  Serial.print("Connexion au WiFi de ") ;
  Serial.println(mySSID) ;

  WiFi.begin(mySSID, myPassword) ;

  while (WiFi.status() != WL_CONNECTED) {
    delay(500) ;
    Serial.print(".") ;
  }

  Serial.print("") ;
  Serial.println("WiFi Connecté") ;
  Serial.print("Adresse IP du module ESP : ") ;
  Serial.println(WiFi.localIP()) ;                // Affiche l'adresse IP de l'ESP
  Serial.print("Adresse IP de la box : ") ;
  Serial.println(WiFi.gatewayIP()) ;                // Affiche l'adresse IP de la box

 // ************************************************************************

  // Attache le servo
  myServo.attach(servoPin) ; 

}

void loop() {

 // ************************************************************************
  // Interrgation du serveur via la requête API
  
  Serial.print("Connexion au serveur  : ") ;
  Serial.println(myHost) ;

  WiFiClient myClient ;           // Rôle du client par rapport au serveur

  if(!myClient.connect(myHost, httpPort)) {       //Pour se connecter au serveur
    Serial.println("Connexion non réussie") ;
    return ;                    // Je ne connaissais pas !
  }

  myClient.print(String("GET") + url + "HTTP/1.1\r\n" +
                  "Host: " + myHost + "\r\n" +
                  "Connection: close\r\n\r\n") ;

  delay(1000) ; 

    // Ici, l'information venant du serveur est détectée
  while(myClient.available()) 
  {
  String line = myClient.readStringUntil('\r') ;    // Découpe à la ligne avec /r
  Serial.print(line) ; 

    // Ici, la ligne est interprétée pour extraire notre information
  if (line.length() == 1) inBody = true ;         // Ligne vide, le 1 pour le caractère de ligne vide
  if (inBody) 
    {
    int pos = line.indexOf(myKeyword) ;

      if (pos > 0) 
      {
      // indexOf donne la position du début du mot 
      // + sa longueur = pos devient le début du mot suivant
        pos += myKeyword.length() ; 

        Serial.println(&line[pos]) ;

      // Direction du vent, valeur comprise entre 0 et 360°
        directionVent = atof(&line[pos]) ;  
          
      } /*Fin récupération flottant */
    
    } /* Fin de la recherche */ 
  
  } /* Fin de l'écoute des données  */
  
 // ************************************************************************


 // ************************************************************************
  // Pilotage de la girouette !
  // Retirer 179° à la variable "directionVent" (à cause du servomoteur :)

  int commandeGirouette = directionVent - 179 ;   // Pilotage de la girouette

  // print the results to the serial monitor:
  Serial.print("Direction du vent = ");
  Serial.print(directionVent);
  Serial.print("\t Cde servo = ");
  Serial.println(commandeGirouette);

  myServo.write(commandeGirouette) ;      // Pilote la girouette
  delay(15) ;                              // tempo
  
 // ************************************************************************

}  /* Fin de la boucle et du programme :) */
