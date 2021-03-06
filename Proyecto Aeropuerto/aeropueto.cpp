using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vuelo.h"
#include "Reservacion.h"

void cargarDatosReservacion(Reservacion listaReservacion[], int &reservaciones)
{
  ifstream fileReservaciones;
  string id, nombre, numVuelo;

  fileReservaciones.open("Pasajeros.txt");

  reservaciones = 0;
  while (fileReservaciones >> id >> nombre >> numVuelo)
  {
    listaReservacion[reservaciones].setIdPasajero(id);
    listaReservacion[reservaciones].setNombrePasajero(nombre);
    listaReservacion[reservaciones].setNumeroDeVuelo(numVuelo);
    reservaciones++;
  }
}

void mostrarReservaciones(Reservacion listaReservacion[], Vuelo listaDeVuelos[], int reservaciones, int cantDeVuelos)
{
  for(int i = 0; i < cantDeVuelos; i++)
  {
    cout << "Pasajero con numero de vuelo " << listaDeVuelos[i].getNumeroDeVuelo() << endl;
    for(int cont = 0; cont < reservaciones; cont++)
    {
      if(listaReservacion[cont].getNumeroDeVuelo() == listaDeVuelos[i].getNumeroDeVuelo())
      {
        cout << listaReservacion[cont].getIdPasajero() << " ";
        cout << listaReservacion[cont].getNombrePasajero() << " "; 
        cout << listaReservacion[cont].getNumeroDeVuelo() << endl;
      }
    }
    cout << "-------------------------------------" << endl;
  }
}

void realizarReservacion(Reservacion listaReservacion[], int &reservaciones)
{
  string id, nombre, numVuelo;
  string respuestaLoop = "si";

  while (respuestaLoop == "si")
  {
    cout << "Ingrese el numero de vuelo del viaje que quiera reservar" << endl;
    cin >> numVuelo;
    cout << "Ingrese el nombre del pasajero (Los espacions se ingresan con '_')" << endl;
    cin >> nombre;
    cout << "Ingrese el ID de la persona" << endl;
    cin >> id;

    listaReservacion[reservaciones].setIdPasajero(id);
    listaReservacion[reservaciones].setNombrePasajero(nombre);
    listaReservacion[reservaciones].setNumeroDeVuelo(numVuelo);
    reservaciones++;

    cout << "Desea hacer otra reservacion?" << endl;
    cin >> respuestaLoop;
  }
}

void cargaDatosVuelos(Vuelo listaDeVuelos[], Reservacion listaReservacion[], int &cantVuelos)
{
  ifstream fileVuelos;
  string numVuelo, origen, destino;
  int horaSalida, minSalida, horaDuracion, minDuracion;

  fileVuelos.open("VuelosDelDia.txt");
  
  cantVuelos = 0;
  while (fileVuelos >> numVuelo >> horaSalida >> minSalida >> origen >> destino >> horaDuracion >> minDuracion)
  {
    Tiempo t1, t2;
    t1.setHora(horaSalida);
    t1.setMinuto(minSalida);
    t2.setHora(horaDuracion);
    t2.setMinuto(minDuracion);

    listaDeVuelos[cantVuelos].setNumeroDeVuelo(numVuelo);
    listaDeVuelos[cantVuelos].setTiempo1(t1);
    listaDeVuelos[cantVuelos].setCiudadDeOrigen(origen);
    listaDeVuelos[cantVuelos].setCiudadDeDestino(destino);
    listaDeVuelos[cantVuelos].setTiempo2(t2);
    cantVuelos++;
  }
}

void mostrarVuelos(Vuelo listaDeVuelos[], int &cantVuelos)
{
  Tiempo tTemporal;
  cout << "----------------------------------------" << endl;
  for(int cont = 0; cont < cantVuelos; cont++)
  {
    cout << "| " << listaDeVuelos[cont].getNumeroDeVuelo() << " | ";
    tTemporal = listaDeVuelos[cont].getTiempo1();
    cout << tTemporal.getHora() << ":" << tTemporal.getMinuto() << " | ";
    cout << listaDeVuelos[cont].getCiudadDeOrigen() << " | ";
    cout << listaDeVuelos[cont].getCiudadDeDestino() << " | ";
    tTemporal = listaDeVuelos[cont].getTiempo2();
    cout << tTemporal.getHora() << ":" << tTemporal.getMinuto() << " | " << endl;
  }
  cout << "----------------------------------------" << endl;
}

