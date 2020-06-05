#ifndef Serie_h
#define Serie_h

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "Capitulo.h"

class Serie
{
  public:
    Serie();
    Serie(string name, string gen, vector<Capitulo*> chList);
    void setNombre(string name) {nombre = name;}
    void setGenero(string gen) {genero = gen;}
    void setCapitulos(vector<Capitulo*> chList) {listaCapitulos = chList;}
    string getNombre() {return nombre;}
    string getGenero() {return genero;}
    void getListaCapitulos();
    void mostrar();
  private:
    string nombre, genero;
    vector<Capitulo*> listaCapitulos;
};

Serie::Serie()
{
  nombre = "--";
  listaCapitulos.resize(0);
}

Serie::Serie(string name, string gen, vector<Capitulo*> chList)
{
  nombre = name;
  genero = gen;
  listaCapitulos = chList;
}

void Serie::getListaCapitulos()
{
  int numCap = listaCapitulos.size();
  for(int i = 0; i < numCap; i++)
  {
    listaCapitulos.at(i) -> mostrar();
  }
}

void Serie::mostrar()
{
  cout << "Nombre: " << nombre << endl;
  cout << "Genero: " << genero << endl;
  cout << "Numero de episodios: " << listaCapitulos.size() << endl;
  cout << endl;
}
#endif