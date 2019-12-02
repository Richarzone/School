using namespace std;
#include <string>
class Reservacion
{
  public:
    Reservacion();
    Reservacion(string nV, string ID, string nom);
    string getNumeroDeVuelo();
    void setNumeroDeVuelo(string nV);
    string getIdPasajero();
    void setIdPasajero(string ID);
    string getNombrePasajero();
    void setNombrePasajero(string nom);
  private:
    string id, nombre, numVuelo;
};

Reservacion::Reservacion()
{
  id = "--";
  nombre = "--";
  numVuelo = "--";
}

Reservacion::Reservacion(string nV, string ID, string nom)
{
  id = ID;
  nombre = nom;
  numVuelo = nV;
}

string Reservacion::getNumeroDeVuelo()
{
  return numVuelo;
}

void Reservacion::setNumeroDeVuelo(string nV)
{
  numVuelo = nV;
}

string Reservacion::getIdPasajero()
{
  return id;
}

void Reservacion::setIdPasajero(string ID)
{
  id = ID;
}

string Reservacion::getNombrePasajero()
{
  return nombre;
}

void Reservacion::setNombrePasajero(string nom)
{
  nombre = nom;
}