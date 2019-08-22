#ifndef ADRESSBUCH_CPP
#define ADRESSBUCH_CPP 

#include <iostream>
#include "Adressbuch.hpp"


using namespace std;

char* input(int minL, const char* output, const char* msg) {
  
  char eingabe[100];
  
  for(int i = 0; i < 100; i++) {
    eingabe[i] = '\0';
  }
  
  int length;
  
  do {
    cout << output;
    cin >> eingabe;
    
    length = 0;
    
    for(int i = 0; i < 100; i++) {
      if(eingabe[i] == '\0') {
        break;
      }
      else {
        length++;
      }
    }
    
    /*
    int length = 0;
    while(eingabe[length] != '\0')
      length++;
    */
    
    if( length < minL ) {
      cout << msg << endl;
      for(int i = 0; i < 100; i++) {
        eingabe[i] = '\0';
      }
    }
      
  } while ( length < minL );
                             
  return eingabe;
}


}

int numberInput(int max, int min, const char* output, const char* msg) {
  
  int zahl = 0;
  
  do {
    cout << output;
    cin >> zahl;
    if((zahl > max)||(zahl <= min) ) {
      cout << msg << endl;
    }
  } while ( (zahl > max) || (zahl <= min) );
                            
  return zahl;
}

Person personInput(){
  Person Eingabe;
  
  cin >> Eingabe.Vorname;
  cin >> Eingabe.Nachname;
  cin >> Eingabe.Telefon;
  cin >> Eingabe.Alter;
  cin >> Eingabe.Groesse;
  cin >> Eingabe.Geschlecht;
  
}

int adressbuch (){

}


#endif