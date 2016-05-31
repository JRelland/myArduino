/* Fichier cpp de 
 *  eGirouette
 *  
 *  José Relland - mai 2016
 *  
 *  Test pour les requêtes Web 
 *  dans fichiers séparés
 *  
 *    
 */

#include "ServoGirouette.h"

/* Détail de la fonction
float ajouteDeux(float nombreRecu)
{
    float valeur(nombreRecu * 10);
    return valeur;
}

*/


void void listReseaux() {
  

// ************************************************************************
  // Pour vérifier si votre WiFi est là (uniquement au lancement)
  // Liste dans moniteur série
  
    Serial.println("Recherche des réseaux WiFi") ;
      
    WiFi.mode(WIFI_STA) ;               // En client
    WiFi.disconnect() ;                 // Pour ne pas être en point d'accès
    delay(100) ;
  
    int n = WiFi.scanNetworks();         // Compte les réseaux WiFi
    
    if (n==0) 
    {
      Serial.println("Aucun réseau trouvé") ;     // Il n'y a pas de réseau dans le secteur :(  
    }
    else 
    {
      Serial.print(n) ; 
      Serial.print(" réseaux trouvés") ;
  
      for (int i = 0; i<n; ++i) 
      {
        Serial.print(i + 1) ;
        Serial.print(" : ") ; 
        Serial.print(WiFi.SSID(i)) ;            // Relève le nom du réseau WiFi
        if (WiFi.SSID(i) == mySSID) {
          ssidFlag = 1 ;                      // Flag pour présence de mon réseau :)
        }
        Serial.print(" (") ;
        Serial.print(WiFi.RSSI(i)) ;            // Relève la puissance
        Serial.print(") ") ;
        Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*") ;
        delay(10) ;
      }
    }
  
    // On peut imaginer un programme vérifiant son SSID :)
    if (ssidFlag == 1) {
      Serial.println("Mon réseau est présent :)") ;
    }
    else {
      Serial.println("Mon réseau n'a pas été trouvé ! :( ") ;
    }
    Serial.println("Fin de la lecture des réseaux Wifi") ;
   // ************************************************************************

 }
