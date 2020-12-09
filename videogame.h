#ifndef VIDEOGAME_H_INCLUDED
#define VIDEOGAME_H_INCLUDED

#include "civilizacion.h"
#include <algorithm>
#include <vector>

class Videogame{
    private:
        string nombre_usuario;
        vector<Civilizacion> civilizaciones;
    public:
        Videogame();
        void agregar(const Civilizacion &p);
        void insertar(const Civilizacion&p, size_t pos);
        void inicializar(const Civilizacion&p, size_t n);
        void primero();
        void ultimo();
        void ordenar_nombre();
        void ordenar_ubicacion_x();
        void ordenar_ubicacion_y();
        void ordenar_puntacion();
        void eliminar(const string &nombre);
        void modificar(const string &nombre);
        Civilizacion* buscar(const Civilizacion &p);
        void mostrar();
        size_t size();

    friend Videogame& operator<<(Videogame &v, const Civilizacion &p){
        v.agregar(p);
        return v;
    }

};

#endif // VIDEOGAME_H_INCLUDED
