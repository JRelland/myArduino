/*  Exemple de répartition du programme en plusieurs fichiers
 *   horloge.ino
 *   horloge.h
 *   horloge.cpp
 *   dans le répertoire horloge
 *   => Tout doit porter le même nom !
 * 
 * José Relland Mai 2016
 * 
 * 
 * 
 */
#include "horloge.h"

void setup() {
  Serial.begin(9660) ;
 }

 void loop() {
float varA = 1.5 ;

Serial.print(varA) ;
Serial.print(" * 10 = ") ;

float varB = ajouteDeux(varA) ;

Serial.println(varB) ;
 }




 

