#include "aldeanos.h"
#include <algorithm>
Aldeano::Aldeano(){}

Aldeano::Aldeano(const string &nombre, int edad, const string &genero, float salud){
    this->nombre = nombre;
    this->edad =  edad;
    this->genero = genero;
    this->salud = salud;
}

void Aldeano::setNombre(const string &a){
    nombre = a;
}
string Aldeano::getNombre()const{
    return nombre;
}

void Aldeano::setEdad(int a){
    edad = a;
}
int Aldeano::getEdad()const{
    return edad;
}

void Aldeano::setGenero(const string &a){
    genero = a;
}
string Aldeano::getGenero()const{
    return genero;
}

void Aldeano::setSalud(float a){
    salud = a;
}
float Aldeano::getSalud()const{
    return salud;
}