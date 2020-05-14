#include <iostream>
#include <fstream>
#include "Fraccion.h"
using namespace std;

void Fracciones(Fraccion listaDeFracciones[], Fraccion &f1, Fraccion &f2)
{
  ifstream fileFracciones;
  int tipoDeOperacion, numerador1, denominador1, numerador2, denominador2;

  fileFracciones.open("operaciones.txt");

  int cont = 0;
  while(fileFracciones >> tipoDeOperacion >> numerador1 >> denominador1 >> numerador2 >> denominador2)
  {
    f1.setNumerador(numerador1);
    f1.setDenominador(denominador1);
    f2.setNumerador(numerador2);
    f2.setDenominador(denominador2);
  
    switch(tipoDeOperacion)
    {
      case 1:
        listaDeFracciones[cont] = f1.suma(f2);
        cout << listaDeFracciones[cont].getNumerador() << "/" << listaDeFracciones[cont].getDenominador() << endl;
        break;
      case 2:
        listaDeFracciones[cont] = f1.multiplicacion(f2);
        cout << listaDeFracciones[cont].getNumerador() << "/" << listaDeFracciones[cont].getDenominador();
        break;
    }
    cont++;
  }  
}

int main()
{
  Fraccion listaDeFracciones[20];
  Fraccion f1, f2;
  
  Fracciones(listaDeFracciones, f1, f2);

  return 0;
}