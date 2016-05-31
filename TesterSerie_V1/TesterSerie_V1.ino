//créé 2013/05/08 - maj 2013/05/08 par truc2geek.wordpress.com
//ce programme Arduino permet de tester la communication série 
//quand il reçoit un chiffre x de 1 à  9 inclus, il fait clignoter x fois la led de test
// Exploitation José Relland - Février 2016 - Troyes Aube Fablab

// Modifs :
// Mise à jour fonction clignoter


const int pinLed = 13;
const String appNom = "TesterSerie_V1";  // Peut-on retourner le nom du programme ???
const int dureeOn = 1000;
const int dureeOff = 500;



void setup()
{
  Serial.begin(9600);  
  pinMode(pinLed, OUTPUT);

}
 
void loop() 
{
  if (Serial.available())
  {
    char donnees = Serial.read();
    if (isDigit(donnees))
    {  
      int nbClignote = (donnees - '0');
      if (nbClignote > 0)
      {
        Clignoter(pinLed, nbClignote, dureeOn, dureeOff);
      }
    }
  }
}


void Clignoter(int pinLed, int nbClignote, int dureeOn, int dureeOff) {
  for(int cpt = 1; cpt <= nbClignote; cpt++) 
  {
      String messageSerial = "Merci d\'attendre : ";        // pour la concaténation !
      
      digitalWrite(pinLed, HIGH);
      messageSerial += dureeOn;
      Serial.println(messageSerial);
      delay(dureeOn);
      
      digitalWrite(pinLed, LOW);
      messageSerial += dureeOff;
      Serial.println(messageSerial);
      delay(dureeOff);
  }

}

  

