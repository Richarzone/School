#ifndef Paquete_h
#define Paquete_h

#include <iostream>
#include <string>
#include "Envio.h"
using namespace std;

class Paquete : public Envio
{
  public:
    Paquete();
    Paquete(Persona rem, Persona des, double cost, double p, double cargoKg);
    void setPeso(double p) {peso = p;};
    void setCargoKg(double cargoKg) {cargoPorKg = cargoKg;};
    double getPeso() {return peso;};
    double getCargoKg() {return cargoPorKg;};
    double calculaCostoEnvio();
  private:
    double peso;
    double cargoPorKg;
};

Paquete::Paquete()
{
  peso = 0;
  cargoPorKg = 0;
}

Paquete::Paquete(Persona rem, Persona des, double cost, double p, double cargoKg):Envio(rem, des, cost)
{
  peso = p;
  cargoPorKg = cargoKg;
}

double Paquete::calculaCostoEnvio()
{
  return costo + peso * cargoPorKg;
}

#endif