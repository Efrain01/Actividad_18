#include "civilizacion.h"
#include <algorithm>
#include <fstream>
Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre, const float ubicacion_x, const float ubicacion_y, float puntuacion){
    this->nombre = nombre;
    this->ubicacion_x = ubicacion_x;
    this->ubicacion_y = ubicacion_y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &c){
    nombre = c;
}
string Civilizacion::getNombre(){
    return nombre;
}

void Civilizacion::setUbicacion_x(const float c){
    ubicacion_x = c;
}
float Civilizacion::getUbicacion_x(){
    return ubicacion_x;
}

void Civilizacion::setUbicacion_y(const float c){
    ubicacion_y =  c;
}
float Civilizacion::getUbicacion_y(){
    return ubicacion_y;
}

void Civilizacion::setPuntuacion(float c){
    puntuacion = c;
}
float Civilizacion::getPuntuacion(){
    return puntuacion;
}

//-------------------------------------------------

void Civilizacion::agregar_final(const Aldeano &a){
    aldeanos.push_back(a);
}

void Civilizacion::agregar_inicio(const Aldeano &a){
    aldeanos.push_front(a);
}

void Civilizacion::mostrar(){
    cout << left;
    cout <<setw(20) << "Nombre";
    cout <<setw(10) << "Edad";
    cout <<setw(10) << "Genero";
    cout <<setw(10) << "Salud";
    cout << endl;
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout<< *it <<endl;
    }
}

void Civilizacion::eliminar_nombre(const string &nombre){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &c = *it;
        if(nombre == c.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminar_salud(float x){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &c = *it;
        if(c.getSalud()< x){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminar_edad(){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &c = *it;
        if(c.getEdad() >= 60){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::modificar(const string &nombre){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        char op;
        if(nombre == a.getNombre()){
            cout << left;
            cout <<setw(20) << "Nombre";
            cout <<setw(10) << "Salud";
            cout <<setw(10) << "Genero";
            cout <<setw(10) << "Edad";
            cout << endl;
            cout<< a;
            cout<<endl;
            cout<<"Modifificar: "<<endl<<"1.- Nombre"<<endl<<"2.- Salud"<<endl<<"3.- Genero"<<endl<<"4.- Edad"<<endl<<"Opcion: ";
            cin>>op;
            if(op == '1'){
                string nombre;
                cout<<"Nombre: ";
                fflush(stdin);
                getline(cin,nombre);
                a.setNombre(nombre);
            }else if(op == '2'){
                float salud;
                cout<<"Salud: ";
                cin>>salud; cin.ignore();
                a.setSalud(salud);
            }else if(op == '3'){
                string genero;
                cout<<"Genero: ";
                getline(cin,genero);
                a.setGenero(genero);
            }else if(op == '4'){
                int edad;
                cout<<"Edad: ";
                cin>>edad; cin.ignore();
                a.setEdad(edad);
            }else{
                cout<<"Opcion invalida";
            }
            break;
        }
    }
}

Aldeano* Civilizacion::buscar(const Aldeano &p){
    auto it = find(aldeanos.begin(), aldeanos.end(),p);
    if(it == aldeanos.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

void Civilizacion::ordenar_nombre(){
    aldeanos.sort();
}

bool comparadorsalud(const Aldeano &a1, const Aldeano &a2){
    return (a1.getSalud() > a2.getSalud());
}

void Civilizacion::ordenar_salud(){
    aldeanos.sort(comparadorsalud);
}

bool comparadoredad(const Aldeano &a1, const Aldeano &a2){
    return (a1.getEdad() > a2.getEdad());
}

void Civilizacion::ordenar_edad(){
    aldeanos.sort(comparadoredad);
}