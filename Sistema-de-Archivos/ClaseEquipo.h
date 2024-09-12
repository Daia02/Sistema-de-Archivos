#ifndef CLASEEQUIPO_H_INCLUDED
#define CLASEEQUIPO_H_INCLUDED

class Equipo {
private:

    int id;
    char nombre[30];
    int nivel; //Número entre 1 y 8
    bool estado;


public:
    void set_id (int d){id=d;}
    void set_nombre (const char *n){strcpy(nombre,n); }
    void set_nivel(int niv){if(niv>0 && niv<9)nivel=niv;
    else cout<<"EL NIVEL NO ES CORRECTO."<<endl;}
    void set_estado (bool es){estado=es;}


    int get_id(){return id;}
    const char *get_nombre (){return nombre;}
    int get_nivel (){return nivel;}
    bool get_estado (){return estado;}

    void Cargar(int ID);
    void Mostrar();

};
void Equipo::Cargar(int ID){
id=ID;
cout<<"INGRESE NOMBRE DE EQUIPO "<<endl;
cargarCadena(nombre,29);
cout<<"INGRESE NIVEL "<<endl;
cin>>nivel;


estado=true;
}

void Equipo::Mostrar(){
if(this->estado==false)return;
cout<<"ID DE EQUIPO: "<<id<<endl;
cout<<"NOMBRE: "<<nombre<<endl;
cout<<"NIVEL: "<<nivel<<endl;
}



#endif // CLASEEQUIPO_H_INCLUDED
