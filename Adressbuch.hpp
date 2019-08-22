#ifndef ADRESSBUCH_HPP
#define ADRESSBUCH_HPP 

#include <iostream>

using namespace std;

struct Person {
  char* Vorname;
  char* Nachname;
  char* Telefon;
  int Alter;
  double Groesse;
  bool Geschlecht;
}; 

Person personInput();

int strlen(char* str, int arrlen = 100);

char* input (
             int minL = 3,
             const char* output = "Input: ",
             const char* msg = "Eingabe ungueltig"
            );

int numberInput(
                int max = 100,
                int min = 1,
                const char* output = "Input: ",
                const char* msg = "Eingabe ungueltig"
               );

int adressbuch ();


#endif