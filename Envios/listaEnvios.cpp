#include <iostream>
#include <fstream>
#include <string>
#include "Sobre.h"
#include "Paquete.h"
using namespace std;

int main()
{
  int cantEnvios = 0;
  int total = 0;
  char tipoEnvio;
  string nombreRem, estadoRem, ciudadRem, nombreDes, estadoDes, ciudadDes, line, cpRem, cpDes;
  int costo, peso, costoKg, largo, ancho, cargoAdicional;
  Envio *listaEnvios[cantEnvios];
  ifstream fileEnvios;

  fileEnvios.open("datosEnvios.txt");
  while(getline(fileEnvios, line))
  {
    cantEnvios++;
  }
  fileEnvios.close();

  fileEnvios.open("datosEnvios.txt");
  int cont = 0;

  for(int i = 0; i < cantEnvios; i++)
  {
    while(fileEnvios >> tipoEnvio)
    {
      fileEnvios >> nombreRem >> estadoRem >> ciudadRem >> cpRem >> nombreDes >> estadoDes >> ciudadDes >> cpDes;
      Persona remitente(nombreRem, estadoRem, ciudadRem, cpRem);
      Persona destinatario(nombreDes, estadoDes, ciudadDes, cpDes);

      if(tipoEnvio == 'p')
      {
        fileEnvios >> costo >> peso >> costoKg;
        listaEnvios[i] = new Paquete(remitente, destinatario, costo, peso, costoKg);
      }
      else
      {
        fileEnvios >> costo >> largo >> ancho >> cargoAdicional;
        listaEnvios[i] = new Sobre(remitente, destinatario, costo, largo, ancho, cargoAdicional);
      }
      cout << "Remitente:" << endl; remitente.imprimir();
      cout << "Destinatario: " << endl; destinatario.imprimir();
      cout << "Costo: " << listaEnvios[i] -> calculaCostoEnvio() << endl;
      total += listaEnvios[i] -> calculaCostoEnvio();
      i++;
    }
  }

  cout << "Total envios: " << total << endl;
  return 0;
}
