
#ifndef ARCHIVODEPORTES_H_INCLUDED
#define ARCHIVODEPORTES_H_INCLUDED

class archivoDeportes{
private:
    char nombre [30];

public:
    archivoDeportes (const char *n){ strcpy (nombre,n);}

    int buscarDeporte(int id);

    bool listarPorId();






    Deporte leerRegistro(int pos){
    Deporte deporte;    ///Instancia de objeto --> El objeto esta VACIO
    FILE *p;
    p= fopen(nombre,"rb"); ///Sin comillas nombre, xq es una variable que va a tener el nombre dentro de la variable.
        if(p==NULL) return deporte;
    fseek (p,sizeof deporte*pos,0);     ///File buscar !
    fread (&deporte,sizeof deporte, 1, p);
        fclose(p);
    return deporte;
    }

     int buscarRegEliminados(){
   Deporte deporte;
   int cantReg=contarRegistros();
   int cant=0;
   for(int i=0;i<cantReg;i++){
    deporte=leerRegistro(i);
    if(deporte.get_estado()==false) cant++;
   }
   return cant;
   }

///Agregar registro
     bool agregarRegistro(Deporte deporte){
    int cant;
    FILE *p;
    p= fopen(nombre,"ab");
        if(p==NULL) return false;
    int id;
    cant=buscarRegEliminados();
    id=contarRegistros()+1;
    if(id==10){
    id=contarRegistros()-cant;}
    else{
    if(id<=10 && id>0){
            cout<<"INGRESE DATOS DEL DEPORTE CON ID "<<id<<" : "<<endl;
             deporte.Cargar(id);
    int escribio= fwrite(&deporte,sizeof deporte, 1,p);
        fclose(p);
    return escribio;}
    else{
    cout<<"se alcanzo limite de deportes"<<endl;
    return false;
    }}
   }



///Mostrar registros
    int mostrarRegistros(){
    Deporte deporte;
    bool bandera=false;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&deporte,sizeof deporte, 1,p)== 1){///Encontro un registro y me muestra el registro
        if (deporte.get_estado()==false){
            bandera=true;
        }
cout << left;
cout<<endl;
cout << setw(6)<<deporte.get_id();
cout << setw(30)<<deporte.get_nombre();
cout <<setw(6)<<deporte.get_tipo();
cout <<setw(8)<<deporte.get_anio();

      cout << endl;
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
    return tam/sizeof(Deporte); /// Nos devuelve la cantidad de registro del archivo, este es un entero (int).

    }

///borrar registro
    bool bajaLogicaRegistro(){
    int id, pos;
    Deporte deporte;
   // ArchivoEmpresa ae;
    char opc;
    cout << "Ingresar el ID del deporte a dar de baja ";
    cin >> id;
    ///Buscar si el jugador existe en el archivo
    pos= buscarDeporte(id);///Recibo la posición del jugador si existe.
        if(pos == -1){
        cout << "No existe ese ID." << endl;
        return false;
        }
          if(pos == -2){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
        }
        deporte= leerRegistro(pos);  ///me devuelve el OBJETO completo de empresa enviandole la posición.
        cout << "EL registro a borrar: " << endl;
        deporte.Mostrar();
        cout<< endl;
        cout << "Esta seguro de borrar el registro?(S/N)";
        cin >> opc;
        if(opc == 'S' || opc== 's'){
            deporte.set_estado(false);
    bool escribio= sobreEscribirRegistro(deporte, pos);
        return escribio;
        }
        return false;
    }


 bool sobreEscribirRegistro(Deporte deporte, int pos){//Registro que ya esta en el archivo, escribe de nuevo en la posicion que le manda por parametro

 FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        return false;
        }
    fseek(p,sizeof deporte*pos,0);
    bool escribio=fwrite(&deporte,sizeof deporte,1,p);
    fclose(p);
    return escribio;
 }




  bool ModificarAnio(){
 Deporte deporte;
 int id,pos=0;
 ///buscar el registro a modificar
 cout<<"INGRESE EL ID DEL REGISTRO A MODIFICAR : ";
 cin>>id;
 ///leer si existe el registro
 pos=buscarDeporte(id);
 if(pos==-1){
    cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
    return false;
 }
 deporte=leerRegistro(pos);

if(deporte.get_estado()==false){
    cout<<"EL CLIENTE INGRESADO YA ESTA DADO DE BAJA"<<endl;
    return false;
}
cout<<"EL REGISTRO A MODIFICAR EL ANIO ES : "<<endl;
deporte.Mostrar();
cout<< endl;
    int anioNuevo;
    cout<<"INGRESE EL NUEVO ANIO: "<<endl;
    cin>>anioNuevo;
    deporte.set_anio(anioNuevo);
    bool aux=sobreEscribirRegistro(deporte,pos);
    return aux;
}

 ///copia de seguridad
  bool copiaDeSeguridadDeportes(){
    Deporte deporte;
    FILE *p;
    p=fopen("deportes.bkp","wb");
    if(p==NULL){return false;}
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        deporte=leerRegistro(i);
        fwrite(&deporte,sizeof deporte,1,p);
    }

   fclose (p);
   return true;
}

