using namespace std;
#include <iostream>

class Complejo
{ 
  public:
    Complejo();
    Complejo(double r, double i);
    Complejo suma(Complejo suma);
    void imprimirResultado();
    void imprimir();
    void setReal(double r) {real = r;};
    void setImaginario(double i) {imaginario = i;};
    double getReal() {return real;};
    double getImaginario() {return imaginario;};
  private:
    double real;
    double imaginario;
};

Complejo::Complejo()
{
  real = 0;
  imaginario = 0;
}

Complejo::Complejo(double r, double i)
{
  real = r;
  imaginario = i;
}

Complejo Complejo::suma(Complejo c2)
{
  Complejo resultado;
  resultado.real = real + c2.real;
  resultado.imaginario = imaginario + c2.imaginario;
  return resultado;
}

void Complejo::imprimir()
{
  cout << real << " + " << imaginario << "i";
}

void Complejo::imprimirResultado()
{
  cout << "Suma: " << real << " + " << imaginario << "i";
}