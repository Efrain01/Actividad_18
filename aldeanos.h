#ifndef ALDEANOS_H_INCLUDED
#define ALDEANOS_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Aldeano{
    private:
        string nombre;
        int edad;
        string genero;
        float salud;
    public:
        Aldeano();
        Aldeano(const string &nombre, int edad, const string &genero, float salud);
        void setNombre(const string &a);
        string getNombre()const;
        void setEdad(int a);
        int getEdad()const;
        void setGenero(const string &a);
        string getGenero()const;
        void setSalud(float a);
        float getSalud()const;

        friend ostream & operator<<(ostream &out, const Aldeano &p){
        out << left;
        out << setw(20) << p.nombre;
        out << setw(10) << p.edad;
        out << setw(10) << p.genero;
        out << setw(10) << p.salud;
        out << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Aldeano &p){
        fflush(stdin);
        cout<< "Nombre: ";
        getline(cin, p.nombre);

        cout<< "Edad: ";
        cin >> p.edad;

        fflush(stdin);
        cout<< "Genero: ";
        getline(cin, p.genero);
        cout<< "Salud: ";
        cin>>p.salud;


        return in;
    }

    bool operator==(const Aldeano& q){
        return nombre == q.nombre;
    }
    bool operator==(const Aldeano& q)const{
        return nombre == q.nombre;
    }

    bool operator<(const Aldeano& q){
        return nombre < q.nombre;
    }

    bool operator<(const Aldeano& q)const{
        return nombre < q.nombre;
    }
};

#endif // ALDEANOS_H_INCLUDED
