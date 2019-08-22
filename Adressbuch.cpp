#ifndef ADRESSBUCH_CPP
#define ADRESSBUCH_CPP 

#include <iostream>
#include "Adressbuch.hpp"


using namespace std;

int strlen(char* str, int arrlen){
  
  int length = 0;
  
  for(int i = 0; i < arrlen; i++) {
    if(*(str + i) == '\0') {
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
  
  return length;
}

void clearString(char* str, int length){
  for(int i = 0; i < length; i++) {
    *(str + i) = '\0';
  }
}

char* input(int minL, const char* output, const char* msg) {
  
  char eingabe[100];
  
  clearString(eingabe, 100);  
  
  do {
    cout << output;
    cin >> eingabe;
    
    if( strlen(eingabe) < minL ) {
      cout << msg << endl;
      clearString(eingabe, 100);
    }
      
  } while ( strlen(eingabe) < minL );
                             
  return eingabe;
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