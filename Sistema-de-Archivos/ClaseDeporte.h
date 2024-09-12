
#ifndef CLASEDEPORTE_H_INCLUDED
#define CLASEDEPORTE_H_INCLUDED

#include <iomanip>

class Deporte {
private:

    int id;
    char nombre[30];
    int tipo; //Número entre 1 y  21
    int anio; // Número entre 1800 y el año actual
    bool estado;


public:
    void set_id (int d){id=d;}
    void set_nombre (const char *n){strcpy(nombre,n); }
    void set_tipo (int t){if(tipo>0 && tipo<20)tipo=t;
    else cout<<"EL TIPO NO ES CORRECTO."<<endl;}
    void set_anio (int a){anio=a;}
    void set_estado (bool es){estado=es;}


    int get_id(){return id;}
    const char *get_nombre (){return nombre;}
    int get_tipo (){return tipo;}
    int get_anio (){return anio;}
    bool get_estado (){return estado;}

    void Cargar(int ID);
    void Mostrar(){
    cout<<"ID DE DEPORTE: "<<id<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"TIPO : "<<tipo<<endl;
    cout<<"ANIO: "<<anio<<endl;
}

};
void Deporte::Cargar(int ID){
id=ID;
cout<<"INGRESE NOMBRE "<<endl;
cin>>nombre;

do{
            cout<<"INGRESE TIPO (valor entre 1 y 21): "<<endl;
            cin>>tipo;

            if (tipo > 0 && tipo < 22) {
                break; // Salir del bucle si el valor es válido
            } else {
                 rlutil::setColor(rlutil::RED);
                cout << "Valor de tipo no valido. Intentalo de nuevo." << endl;
                 rlutil::setColor(rlutil::WHITE);
            }}
         while (true);

 do{

            cout<<"INGRESE ANIO (valor entre 1800 y anio actual): "<<endl;
            cin>>anio;

            if (anio >= 1800 && anio < 2024) {
                break; // Salir del bucle si el valor es válido
            } else {
                 rlutil::setColor(rlutil::RED);
                cout << "Valor de anio no valido. Intentalo de nuevo." << endl;
                 rlutil::setColor(rlutil::WHITE);
            }}
         while (true);


estado=true;
}

/*void Deporte::Mostrar(){
if(this->estado==false)return;
cout<<"ID DE DEPORTE: "<<id<<endl;
cout<<"NOMBRE: "<<nombre<<endl;
cout<<"TIPO: "<<tipo<<endl;
cout<<"ANIO: "<<anio<<endl;
}*/







#endif // CLASEDEPORTE_H_INCLUDED
