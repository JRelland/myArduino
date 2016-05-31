/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)

 Modified by José Relland - 2016, May
 To send words in morse :). 
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

int myDelay = 1000 ;                       // Initialise variable for delay
char myEntry ;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600) ;              // Initialise monitor communication
  
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("") ;
  Serial.println("Entrer 1 à 9 : ") ;

  // Boucle pour le traitement de la valeur de myDelay
  if (Serial.available() > 0) {
    
      myEntry = Serial.read() ;
      Serial.print("Vous avez taper : ") ;
      Serial.println(myDelay) ;
      Serial.println(myDelay, DEC) ;
       
    // Détecter entre la valeur 1 (49 en ASCII) et 9 (57) et mettre à jour myDelai 
    if (myEntry >= 49 && myEntry <= 57 ) {
  
      myDelay = ( myDelay - 48 ) * 1000 ;
  
      Serial.print("Vous avez taper : ") ;
      Serial.println(myDelay, DEC) ;
      }
    else {
  
      Serial.print("Entrée non reconnue, ") ;
      Serial.print(myDelay) ;
      Serial.println(". myDelay à 1000 ms.") ;
    
      myDelay = 1000 ;                  // Delay is 1 s
    }
  }

    digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                      // but actually the LED is on; this is because 
                                      // it is acive low on the ESP-01)
    Serial.print("myDelay : ") ;
    Serial.println(myDelay) ;

    delay(myDelay);                      // Wait for a second
    
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
    
    Serial.print("myDelay : ") ;
    Serial.println(myDelay) ;
    
    delay(myDelay);                      // Wait for two seconds (to demonstrate the active low LED)
}
