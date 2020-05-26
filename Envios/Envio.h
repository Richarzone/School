#ifndef Envio_h
#define Envio_h

using namespace std;
#include <iostream>
#include <string>
#include "Persona.h"

class Envio
{
  public:
    Envio();
    Envio(Persona rem, Persona des, double cost);
    void setRemitente(Persona rem) {remitente = rem;};
    void setDestinatario(Persona des) {destinatario = des;};
    void setCostoEstandar(double cost) {costo = cost;};
    Persona getRemitente() {return remitente;};
    Persona getDestinatario() {return destinatario;};
    double getCostoEstandar() {return costo;};
    virtual double calculaCostoEnvio() = 0;
  protected:
    Persona remitente;
    Persona destinatario;
    double costo;
};

Envio::Envio()
{
  remitente = Persona();
  destinatario = Persona();
  costo = 0;
}

Envio::Envio(Persona rem, Persona des, double cost)
{
  remitente = rem;
  destinatario = des;
  costo = cost;
}

#endif