#ifndef CLASETIPODEDEPORTE_H_INCLUDED
#define CLASETIPODEDEPORTE_H_INCLUDED
class TipoDeDeporte {
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
void TipoDeDeporte::Cargar(int ID){
id=ID;
cout<<"INGRESE NOMBRE DE DEPORTE "<<endl;
cargarCadena(nombre,29);
cout<<"INGRESE NIVEL DE DIFICULTAD"<<endl;
cin>>nivel;


estado=true;
}

void TipoDeDeporte::Mostrar(){
if(this->estado==false)return;
cout<<"ID DE TIPO DE DEPORTE: "<<id<<endl;
cout<<"NOMBRE: "<<nombre<<endl;
cout<<"NIVEL DE DIFICULTAD: "<<nivel<<endl;
}




#endif // CLASETIPODEDEPORTE_H_INCLUDED
