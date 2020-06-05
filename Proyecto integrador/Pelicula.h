#ifndef Pelicula_h
#define Pelicula_h

using namespace std;
#include <iostream>
#include <string>
#include "Video.h"

class Pelicula : public Video
{
  public:
    Pelicula();
    Pelicula(int id, string name, int dur, string direc, string gen, double cal, bool os);
    void setDirector(string direc) {director = direc;}
    void setOscar(bool os) {oscar = os;}
    string getDirector() {return director;}
    bool getOscar() {return oscar;}
    void mostrar();
  private:
    string director;
    bool oscar;
};

Pelicula::Pelicula():Video()
{
  director = "--";
  oscar = false;
}

Pelicula::Pelicula(int id, string name, int dur, string direc, string gen, double cal, bool os):Video(id,name, dur, gen, cal)
{
  director = direc;
  oscar = os;
}

void Pelicula::mostrar()
{
  cout << "ID: " << ID << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Duracion: " << duracion << " minutos" << endl;
  cout << "Director: " << director << endl;
  cout << "Genero: " << genero << endl;
  cout << "Calificacion: " << calificacion << endl;
  if(oscar)
  {
    cout << "Ganadora de un Oscar";
    cout << endl;
  }
  cout << endl;
}

#endif