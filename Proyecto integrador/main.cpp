using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pelicula.h"
#include "Serie.h"

void cargaDatos(Pelicula *listaPeliculas[], Serie *listaSeries[], vector<Video*> &listaVideos, int &peliculas, int &series , int &cantVideos)
{
  ifstream fileVideos;
  char tipoDeVideo;
  int palabras = 0;
  int id, duracion;
  string nombre, genero, director, serie, currentS, currentG, temporada, line, os;
  double calificacion;
  bool oscar;
  vector<string> stringHolder;
  vector<Capitulo*> listaCapitulos;
  vector<Capitulo*> capituloHolder;
 
  fileVideos.open("ListaDeContenido.txt");
  while(getline(fileVideos, line))
  {
    cantVideos++;
  }
  fileVideos.close();

  fileVideos.open("ListaDeContenido.txt");
  while(fileVideos >> line)
  {
    stringHolder.push_back(line);
    palabras++;
  }
  fileVideos.close();

  fileVideos.open("ListaDeContenido.txt");

  //cout << cantVideos << endl;

  for(int i = 0; i < cantVideos; i++)
  {
    while (fileVideos >> tipoDeVideo)
    {
      if(tipoDeVideo == 'p')
      {
        fileVideos >> id >> nombre >> duracion >> genero >> calificacion >> director >> os;
        if(os == "si")
        {
          oscar = true;
        }
        else
        {
          oscar = false;
        }
        listaPeliculas[peliculas] = new Pelicula(id, nombre, duracion, director, genero, calificacion, oscar);
        listaVideos.push_back(new Pelicula(id, nombre, duracion, director, genero, calificacion, oscar));
        peliculas++;
      }
      else
      {
        fileVideos >> id >> nombre >> duracion >> genero >> calificacion >> serie >> temporada;
        listaVideos.push_back(new Capitulo(id, nombre, serie, temporada, duracion, genero, calificacion));
        listaCapitulos.push_back(new Capitulo(id, nombre, serie, temporada, duracion, genero, calificacion));
        
        int cont = 0;

        currentS = serie;
        currentG = genero;

        for(int j = 0; j < palabras; j++)
        {
          if(stringHolder.at(j) == serie)
          {
            cont++;
          }
        }

        for(int w = 0; w < cont-1; w++)
        {
          fileVideos >> tipoDeVideo >> id >> nombre >> duracion >> genero >> calificacion >> serie >> temporada;
          listaCapitulos.push_back(new Capitulo(id, nombre, serie, temporada, duracion, genero, calificacion));
          listaVideos.push_back(new Capitulo(id, nombre, serie, temporada, duracion, genero, calificacion));
        }
        
        listaSeries[series] = new Serie(currentS, currentG, listaCapitulos);
        listaCapitulos.clear();
        series++;
      } 
    } 
  }
  stringHolder.clear();
}

void mostrarPeliculas(Pelicula*listaPeliculas[], int &peliculas)
{
  for(int i = 0; i < peliculas; i++)
  {
    listaPeliculas[i] -> mostrar();
  }
}

void mostrarSeries(Serie*listaSeries[], int &series)
{
  for(int i = 0; i < series; i++)
  {
    listaSeries[i] -> mostrar();
  }
}

void mostrarEpisodios(Serie*listaSeries[], int &series)
{
  int seleccion;
  string menuLoop = "si";

  while(menuLoop == "si")
  {
    cout << "Selecciona una serie" << endl;
    for(int i = 0; i < series; i++)
    {
      cout << i + 1 << ") ";
      cout << listaSeries[i] -> getNombre() << endl;
    }
    cin >> seleccion;
    seleccion = seleccion - 1;
    if(seleccion <= series-1)
    {
      listaSeries[seleccion] -> getListaCapitulos();
      cout << "Quieres ver otra serie?" << endl;
      cin >> menuLoop;
    }
    else
    {
      cout << "Busqueda no encontrada" << endl;
    }
    
  }
  cout << "Regresando al menu principal..." << endl;
}

void buscarPorCalificacion(vector<Video*> &listaVideos, int &cantVideos)
{
  double cal;
  int cont = 0;

  string menuLoop = "si";
  while(menuLoop == "si")
  {
    cout << "Ingresa la calificacion:" << endl;
    cin >> cal;

    for(int i = 0; i < cantVideos; i++)
    {
      
      if(listaVideos[i] -> getCalificacion() == cal)
      {
        listaVideos[i] -> mostrar();
      }
      else
      {
        cont++;
      } 
    }
    
    if(cont == cantVideos)
    {
      cout << "Busqueda no encontrada" << endl;
      cont = 0; 
    }

    cont = 0; 

    cout << "Quieres hacer otra busqueda?" << endl;
    cin >> menuLoop;
  }
  cout << "Regresando al menu principal..." << endl;
}

