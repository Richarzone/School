using namespace std;
#include <string>
#include "Tiempo.h"

class Vuelo
{
  public:
    Vuelo();
    Vuelo(string nV, Tiempo tiempo1, string cO, string cD, Tiempo tiempo2);
    string getNumeroDeVuelo();
    void setNumeroDeVuelo(string nV);
    string getCiudadDeOrigen();
    void setCiudadDeOrigen(string cO);
    string getCiudadDeDestino();
    void setCiudadDeDestino(string cD);
    Tiempo getTiempo1();
    void setTiempo1(Tiempo tiempo1);
    Tiempo getTiempo2();
    void setTiempo2(Tiempo tiempo2);
  private:
    string numeroVuelo, ciudadOrigen, ciudadDestino;
    Tiempo horaDeSalida, horaDeLlegada;
};

Vuelo::Vuelo()
{
  numeroVuelo = "--";
  ciudadOrigen = "--";
  ciudadDestino = "--";
  Tiempo tiempo1, tiempo2;
  tiempo1.setHora(0);
  tiempo1.setMinuto(0);
  tiempo2.setHora(0);
  tiempo2.setMinuto(0);
  horaDeSalida = tiempo1;
  horaDeLlegada = tiempo2;
}

Vuelo::Vuelo(string nV, Tiempo tiempo1, string cO, string cD, Tiempo tiempo2)
{
  numeroVuelo = nV;
  ciudadOrigen = cO;
  ciudadDestino = cD;
  horaDeSalida = tiempo1;
  horaDeLlegada = tiempo2;
}

string Vuelo::getNumeroDeVuelo()
{
  return numeroVuelo;
}

void Vuelo::setNumeroDeVuelo(string nV)
{
  numeroVuelo = nV;
}

string Vuelo::getCiudadDeOrigen()
{
  return ciudadOrigen;
}

void Vuelo::setCiudadDeOrigen(string cO)
{
  ciudadOrigen = cO;
}

string Vuelo::getCiudadDeDestino()
{
  return ciudadDestino;
}

void Vuelo::setCiudadDeDestino(string cD)
{
  ciudadDestino = cD;
}

Tiempo Vuelo::getTiempo1()
{
    return horaDeSalida;
}

void Vuelo::setTiempo1(Tiempo tiempo1)
{
    horaDeSalida = tiempo1;
}

Tiempo Vuelo::getTiempo2()
{
    return horaDeLlegada;
}

void Vuelo::setTiempo2(Tiempo tiempo2)
{
    horaDeLlegada = tiempo2;
}