//créé 2013/05/08 - maj 2013/05/08 par truc2geek.wordpress.com
//ce programme Arduino permet de tester la communication sÃ©rie 
//quand il reÃ§oit un chiffre x de 1 Ã  9 inclus, il fait clignoter x fois la led de test
// Exploitation José Relland - Février 2016 - Troyes Aube Fablab

const int pinLed = 13;

void setup()
{
  Serial.begin(9600);  
  pinMode(pinLed, OUTPUT);
}


void loop()
{
  if ( Serial.available())
  {
    char donnees = Serial.read();
    if (isDigit(donnees))
    {  
      int nbClignote = (donnees - '0');
      if (nbClignote > 0)
      {
        Clignoter(nbClignote);
      }
    }
  }
}


void Clignoter(int nbClignote)
{
  for(int cpt = 1; cpt <= nbClignote; cpt++) 
  {
      digitalWrite(pinLed, HIGH);
      delay(1000);
      digitalWrite(pinLed, LOW);
      delay(500);
  }
}
