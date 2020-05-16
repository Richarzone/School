#include <iostream>
#include <fstream>
#include <string>
#include "Complejo.h"
using namespace std;

void sumaComplejos(Complejo listaComplejos[], Complejo &resultado)
{
  ifstream fileComplejos;
  int nReal,nImaginario;
  int cantComplejos = 0;
  string line;

  fileComplejos.open("numerosComplejos.txt");

  while(getline(fileComplejos, line))
  {
    cantComplejos++;
  }

  fileComplejos.close();

  fileComplejos.open("numerosComplejos.txt");
  
  int cont = 0;
  for(int i = 0; i < cantComplejos; i++)
  {
    while(fileComplejos >> nReal >> nImaginario)
    {
      listaComplejos[cont].setReal(nReal);
      listaComplejos[cont].setImaginario(nImaginario);
      cont++;
    }
  }
  
  for(int i = 0; i < cantComplejos; i++)
  {
    listaComplejos[i].imprimir();
    cout << endl;
  }

  cantComplejos = cantComplejos - 1;
  resultado = listaComplejos[0];

  for(int i = 0; i < cantComplejos; i++)
  {
    resultado = resultado.suma(listaComplejos[i+1]);
  }
  
  resultado.imprimirResultado();
}

int main()
{
  Complejo listaComplejos[20];
  Complejo resultado = Complejo();
  
  sumaComplejos(listaComplejos, resultado);
  return 0;
}