void buscarPorGenero(vector<Video*> &listaVideos, int &cantVideos)
{
  string gen, currG, g;
  int cont = 0;
  int cantGeneros = 0;
  string listaGeneros[10];

  for(int i = 0; i < cantVideos; i++)
  {
    g = listaVideos[i] -> getGenero();
    if(currG != g)
    {
      currG = g;
      listaGeneros[cantGeneros] = currG;
      cantGeneros++;
    }
  }

  string menuLoop = "si";
  while(menuLoop == "si")
  {
    cout << "Ingresa el genero que quieras ver:" << endl;
    for(int i = 0; i < cantGeneros; i++)
    {
      cout << i + 1 << ") ";
      cout << listaGeneros[i] << endl;
    }
    cin >> gen;

    for(int i = 0; i < cantVideos; i++)
    {
      if(listaVideos[i] -> getGenero() == gen)
      {
        listaVideos[i] -> mostrar();
      }
      else
      {
        cont++;
      }
    }
    
    if(cont == cantVideos)
    {
      cout << "Busqueda no encontrada" << endl;
      cont = 0; 
    }
    
    cont = 0; 

    cout << "Quieres hacer otra busqueda?" << endl;
    cin >> menuLoop;
  }
  cout << "Regresando al menu principal..." << endl;
}

void buscarPorCalificacionP(Pelicula *listaPeliculas[], int &peliculas)
{
  double cal;
  bool busqueda;
  int cont = 0;
  string menuLoop = "si";
  while(menuLoop == "si")
  {
    cout << "Ingresa la calificacion:" << endl;
    cin >> cal;

    for(int i = 0; i < peliculas; i++)
    {
      busqueda = listaPeliculas[i] -> getCalificacion() == cal;
      if(busqueda)
      {
        listaPeliculas[i] -> mostrar();
      }
      else
      {
        cont++;
      }
    }

    if(cont == peliculas)
    {
      cout << "Busqueda no encontrada" << endl;
      cont = 0; 
    }

    cont = 0; 

    cout << "Quieres hacer otra busqueda?" << endl;
    cin >> menuLoop;
    
  }
  cout << "Regresando al menu principal..." << endl;
}

void recomendacionDelDia(Pelicula *listaPeliculas[], int &peliculas)
{
  cout << "Hoy recomendamos que veas:" << endl;

  for(int i = 0; i < peliculas; i++)
  {
    if(listaPeliculas[i] -> getNombre() == "Parasite")
    {
      listaPeliculas[i] -> mostrar();
    }
  }
}

int main()
{ 
  Pelicula *listaPeliculas[10];
  Serie *listaSeries[10];
  vector<Video*> listaVideos;
  char respuesta;
  int cantVideos = 0;
  int peliculas = 0;
  int series = 0;
  string resp;

  cout << "Bienvenido" << endl;
  cargaDatos(listaPeliculas, listaSeries, listaVideos, peliculas, series, cantVideos);
  
  string menuLoop = "si";
  cout << "Que deseas hacer hoy?" << endl;
  cout << endl;

  while (menuLoop == "si")
  {
    cout << "a) Mostrar lista de peliculas | b) Mostrar lista de series | c) Buscar por calificacion | d) Buscar por genero | e) Mostrar episodios de una serie | f) Buscar peliculas por calificacion | g) Recomendacion del dia | r) Refrescar | x) Salir" << endl; 
    cin >> respuesta;
    switch (respuesta)
    {
      case 'a':
        mostrarPeliculas(listaPeliculas, peliculas);
        break;
      case 'b':
        mostrarSeries(listaSeries, series);
        cout << "Quieres ver una de estas series?" << endl;
        cin >> resp;
        if (resp == "si")
        {
          mostrarEpisodios(listaSeries, series);
        }
        break;
      case 'c':
        buscarPorCalificacion(listaVideos, cantVideos);
        break;
      case 'd':
        buscarPorGenero(listaVideos, cantVideos);
        break;
      case 'e':
        //mostrarSeries(listaSeries, series);
        mostrarEpisodios(listaSeries, series); 
        break;
      case 'f':
        buscarPorCalificacionP(listaPeliculas, peliculas);
        break;
      case 'g':
        recomendacionDelDia(listaPeliculas, peliculas);
        break;
      case 'r':
        cout << "Refrescando..." << endl;
        cargaDatos(listaPeliculas, listaSeries, listaVideos, peliculas, series, cantVideos);
        cout << "Listo" << endl;
        break;
      case 'x':
        cout << "Vuelve pronto" << endl;
        exit(0);
        break;
    }
    cout << "Deseas hacer otra accion?" << endl;
    cin >> menuLoop;
  }
  cout << "Vuelve pronto" << endl;
  return 0;
}