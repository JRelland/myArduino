/* Programme Morse 
 *  fichier morse02.h
 *  
 *  Tester les libraiires
 * 
 * José Relland Mai 2016
 * 
 * https://www.arduino.cc/en/Hacking/LibraryTutorial
 */

#ifndef morse02_h
#define morse02_h

#include "Arduino.h"

// Functions
class Morse
{
  public:
    Morse(int ledPin);
    void dot();
    void dash();
  private:
    int _ledPin;
};


#endif // End of the script
