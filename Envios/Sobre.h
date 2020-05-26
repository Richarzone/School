#ifndef Sobre_h
#define Sobre_h

#include <iostream>
#include <string>
#include "Envio.h"
using namespace std;

class Sobre : public Envio
{
  public:
    Sobre();
    Sobre(Persona rem, Persona des, double cost, double l, double a, double cargo);
    void setLargo(double l) {largo = l;};
    void setAncho(double a) {ancho = a;};
    void setCargoAdicional(double cargo) {cargoAdicional = cargo;};
    double getLargo() {return largo;};
    double getAncho() {return ancho;};
    double getCargoAdicional() {return cargoAdicional;};
    double calculaCostoEnvio();
  private:
    double largo;
    double ancho;
    double cargoAdicional;
};

Sobre::Sobre()
{
  largo = 0;
  ancho = 0;
  cargoAdicional = 0;
}

Sobre::Sobre(Persona rem, Persona des, double cost, double l, double a, double cargo):Envio(rem, des, cost)
{
  largo = l;
  ancho = a;
  cargoAdicional = cargo;
}

double Sobre::calculaCostoEnvio()
{
  if(largo > 25 && ancho > 30)
  {
    return costo + cargoAdicional;
  }
  else
  {
    return costo;
  }
}

#endif