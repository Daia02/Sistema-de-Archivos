#ifndef ARCHIVOEQUIPOS_H_INCLUDED
#define ARCHIVOEQUIPOS_H_INCLUDED
class archivoEquipos{
private:
    char nombre [30];

public:
    archivoEquipos (const char *n){ strcpy (nombre,n);}

    int buscarEquipo(int id);

    bool listarPorId();
    bool copiaDeSeguridadEquipos();


    Equipo leerRegistro(int pos){
    Equipo equipo;    ///Instancia de objeto --> El objeto esta VACIO
    FILE *p;
    p= fopen(nombre,"rb"); ///Sin comillas nombre, xq es una variable que va a tener el nombre dentro de la variable.
        if(p==NULL) return equipo;
    fseek (p,sizeof equipo*pos,0);     ///File buscar !
    fread (&equipo,sizeof equipo, 1, p);
        fclose(p);
    return equipo;
    }
///Agregar registro
     bool agregarRegistro(Equipo equipo){

    FILE *p;
    p= fopen(nombre,"ab");
        if(p==NULL) return false;
    int id;
    cout<<"INGRESE ID DE EQUIPO: "<<endl;
    cin>>id;
    if(buscarEquipo(id)>=0){
        cout<<"EL ID YA EXISTE"<<endl;
        return false;
    }
    equipo.Cargar(id);
    int escribio= fwrite(&equipo,sizeof equipo, 1,p);
        fclose(p);
    return escribio;
    }
///Mostrar registros
    int mostrarRegistros(){
    Equipo equipo;
    bool bandera=false;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&equipo,sizeof equipo, 1,p)== 1){///Encontro un registro y me muestra el registro
        if (equipo.get_estado()==false){
            bandera=true;
        }
        cout<<left;
        cout<<setw(8)<<equipo.get_id();
        cout<<setw(30)<<equipo.get_nombre();
        cout<<setw(3)<<equipo.get_nivel();
        if(equipo.get_estado()){
            cout<<"true"<<endl;
        }
        cout<<endl;


    }
    int cantRegistros=contarRegistros();
    if(cantRegistros==1  &&  bandera ){ //|| alt+124
        cout<<"No hay registros en el archivo "<<endl;
    }
    if(cantRegistros==0) cout<<"No hay registros en el archivo "<<endl;

    }

    ///Contar registros
    int contarRegistros(){

    FILE *p;
    p=fopen(nombre,"rb");
        if(p==NULL) return -1;
    fseek(p,0,2);
    int tam= ftell(p); ///Aca preguntamos al archivo que tamaño tenes. Devuelve la cantidad de bytes que tiene el archivo en total. .
    fclose(p);
    return tam/sizeof(Equipo); /// Nos devuelve la cantidad de registro del archivo, este es un entero (int).

    }


    bool bajaLogicaRegistro(){
    int id, pos;
    Equipo equipo;
   // ArchivoEmpresa ae;
    char opc;
    cout << "Ingresar el ID del deporte a dar de baja ";
    cin >> id;
    ///Buscar si el jugador existe en el archivo
    pos= buscarEquipo(id);///Recibo la posición del jugador si existe.
        if(pos == -1){
        cout << "No existe ese ID." << endl;
        return false;
        }
          if(pos == -2){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
        }
        equipo= leerRegistro(pos);  ///me devuelve el OBJETO completo de empresa enviandole la posición.
        cout << "EL registro a borrar: " << endl;
        equipo.Mostrar();
        cout<< endl;
        cout << "Esta seguro de borrar el registro?(S/N)";
        cin >> opc;
        if(opc == 'S' || opc== 's'){
            equipo.set_estado(false);
    bool escribio= sobreEscribirRegistro(equipo, pos);
        return escribio;
        }
        return false;
    }


 bool sobreEscribirRegistro(Equipo equipo, int pos){//Registro que ya esta en el archivo, escribe de nuevo en la posicion que le manda por parametro

 FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        return false;
        }
    fseek(p,sizeof equipo*pos,0);
    bool escribio=fwrite(&equipo,sizeof equipo,1,p);
    fclose(p);
    return escribio;
 }


  bool ModificarNombre(){
 Equipo equipo;
 int id,pos=0;
 ///buscar el registro a modificar
 cout<<"INGRESE EL ID DEL REGISTRO A MODIFICAR : ";
 cin>>id;
 ///leer si existe el registro
 pos=buscarEquipo(id);
 if(pos==-1){
    cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
    return false;
 }
 equipo=leerRegistro(pos);

if(equipo.get_estado()==false){
    cout<<"EL ID INGRESADO YA ESTA DADO DE BAJA"<<endl;
    return false;
}
cout<<"EL REGISTRO A MODIFICAR EL NOMBRE ES : "<<endl;
equipo.Mostrar();
cout<< endl;
    char nombreNuevo[30] ;
    cout<<"INGRESE EL NUEVO NOMBRE: "<<endl;
    cargarCadena(nombreNuevo,30);
    equipo.set_nombre(nombreNuevo);
    bool aux=sobreEscribirRegistro(equipo,pos);
    return aux;
}


