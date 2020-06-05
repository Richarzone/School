#ifndef Video_h
#define Video_h

using namespace std;
#include <iostream>
#include <string>

class Video
{
  public:
    Video();
    Video(int id, string name, int dur, string gen, double cal);
    void setID(int id) {ID = id;}
    void setNombre(string name) {nombre = name;}
    void setDuracion(int dur) {duracion = dur;}
    void setCalificacion(double cal) {calificacion = cal;}
    int getID() {return ID;}
    string getNombre() {return nombre;}
    int getDuracion() {return duracion;}
    string getGenero() {return genero;}
    double getCalificacion() {return calificacion;}
    virtual void mostrar() = 0;
  protected:
    int ID, duracion;
    string nombre, genero;
    double calificacion;
};

Video::Video()
{
  ID = 0;
  nombre = "--";
  duracion = 0;
  genero = "--";
  calificacion = 0.0;
}

Video::Video(int id, string name, int dur, string gen, double cal)
{
  ID = id;
  nombre = name;
  duracion = dur;
  genero = gen;
  calificacion = cal;
}

#endif
