#ifndef Capitulo_h
#define Capitulo_h

using namespace std;
#include <iostream>
#include <string>
#include "Video.h"

class Capitulo : public Video
{
  public:
    Capitulo();
    Capitulo(int id, string name, string ser, string temp, int dur, string gen, double cal);
    void setTemporada(string temp) {temporada = temp;}
    string getTemporada() {return temporada;}
    void setSerie(string ser) {serie = ser;}
    string getSerie() {return serie;}
    void mostrar();
  private:
    string temporada, serie;
};

Capitulo::Capitulo():Video()
{
  temporada = "--";
  serie = "--";
}

Capitulo::Capitulo(int id, string name, string ser, string temp, int dur, string gen, double cal):Video(id, name, dur, gen, cal)
{
  temporada = temp;
  serie = ser;
}

void Capitulo::mostrar()
{
  cout << "ID: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Temporada: " << temporada << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Calificacion: " << calificacion << endl;
  cout << endl;
}

#endif