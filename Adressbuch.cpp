#ifndef ADRESSBUCH_CPP
#define ADRESSBUCH_CPP 

#include <iostream>
#include <fstream>
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
  
  char* eingabe = (char*)malloc(100 * sizeof(char));
  
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

float floatInput(float max, float min, const char* output, const char* msg) {
  
  float zahl = 0;
  
  do {
    cout << output;
    cin >> zahl;
    if((zahl > max)||(zahl <= min) ) {
      cout << msg << endl;
    }
  } while ( (zahl > max) || (zahl <= min) );
  
  return zahl;
}

char charInput(const char* allowed, int allowedL, const char* output, const char* msg) {

  char c;
  bool isOk;
  
  do {
    cout << output;
    cin >> c;
    
    isOk = false;
    for(int i = 0; i < allowedL; i++) {
      if( c == *(allowed + i)) { // allowed[i]
        isOk = true;
        break;
      }
    }
    if(!isOk) {
      cout << msg << endl;
    }
    
  } while(!isOk);

  return c;
}

bool geschlechtInput() {
  char g = charInput("wWmM", 4, "Geschlecht (W/M): ", "Bitte W oder M eingeben.");
  return ((g == 'm') || (g == 'M'));
}

Person personInput(){
  Person Eingabe;
  
  Eingabe.Vorname = input(3, "Vorname: ","Bitte mindestens 3 Zeichen eingeben." );
  Eingabe.Nachname = input(3, "Nachname: ", "Bitte mindestens 3 Zeichen eigeben.");
  Eingabe.Telefon = input(5, "Telefon: ", "Bitte mindestens 5 Nummern eingeben.");
  
  Eingabe.Alter = numberInput(130, 1, "Alter: ", "Bitte richtigen Alter eingeben.");
  Eingabe.Groesse = floatInput(3.50, 0.50, "Groesse: ", "Bitte richtige Grosse eingeben.");
  Eingabe.Geschlecht = geschlechtInput();
  
  return Eingabe;
}

void personOutput(Person pers) {
  cout << "Vorname: " << pers.Vorname << endl;
  cout << "Nachname: " << pers.Nachname << endl;
  cout << "Telefon: " << pers.Telefon << endl;
  cout << "Alter: " << pers.Alter<< " Jahre" << endl;
  cout << "Größe: " << pers.Groesse << "m" << endl;
  
  // Möglichkeit 1
  /*
  if(pers.Geschlecht) {
    cout << "Geschlecht: männlich" << endl;
  } else {
    cout << "Geschlecht: weiblich" << endl;
  }
  */
  
  // Möglichkeit 2
  cout << "Geschlecht: ";
  if(pers.Geschlecht) {
    cout << "männlich";
  } else {
    cout << "weiblich";
  }  
  cout << endl;
  
  // Möglichkeit 3
  //cout << "Geschlecht: " << (pers.Geschlecht)?"männlich":"weiblich" << endl;
}

void personSave(Person pers, fstream* save) {
  *save << pers.Vorname << ',';
  *save << pers.Nachname << ',';
  *save << pers.Telefon << ',';
  *save << pers.Alter << ',';
  *save << pers.Groesse << ',';
  *save << pers.Geschlecht << endl;
}



int main() {
  int anzahl = numberInput(100, 0, "Personen Anzahl: ", "Bitte min 1 Person oder max 100 Personen eingeben.");
  Person Adressbuch[anzahl];
  for(int i = 0; i < anzahl; i++) {
    cout << endl << "Person (" << (i+1) << "):" << endl;
    Adressbuch[i] = personInput();
  }
  cout << "---------------------------------" << endl;
  for(int i = 0; i < anzahl; i++) {
    cout << endl;
    personOutput(Adressbuch[i]);
  }
  cout << "---------------------------------" << endl;
  
  fstream tuer;
  tuer.open("Adressbuch.txt", fstream::out);
  tuer << "Vorname,Nachname,Telefon,Alter,Größe,Geschlecht" << endl;
  for(int i = 0; i < anzahl; i++) {
    personSave(Adressbuch[i], &tuer);
  }
  tuer.close();
  
  cout << "Alle Gespeichert <3 !!" << endl;
}


#endif