#include <iostream>
#include "videogame.h"
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    Videogame v;
    Civilizacion civ;
    string op;
    string nombre_usuario;

    do{
        cout<<"01.- Nombre de usuario"<<endl;
        cout<<"02.- Agregar civilizacion"<<endl;
        cout<<"03.- Insertar civilizacion"<<endl;
        cout<<"04.- Crear civilizacion"<<endl;
        cout<<"05.- Primera civilizacion"<<endl;
        cout<<"06.- Ultima civilizacion"<<endl;
        cout<<"07.- Ordenar"<<endl;
        cout<<"08.- Eliminar civilizacion"<<endl;
        cout<<"09.- Buscar"<<endl;
        cout<<"10.- Modificar"<<endl;
        cout<<"11.- Resumen"<<endl;
        cout<<"12.- Salir"<<endl<<endl;
        cout<<"Opcion: ";
        getline(cin,op);

        if(op == "1" || op == "01"){
            cout<<"Esta en la opccion: "<<op<<endl;
            cout<<"Nombre de usuario: ";
            getline(cin,nombre_usuario);
            system("pause");
            system("cls");
            //---------------------------------------------------------1
        }else if (op == "2" || op == "02"){
            cout<<"Esta en la opccion: "<<op<<endl;
            Civilizacion c;
            cin>>c; cin.ignore();
            v.agregar(c);
            system("pause");
            system("cls");
            //---------------------------------------------------------2
        }else if (op == "3" || op == "03"){
            cout<<"Esta en la opccion: "<<op<<endl;
            Civilizacion c;
            cin>>c;
            size_t pos;
            cout<<"Posicion a insertar: ";
            cin>>pos; cin.ignore();
            if(pos >= v.size()){
                cout<<"Posicion invalida"<<endl;
            }else{
                v.insertar(c,pos);
            }
            system("pause");
            system("cls");
            //---------------------------------------------------------3
        }else if (op == "4" || op == "04"){
            cout<<"Esta en la opccion: "<<op<<endl;
            Civilizacion c;
            cin>>c;
            size_t n;
            cout<<"n: ";
            cin>>n; cin.ignore();
            v.inicializar(c,n);
            system("pause");
            system("cls");
            //---------------------------------------------------------4
        }else if (op == "5" || op == "05"){
            cout<<"Esta en la opccion: "<<op<<endl;
            v.primero();
            system("pause");
            system("cls");
            //---------------------------------------------------------5
        }else if (op == "6" || op == "06"){
            cout<<"Esta en la opccion: "<<op<<endl;
            v.ultimo();
            system("pause");
            system("cls");
            //---------------------------------------------------------6
        }else if (op == "7" || op == "07"){
            cout<<"Esta en la opccion: "<<op<<endl;
            cout<<"Ordenar por: "<<endl<<"1.- Nombre."<<endl<<"2.- Ubicacion en x."<<endl<<"3.- Ubicacion en y"<<endl<<"4.- Puntuacion"<<endl;
            string opc;
            cout<<"Opcion: ";
            getline(cin,opc); //cin.ignore();
            if(opc == "1" || opc == "01"){
                v.ordenar_nombre();
            }else if(opc == "2" || opc == "02"){
                v.ordenar_ubicacion_x();
            }else if(opc == "3" || opc == "03"){
                v.ordenar_ubicacion_y();
            }else if(opc == "4" || opc == "04"){
                v.ordenar_puntacion();
            }else{
                cout<<"opccion no valida.";
            }
            system("pause");
            system("cls");
            //---------------------------------------------------------7
        }else if (op == "8" || op == "08"){
            cout<<"Esta en la opccion: "<<op<<endl;
            string nombre;
            cout<<"Civilizacion: ";
            getline(cin,nombre);
            v.eliminar(nombre);
            system("pause");
            system("cls");
            //---------------------------------------------------------8
        }else if (op == "9" || op == "09"){
            cout<<"Esta en la opccion: "<<op<<endl;
            Civilizacion c;
            cin>>c;
            Civilizacion *ptr = v.buscar(c);
            if(ptr == nullptr){
                cout<<"No encontrado"<<endl;
            }else{
                size_t op;
                cout << left;
                cout <<setw(20) << "Nombre";
                cout <<setw(20) << "Edad";
                cout <<setw(20) << "Genero";
                cout <<setw(5) << "Salud";
                cout << endl;
                cout<<*ptr<<endl;
                cout<<"Menu"<<endl<<endl<<"1.- Agregar aldeano"<<endl<<"2.- Eliminar aldeano"<<endl<<"3.- Clasificar aldeano"<<endl<<"4.- Buscar aldeano"<<endl<<"5.- Modificar aldeano"<<endl<<"6.- Mostrar aldeano"<<endl<<"Opcion: ";
                cin>>op; cin.ignore();
                if(op == 1){//agregar aldeano
                    Aldeano a;
                    size_t op;
                    cout<<"1.- Agregar al principio"<<endl<<"2.- Agregar al final"<<endl<<"Opcion: ";
                    cin>>op; cin.ignore();
                    if(op == 1){
                        cin>>a; cin.ignore();
                        civ.agregar_inicio(a);
                        ptr-> setPuntuacion(ptr->getPuntuacion()+100);
                    }else if(op == 2){
                        cin>>a; cin.ignore();
                        civ.agregar_final(a);
                        ptr-> setPuntuacion(ptr->getPuntuacion()+100);
                    }else{
                        cout<<"Opcion invalida";
                        civ.agregar_final(a);
                    }
                }else if(op == 2){//elimina aldeano
                    cout<<"1.- Eliminar por nombre"<<endl<<"2.- Eliminar aldeanos donde su salud sea menor que lo indicado"<<endl<<"3.- Eliminar aldeanos donde su edad sea mayor igual a 60"<<endl<<"Opcion";
                    size_t op;
                    cin>>op; cin.ignore();
                    if(op == 1){
                        string nombre;
                        cout<<"Nombre: ";
                        getline(cin,nombre);
                        civ.eliminar_nombre(nombre);
                    }else if(op == 2){
                        float x;
                        cout<<"Salud a determinar: ";
                        cin>>x; cin.ignore();
                        civ.eliminar_salud(x);
                    }else if(op == 3){
                        civ.eliminar_edad();
                    }else{
                        cout<<"Opcion invalida";
                    }
                }else if(op == 3){//clasifica
                    cout<<"1.- Clasificar la lista de aldeanos por nombre (ascendente)"<<endl<<"2.- Clasificar la lista de aldeanos por edad (descendente)"<<endl<<"3.- Ordenar la lista de aldeanos por salud (descendente)"<<endl<<"Opcion: ";
                    size_t op;
                    cin>>op; cin.ignore();
                    if(op == 1){
                        civ.ordenar_nombre();
                    }else if(op == 2){
                        civ.ordenar_edad();
                    }else if(op == 3){
                        civ.ordenar_salud();
                    }else{
                        cout<<"Opcion invalida";
                    }
                }else if(op == 4){//busca
                    Aldeano a;
                    cin>>a; cin.ignore();
                    Aldeano *ptr1 = civ.buscar(a);
                    if(ptr1 == nullptr){
                        cout<<"No encontrado";
                    }else{
                        cout << left;
                        cout <<setw(20) << "Nombre";
                        cout <<setw(10) << "Edad";
                        cout <<setw(10) << "Genero";
                        cout <<setw(10) << "Salud";
                        cout << endl;
                        cout<<*ptr1<<endl;
                    }
                }else if(op == 5){//modificar
                    string nombre;
                    cout<<"Aldeano: ";
                    getline(cin,nombre);
                    civ.modificar(nombre);
                }else if(op == 6){//mostrar
                    civ.mostrar();
                }else{
                    cout<<"Opcion invalida";
                }
            }
            system("pause");
            system("cls");
            //---------------------------------------------------------9
        }else if (op == "10"){
            cout<<"Esta en la opccion: "<<op<<endl;
            string nombre;
            cout<<"Civilizacion: ";
            getline(cin,nombre);
            v.modificar(nombre);
            system("pause");
            system("cls");
            //---------------------------------------------------------10
        }else if (op == "11"){
            cout<<"Esta en la opccion: "<<op<<endl;
            cout<<"Usuario: "<<nombre_usuario<<endl<<endl;
            v.mostrar();
            system("pause");
            system("cls");
            //---------------------------------------------------------11
            v.mostrar();
        }else if (op == "12"){
            cout<<"Esta en la opccion: "<<op<<endl;
            system("pause");
            system("cls");
            //---------------------------------------------------------12
        }else{
            cout<<"No es una opccion valida . . ."<<endl;
        }
    }while(op != "12");




    return 0;
}