void agregarVuelo(Vuelo listaDeVuelos[], int &cantVuelos)
{
  string numVuelo, origen, destino;
  int horaSalida, minSalida, horaDuracion, minDuracion;
  Tiempo t1, t2;

  cout << "Ingrese el numero de vuelo" << endl;
  cin >> numVuelo;
  cout << "Ingrese el horario de salida (Ingrese la hora y separe con un espacio para ingresar los minutos)" << endl;
  cin >> horaSalida >> minSalida;
  cout << "Ingrese las siglas del lugar de origen (MAYUS)" << endl;
  cin >> origen;
  cout << "Ingrese las siglas del lugar de destino (MAYUS)" << endl;
  cin >> destino;
  cout << "Ingrese tiempo de duracion del vuelo (Ingrese las horas y separe con un espacio para ingresar los minutos)" << endl;
  cin >> horaDuracion >> minDuracion;

  t1.setHora(horaSalida);
  t1.setMinuto(minSalida);
  t2.setHora(horaDuracion);
  t2.setMinuto(minDuracion);

  listaDeVuelos[cantVuelos].setNumeroDeVuelo(numVuelo);
  listaDeVuelos[cantVuelos].setTiempo1(t1);
  listaDeVuelos[cantVuelos].setCiudadDeOrigen(origen);
  listaDeVuelos[cantVuelos].setCiudadDeDestino(destino);
  listaDeVuelos[cantVuelos].setTiempo2(t2);
  cantVuelos++;
}

void mostrarAeropuertos()
{
  ifstream filePuertos;
  string nombrePuerto, IATA;
  filePuertos.open("Aeropuertos.txt");

  while (filePuertos >> IATA >> nombrePuerto)
  {
    cout << IATA << " " << nombrePuerto << endl;
  }
  filePuertos.close();
}

int main()
{
  Reservacion listaReservacion[20];
  Vuelo listaDeVuelos[10];
  int cantVuelos, reservaciones;
  char respuesta;
  string menuLoop = "si";
  string reservResp;

  cargaDatosVuelos(listaDeVuelos, listaReservacion, cantVuelos);
  cargarDatosReservacion(listaReservacion, reservaciones);

  cout << "Bienvenido" << endl;
  cout << endl;

  while (menuLoop == "si")
  {
    cout << "Seleccione una de las siguientes opciones presionando la tecla correspondiente" << endl;
    cout << "a) Mostrar lista de aeropuertos | b) Mostrar vuelos disponibles | c) Realizar una reservacion | d) Mostrar lista de pasajeros con reservacion | e) Agregar vuelo al sistema | x) Salir" << endl; 
    cout << "Vuelos disponibles: " << cantVuelos << endl;
    cin >> respuesta;
    switch (respuesta)
    {
      case 'a':
        mostrarAeropuertos();
        break;
      case 'b':
        mostrarVuelos(listaDeVuelos, cantVuelos);
        cout << "Desea hacer una reservacion?" << endl;
        cin >> reservResp;
        if(reservResp == "si")
        {
          realizarReservacion(listaReservacion, reservaciones);
        }
        break;
      case 'c':
        realizarReservacion(listaReservacion, reservaciones);
        break;
      case 'd':
        mostrarReservaciones(listaReservacion, listaDeVuelos, reservaciones, cantVuelos);
        break;
      case 'e':
        agregarVuelo(listaDeVuelos, cantVuelos);
        break;
      case 'x':
        cout << "Vuelva pronto" << endl;
        exit(0);
        break;
    }
    cout << "Deasea hacer otra accion?" << endl;
    cin >> menuLoop;
  }
  return 0;
}