///restaurar archivos
bool restaurarDeportes() {
    FILE* pD;
    FILE* pBkp;

    pD = fopen("deportes.bkp", "rb");
    if (pD == NULL) {
        cout << "Error al abrir el archivo deportes.bkp." << endl;
        return false;
    }

    pBkp= fopen("deportes.dat", "wb");
    if (pBkp == NULL) {
        cout << "Error al abrir el archivo deportes.dat." << endl;
        fclose(pD);
        return false;
    }

    Deporte deporte;
    while (fread(&deporte, sizeof(Deporte), 1, pD) == 1) {
        if (deporte.get_estado()) {
            fwrite(&deporte, sizeof(Deporte), 1, pBkp);
        }
    }

    fclose(pD);
    fclose(pBkp);
    return true;
}




bool datosInicioDeportes() {
    FILE* pDeportes;
    FILE* pDeportesinicio;

    pDeportes = fopen("deportesinicio.dat", "rb");
    if (pDeportes == NULL) {
        cout << "Error al abrir el archivo deportesinicio.dat." << endl;
        return false;
    }

    pDeportesinicio = fopen("deportes.dat", "wb");
    if (pDeportesinicio == NULL) {
        cout << "Error al abrir el archivo deportes.dat." << endl;
        fclose(pDeportes);
        return false;
    }

    Deporte deporte;
    while (fread(&deporte, sizeof(Deporte), 1, pDeportes) == 1) {
        if (deporte.get_estado()) {
            fwrite(&deporte, sizeof(Deporte), 1, pDeportesinicio);
        }
    }

    fclose(pDeportes);
    fclose(pDeportesinicio);
    return true;
}


};

int archivoDeportes::buscarDeporte(int id){
Deporte deporte;
int pos=0;

FILE *p;
    p= fopen(nombre, "rb");
    if(p==NULL){
        return -2;
        }
  int cantRegistros= contarRegistros();
  while(pos < cantRegistros){
      deporte= leerRegistro(pos);
    if( id == deporte.get_id()){
        fclose(p);
        return pos;
    }
    pos++;
  }
    fclose(p);
    return -1;
}

bool archivoDeportes::listarPorId(){
Deporte dep;
 int id;
 cout<<"INGRESE ID QUE DESEA LISTAR: ";
 cin>>id;
int pos=buscarDeporte(id);
 if(pos==-1){
    cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
    return false;
 }

 dep=leerRegistro(pos);
  if(id==dep.get_id()){
        dep.Mostrar();}

 return false;

 }

#endif // ARCHIVODEPORTES_H_INCLUDED
