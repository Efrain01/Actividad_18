#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED


#include <iostream>
#include <iomanip>
#include <algorithm>
#include "aldeanos.h"
#include <list>

using namespace std;

class Civilizacion{
    private:
        string nombre;
        float ubicacion_x;
        float ubicacion_y;
        float puntuacion;
        list<Aldeano> aldeanos;
    public:
        Civilizacion();
        Civilizacion(const string &nombre, const float ubicacion_x, const float ubicacion_y, float puntuacion);
        void setNombre(const string &c);
        string getNombre();
        void setUbicacion_x(const float c);
        float getUbicacion_x();
        void setUbicacion_y(const float c);
        float getUbicacion_y();
        void setPuntuacion(float c);
        float getPuntuacion();
        //-------------------------------------------------
        void agregar_final(const Aldeano &a);
        void agregar_inicio(const Aldeano &a);
        void mostrar();
        void eliminar_nombre(const string &nombre);
        void eliminar_salud(float x);
        void eliminar_edad();
        void ordenar_nombre();
        void ordenar_salud();
        void ordenar_genero();
        void ordenar_edad();
        void modificar(const string &nombre);
        Aldeano* buscar(const Aldeano &p);

    friend ostream & operator<<(ostream &out, const Civilizacion &p){
        out << left;
        out << setw(20) << p.nombre;
        out << setw(20) << p.ubicacion_x;
        out << setw(20) << p.ubicacion_y;
        out << setw(5) << p.puntuacion;
        out << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &p){
        fflush(stdin);
        cout<< "Nombre: ";
        getline(cin, p.nombre);

        cout<< "Ubicacion en x: ";
        cin >> p.ubicacion_x;

        cout<< "Ubicacion en y: ";
        cin >> p.ubicacion_y;
        fflush(stdin);
        cout<< "Puntuacion: ";
        cin>>p.puntuacion;


        return in;
    }

    bool operator==(const Civilizacion& p){
        return (nombre == p.nombre);
    }

    bool operator==(const Civilizacion& p) const{
        return (nombre == p.nombre);
    }

    bool operator<(const Civilizacion& p){
        return nombre < p.nombre;
    }

    bool operator<(const Civilizacion& p) const{
        return nombre < p.nombre;
    }


};

#endif // CIVILIZACION_H_INCLUDED
