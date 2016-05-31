//application : TesterSerie
//version : 1.3a
//créé 2013/05/08 - maj 2014/08/24
//Ce programme Arduino permet de tester la communication série.
//Quand il reçoit un chiffre x de 1 à 9 inclus, il fait clignoter x fois la led de test ;
//il transmet des infos en retour et réagit aussi via le module LCD.

//ChangeLog V1.2 à V1.3 :
//constante pour nom et version de l'application
//modifié et renommé fonction Clignoter --> clignoterLed
//commencé à implémenter la gestion des paramètres




const int pinLed = 13;
const String appNom = "TesterSerie V1.3";


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.



void setup()
{
    Serial.begin(9600);
    pinMode(pinLed, OUTPUT);
  

    
    testChaine();
}


void loop() {
    if ( Serial.available()) {
        lcd.clear();
        Serial.print("donnees recues : ");
        char donnees = Serial.read();
        Serial.print(donnees);
        if (isDigit(donnees)) {  
            Serial.println(" ; chiffre.");
            lcd.setBacklight(GREEN);
            lcd.setCursor(0,0);
            lcd.print("valeur valide :");
            lcd.setCursor(0,1);
            lcd.print(donnees);
            int nbClignote = (donnees - '0');
            if (nbClignote > 0) {
                clignoterLed(pinLed, nbClignote, 1000, 500);
            }
        } else {
            Serial.println(" ; autre.");
            lcd.setBacklight(RED);
            lcd.setCursor(0,0);
            lcd.print("valeur invalide");
        }
        delay(500);
        lcd.setBacklight(BLUE);
        lcd.clear();
    }
}


void clignoterLed(int pinLed, int nbClignote, int dureeOn, int dureeOff) {
    for(int cpt=1; cpt<=nbClignote; cpt++) {
        digitalWrite(pinLed, HIGH);
        delay(dureeOn);
        digitalWrite(pinLed, LOW);
        delay(dureeOff);
    }
}


void testChaine() {
    String maChaine = "nombre_0_150";
    int indexSep1, indexSep2;
    String valeur1, valeur2, valeur3;
    indexSep1 = maChaine.indexOf("_");
    indexSep2 = maChaine.indexOf("_", indexSep1 + 1);
    valeur1 = maChaine.substring(0, indexSep1);
    valeur2 = maChaine.substring(indexSep1 + 1, indexSep2);
    valeur3 = maChaine.substring(indexSep2 + 1);
    Serial.println("indexSep1 : " + String(indexSep1));
    Serial.println("indexSep2 : " + String(indexSep2));
    Serial.println("valeur1 : " + valeur1);
    Serial.println("valeur2 : " + valeur2);
    Serial.println("valeur3 : " + valeur3);
}

