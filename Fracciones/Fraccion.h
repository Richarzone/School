
#ifndef  Fraccion_h
#define  Fraccion_h

#include <iostream>

using namespace std;

class Fraccion {
private:
    int numerador;
    int denominador;
public:
    Fraccion();
    Fraccion(int numerador, int denominador);
    int getNumerador();
    int getDenominador();
    void setNumerador(int numerador);
    void setDenominador(int denominador);
    Fraccion suma(Fraccion suma);
    Fraccion multiplicacion(Fraccion mult);
    void imprimir();
    void reducir();
};

Fraccion::Fraccion() {
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int numerador, int denominador) {
    if ((numerador > 0 && denominador < 0) || (numerador < 0 && denominador < 0)){
        numerador *= -1;
        denominador *= -1;
    }
    this->numerador = numerador;
    this->denominador = denominador;
    reducir();
}

void Fraccion::setNumerador(int numerador)
{
    this->numerador = numerador;
}

void Fraccion::setDenominador(int denominador)
{
    this->denominador = denominador;
}

int Fraccion::getNumerador() {
    return numerador;
}

int Fraccion::getDenominador() {
    return denominador;
}

Fraccion Fraccion::suma(Fraccion f2){
    Fraccion resultado;
    if (denominador == f2.denominador) {
        resultado.numerador = numerador + f2.numerador;
        resultado.denominador = denominador;
    }
    else {
        int d1 = this->denominador;
        int d2 = f2.denominador;
        resultado.numerador = numerador * d2 + f2.getNumerador() * d1;
        resultado.denominador = d1 * d2;
    }
    resultado.reducir();
    return resultado;
}

Fraccion Fraccion::multiplicacion(Fraccion f2){
    Fraccion resultado;
    resultado.numerador = numerador * f2.numerador;
    resultado.denominador = denominador * f2.denominador;
    resultado.reducir();
    return resultado;
}

void Fraccion::imprimir() {
    cout << this->numerador << "/" << this->denominador;
}

void Fraccion::reducir() {
    int red;
    if (numerador > denominador)
        red = denominador;
    else
        red = numerador;
    while (red > 1) {
        if (numerador % red == 0 && denominador % red == 0) {
            numerador /= red;
            denominador /= red;
        }
        red--;
        
    }
}

#endif

