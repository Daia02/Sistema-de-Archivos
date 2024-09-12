
#ifndef CLASEJUGADOR_H_INCLUDED
#define CLASEJUGADOR_H_INCLUDED



class Jugador {
private:
    int dni;
    char nombre[30];
    char apellido [30];
    char email[30];
    char telefono [30];
    int claustro; //(1: docente; 2 alumno; 3 no docente; 4 graduado)
    int deporte; // (número entre 1 y 10)
    int num_equipo; // (número entero)
    Fecha FechaInscripcion;
    float matricula;
    bool estado;


public:
    void set_dni (int d){dni=d;}
    void set_nombre (const char *n){strcpy(nombre,n); }
    void set_apellido (const char *a){strcpy(apellido,a);}
    void set_email (const char *e){strcpy (email,e);}
    void set_telefondo (const char *tel){strcpy (telefono,tel);}
    void set_claustro (int c){c=claustro;}
    void set_deporte (int d) {if ((deporte>0) && (deporte<=10)) deporte=d;
    else cout<<"NO VALIDO "<<endl;}
    void set_equipo (int equipo){num_equipo=equipo;}
    void set_fecha (Fecha f){FechaInscripcion=f;}
    void set_matricula (float m){if(matricula>=0) matricula=m;}
    void set_estado (bool es){estado=es;}


    int get_dni(){return dni;}
    const char *get_nombre (){return nombre;}
    const char *get_apellido (){return apellido;}
    const char *get_email (){return email;}
    const char *get_telefono (){return telefono;}
    int get_claustro (){return claustro;}
    int get_deporte (){return deporte;}
    int get_equipo (){return num_equipo;}
    Fecha get_fecha (){return FechaInscripcion;}
    float get_matricula (){return matricula;}
    bool get_estado (){return estado;}

    void Cargar(int DNI);
    void Mostrar();

};
void Jugador::Cargar(int DNI){
bool flag=true;
archivoEquipos archE("equipos.dat");


dni=DNI;
cout<<"INGRESE NOMBRE: "<<endl;
cin>>nombre;
cout<<"INGRESE APELLIDO: "<<endl;
cargarCadena(nombre,30);
cout<<"INGRESE EMAIL: "<<endl;
cargarCadena(email,30);
cout<<"INGRESE TELEFONO: "<<endl;
cargarCadena(telefono,30);
do{
            cout << "INGRESE CLAUSTRO (valor entre 1 y 4): "<<endl;
            cin >> claustro;

            if (claustro > 0 && claustro < 5) {
                break; // Salir del bucle si el valor es válido
            } else {
                 rlutil::setColor(rlutil::RED);
                cout << "Valor de claustro no valido. Intentalo de nuevo." << endl;
                 rlutil::setColor(rlutil::WHITE);
            }}
         while (true);

do{
            cout << "INGRESE DEPORTE (valor entre 1 y 10): "<<endl;
            cin >> claustro;

            if (claustro > 0 && claustro < 11) {
                break; // Salir del bucle si el valor es válido
            } else {
                 rlutil::setColor(rlutil::RED);
                cout << "Valor de deporte no valido. Intentalo de nuevo." << endl;
                 rlutil::setColor(rlutil::WHITE);
            }}
         while (true);


do{
flag=true;
cout<<"INGRESE ID DE EQUIPO: "<<endl;
cin>>num_equipo;

if(archE.contarRegistros()==0){flag=true;}
else{if(archE.buscarEquipo(num_equipo)==-1){
     rlutil::setColor(rlutil::RED);
    cout<<"EL ID DE EQUIPO NO COINCIDE "<<endl;
     rlutil::setColor(rlutil::WHITE);
    cout<<"INGRESE NUEVAMENTE ID DE EQUIPO: "<<endl;
    cin>>num_equipo;
    flag=false;
}
}
}while(!flag);


cout<<"INGRESE FECHA "<<endl;
FechaInscripcion.Cargar();
cout<<"INGRESE MATRICULA "<<endl;
cin>>matricula;
estado=true;
}

void Jugador::Mostrar(){
if(this->estado==false)return;
cout<<"DNI:"<<dni<<endl;
cout<<"NOMBRE: "<<nombre<<endl;
cout<<"APELLIDO: "<<apellido<<endl;
cout<<"EMAIL: "<<email<<endl;
cout<<"TELEFONO: "<<telefono<<endl;
cout<<"CLAUSTRO: "<<claustro<<endl;
cout<<"DEPORTE: "<<deporte<<endl;
cout<<"NUMERO DE EQUIPO "<<num_equipo<<endl;
cout<<"FECHA : ";
FechaInscripcion.Mostrar();
cout<<"MATRICULA: "<<matricula<<endl;
}




#endif // CLASEJUGADOR_H_INCLUDED
