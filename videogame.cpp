#include "videogame.h"
#include <fstream>
#include <algorithm>

Videogame::Videogame(){}

void Videogame::agregar(const Civilizacion &p){
    civilizaciones.push_back(p);
}

void Videogame::insertar(const Civilizacion&p, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, p);
}

void Videogame::inicializar(const Civilizacion&p, size_t n){
    civilizaciones = vector<Civilizacion>(n,p);
}

void Videogame::primero(){
    if(civilizaciones.empty()){
        cout<<"Esta vacio";
    }else{
        cout << left;
        cout <<setw(20) << "Nombre";
        cout <<setw(20) << "Ubicacion en x";
        cout <<setw(20) << "Ubicacion en y";
        cout <<setw(5) << "Puntuacion";
        cout << endl;
        cout<<civilizaciones.front()<<endl;
    }
}

void Videogame::ultimo(){
    if(civilizaciones.empty()){
        cout<<"Esta vacio";
    }else{
        cout << left;
        cout <<setw(20) << "Nombre";
        cout <<setw(20) << "Ubicacion en x";
        cout <<setw(20) << "Ubicacion en y";
        cout <<setw(5) << "Puntuacion";
        cout << endl;
        cout<<civilizaciones.back()<<endl;
    }
}

void Videogame::ordenar_nombre(){
    sort(civilizaciones.begin(), civilizaciones.end());
}

void Videogame::ordenar_ubicacion_x(){
    sort(civilizaciones.begin(), civilizaciones.end(), [] (Civilizacion c1, Civilizacion c2) {return c1.getUbicacion_x() < c2.getUbicacion_x();});
}

void Videogame::ordenar_ubicacion_y(){
    sort(civilizaciones.begin(), civilizaciones.end(), [] (Civilizacion c1, Civilizacion c2) {return c1.getUbicacion_y() < c2.getUbicacion_y();});
}

void Videogame::ordenar_puntacion(){
    sort(civilizaciones.begin(), civilizaciones.end(), [] (Civilizacion c1, Civilizacion c2) {return c1.getPuntuacion() < c2.getPuntuacion();});
}

Civilizacion* Videogame::buscar(const Civilizacion &p){
    auto it = find(civilizaciones.begin(), civilizaciones.end(),p);
    if(it == civilizaciones.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}
void Videogame::eliminar(const string &nombre){
    for(auto it = civilizaciones.begin(); it != civilizaciones.end(); it++){
        Civilizacion &c = *it;
        if(nombre == c.getNombre()){
            civilizaciones.erase(it);
            break;
        }
    }
}

void Videogame::modificar(const string &nombre){
    for(auto it = civilizaciones.begin(); it != civilizaciones.end(); it++){
        Civilizacion &c = *it;
        char op;
        if(nombre == c.getNombre()){
            cout << left;
            cout <<setw(20) << "Nombre";
            cout <<setw(20) << "Ubicacion en x";
            cout <<setw(20) << "Ubicacion en y";
            cout <<setw(5) << "Puntuacion";
            cout << endl;
            cout<< c;
            cout<<endl;
            cout<<"Modifificar: "<<endl<<"1.- Nombre"<<endl<<"2.- Ubicacion en x"<<endl<<"3.- Ubicacion en y"<<endl<<"4.- Puntuacion"<<endl<<"Opcion: ";
            cin>>op;
            if(op == '1'){
                string nombre;
                cout<<"Nombre: ";
                fflush(stdin);
                getline(cin,nombre);
                c.setNombre(nombre);
            }else if(op == '2'){
                float x;
                cout<<"Ubicacion en x: ";
                cin>>x; cin.ignore();
                c.setUbicacion_x(x);
            }else if(op == '3'){
                float y;
                cout<<"Ubicacion en y: ";
                cin>>y; cin.ignore();
                c.setUbicacion_y(y);
            }else if(op == '4'){
                float puntuacion;
                cout<<"Puntuacion: ";
                cin>>puntuacion; cin.ignore();
                c.setPuntuacion(puntuacion);
            }else{
                cout<<"Opcion invalida";
            }
            break;
        }
    }
}
void Videogame::mostrar(){
    cout << left;
    cout <<setw(20) << "Nombre";
    cout <<setw(20) << "Ubicacion en x";
    cout <<setw(20) << "Ubicacion en y";
    cout <<setw(5) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++){
        Civilizacion &p = civilizaciones[i];
        cout<< p;
        cout<<endl;
    }
}

size_t Videogame::size(){
    return civilizaciones.size();
}