///RESTAURAR ARCHIVOS
bool restaurarEquipos() {
    FILE* pE;
    FILE* pBkp;

    pE = fopen("equipos.bkp", "rb");
    if (pE == NULL) {
        cout << "Error al abrir el equipos.bkp." << endl;
        return false;
    }

    pBkp= fopen("equipos.dat", "wb");
    if (pBkp == NULL) {
        cout << "Error al abrir el archivo equipos.dat." << endl;
        fclose(pE);
        return false;
    }

    Equipo equipo;
    while (fread(&equipo, sizeof(Equipo), 1, pE) == 1) {
        if (equipo.get_estado()) {
            fwrite(&equipo, sizeof(Equipo), 1, pBkp);
        }
    }

    fclose(pE);
    fclose(pBkp);
    return true;
}

bool datosInicioEquipos() {
    FILE* pEquipos;
    FILE* pEquiposinicio;

    pEquipos = fopen("equiposinicio.dat", "rb");
    if (pEquipos == NULL) {
        cout << "Error al abrir el archivo equiposinicio.dat." << endl;
        return false;
    }

    pEquiposinicio = fopen("equipos.dat", "wb");
    if (pEquiposinicio == NULL) {
        cout << "Error al abrir el archivo deportes.dat." << endl;
        fclose(pEquipos);
        return false;
    }

    Equipo equipo;
    while (fread(&equipo, sizeof(Equipo), 1, pEquipos) == 1) {
        if (equipo.get_estado()) {
            fwrite(&equipo, sizeof(Equipo), 1, pEquiposinicio);
        }
    }

    fclose(pEquipos);
    fclose(pEquiposinicio);
    return true;
}

};

int archivoEquipos::buscarEquipo(int id){
Equipo equipo;
int pos=0;

FILE *p;
    p= fopen(nombre, "rb");
    if(p==NULL){
        return -2;
        }
  int cantRegistros= contarRegistros();
  while(pos < cantRegistros){
      equipo= leerRegistro(pos);
    if( id == equipo.get_id()){
        fclose(p);
        return pos;
    }
    pos++;
  }
    fclose(p);
    return -1;
}

bool archivoEquipos::listarPorId(){
Equipo equipo;
 int id;
 cout<<"INGRESE ID QUE DESEA LISTAR: ";
 cin>>id;
int pos=buscarEquipo(id);
 if(pos==-1){
    cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
    return false;
 }

 equipo=leerRegistro(pos);
  if(id==equipo.get_id()){
        equipo.Mostrar();}

 return false;
 }

 bool archivoEquipos::copiaDeSeguridadEquipos(){
    Equipo equipo;
    FILE *p;
    p=fopen("equipos.bkp","wb");
    if(p==NULL){return false;}
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        equipo=leerRegistro(i);
        fwrite(&equipo,sizeof equipo,1,p);
    }
    return true;
   fclose (p);

}



#endif // ARCHIVOEQUIPOS_H_INCLUDED
