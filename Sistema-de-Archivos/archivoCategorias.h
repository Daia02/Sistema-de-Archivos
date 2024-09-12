#ifndef ARCHIVOCATEGORIAS_H_INCLUDED
#define ARCHIVOCATEGORIAS_H_INCLUDED

class archivoTipoDeportes{
private:
    char nombre [30];

public:
    archivoTipoDeportes(const char *n){ strcpy (nombre,n);}

    int buscarTipo(int id);

    bool listarPorId();


    TipoDeDeporte leerRegistro(int pos){
    TipoDeDeporte tipoDeporte;    ///Instancia de objeto --> El objeto esta VACIO
    FILE *p;
    p= fopen(nombre,"rb"); ///Sin comillas nombre, xq es una variable que va a tener el nombre dentro de la variable.
        if(p==NULL) return tipoDeporte;
    fseek (p,sizeof tipoDeporte*pos,0);     ///File buscar !
    fread (&tipoDeporte,sizeof tipoDeporte, 1, p);
        fclose(p);
    return tipoDeporte;
    }
///Agregar registro
     bool agregarRegistro(TipoDeDeporte tipoDeporte){

    FILE *p;
    p= fopen(nombre,"ab");
        if(p==NULL) return false;
    int id;
    cout<<"INGRESE ID DE TIPO DE DEPORTE: "<<endl;
    cin>>id;
    if(buscarTipo(id)>=0){
        cout<<"EL ID YA EXISTE"<<endl;
        return false;
    }
    tipoDeporte.Cargar(id);
    int escribio= fwrite(&tipoDeporte,sizeof tipoDeporte, 1,p);
        fclose(p);
    return escribio;
    }
///Mostrar registros
    int mostrarRegistros(){
    TipoDeDeporte tip;
    bool bandera=false;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&tip,sizeof tip, 1,p)== 1){///Encontro un registro y me muestra el registro
        if (tip.get_estado()==false){
            bandera=true;
        }
          cout<<left;
        cout<<setw(8)<<tip.get_id();
        cout<<setw(30)<<tip.get_nombre();
        cout<<setw(3)<<tip.get_nivel();
        if(tip.get_estado()){
            cout<<"true"<<endl;
        }
        cout<<endl;

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
    return tam/sizeof(TipoDeDeporte); /// Nos devuelve la cantidad de registro del archivo, este es un entero (int).

    }


    bool bajaLogicaRegistro(){
    int id, pos;
    TipoDeDeporte tipoDeporte;
   // ArchivoEmpresa ae;
    char opc;
    cout << "Ingresar el ID del deporte a dar de baja ";
    cin >> id;
    ///Buscar si el jugador existe en el archivo
    pos= buscarTipo(id);///Recibo la posición del jugador si existe.
        if(pos == -1){
        cout << "No existe ese ID." << endl;
        return false;
        }
          if(pos == -2){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
        }
        tipoDeporte= leerRegistro(pos);  ///me devuelve el OBJETO completo de empresa enviandole la posición.
        cout << "EL registro a borrar: " << endl;
        tipoDeporte.Mostrar();
        cout<< endl;
        cout << "Esta seguro de borrar el registro?(S/N)";
        cin >> opc;
        if(opc == 'S' || opc== 's'){
            tipoDeporte.set_estado(false);
    bool escribio= sobreEscribirRegistro(tipoDeporte, pos);
        return escribio;
        }
        return false;
    }


 bool sobreEscribirRegistro(TipoDeDeporte tipoDeporte, int pos){//Registro que ya esta en el archivo, escribe de nuevo en la posicion que le manda por parametro

 FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        return false;
        }
    fseek(p,sizeof tipoDeporte*pos,0);
    bool escribio=fwrite(&tipoDeporte,sizeof tipoDeporte,1,p);
    fclose(p);
    return escribio;
 }


  bool ModificarNivelDeDificultad(){
 TipoDeDeporte tipoDeporte;
 int id,pos=0;
 ///buscar el registro a modificar
 cout<<"INGRESE EL ID DEL REGISTRO A MODIFICAR : ";
 cin>>id;
 ///leer si existe el registro
 pos=buscarTipo(id);
 if(pos==-1){
    cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
    return false;
 }
 tipoDeporte=leerRegistro(pos);

if(tipoDeporte.get_estado()==false){
    cout<<"EL ID INGRESADO YA ESTA DADO DE BAJA"<<endl;
    return false;
}
cout<<"EL REGISTRO A MODIFICAR EL NOMBRE ES : "<<endl;
tipoDeporte.Mostrar();
cout<< endl;
    int nivel;
    cout<<"INGRESE EL NUEVO NIVEL DE DIFICULTAD: "<<endl;
    nivel;
    tipoDeporte.set_nivel(nivel);
    bool aux=sobreEscribirRegistro(tipoDeporte,pos);
    return aux;
}
///COPIA DE SEGURIDAD

  bool copiaDeSeguridadTipoDeportes(){
    TipoDeDeporte tipoDeporte;
    FILE *p;
    p=fopen("deportes.bkp","wb");
    if(p==NULL){return false;}
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        tipoDeporte=leerRegistro(i);
        fwrite(&tipoDeporte,sizeof tipoDeporte,1,p);
    }

   fclose (p);
   return true;
}

///RESTAURAR ARCHIVOS
bool restaurarTipoDeportes() {
    FILE* pT;
    FILE* pBkp;

    pT = fopen("tipoDeportes.bkp", "rb");
    if (pT == NULL) {
        cout << "Error al abrir el archivo tipoDeportes.bkp." << endl;
        return false;
    }

    pBkp= fopen("tipoDeportes.dat", "wb");
    if (pBkp == NULL) {
        cout << "Error al abrir el archivo tipoDeportes.dat." << endl;
        fclose(pT);
        return false;
    }

    TipoDeDeporte tipoDeporte;
    while (fread(&tipoDeporte, sizeof(TipoDeDeporte), 1, pT) == 1) {
        if (tipoDeporte.get_estado()) {
            fwrite(&tipoDeporte, sizeof(TipoDeDeporte), 1, pBkp);
        }
    }

    fclose(pT);
    fclose(pBkp);
    return true;
}

bool datosInicioTipos() {
    FILE* pTipos;
    FILE* pTiposInicio;

    pTipos = fopen("tiposinicio.dat", "rb");
    if (pTipos== NULL) {
        cout << "Error al abrir el archivo deportesinicio.dat." << endl;
        return false;
    }

    pTiposInicio = fopen("tipoDeportes.dat", "wb");
    if (pTiposInicio == NULL) {
        cout << "Error al abrir el archivo deportes.dat." << endl;
        fclose(pTipos);
        return false;
    }

    TipoDeDeporte tipoDeporte;
    while (fread(&tipoDeporte, sizeof(TipoDeDeporte), 1, pTipos) == 1) {
        if (tipoDeporte.get_estado()) {
            fwrite(&tipoDeporte, sizeof(TipoDeDeporte), 1, pTiposInicio);
        }
    }

    fclose(pTipos);
    fclose(pTiposInicio);
    return true;
}

};

int archivoTipoDeportes::buscarTipo(int id){
TipoDeDeporte tipoDeporte;
int pos=0;

FILE *p;
    p= fopen(nombre, "rb");
    if(p==NULL){
        return -2;
        }
  int cantRegistros= contarRegistros();
  while(pos < cantRegistros){
      tipoDeporte= leerRegistro(pos);
    if( id == tipoDeporte.get_id()){
        fclose(p);
        return pos;
    }
    pos++;
  }
    fclose(p);
    return -1;
}

bool archivoTipoDeportes::listarPorId(){
TipoDeDeporte tipoDeporte;
 int id;
 cout<<"INGRESE ID QUE DESEA LISTAR: ";
 cin>>id;
int pos=buscarTipo(id);
 if(pos==-1){
    cout<<"NO EXISTE EL ID EN EL ARCHIVO"<<endl;
    return false;
 }

 tipoDeporte=leerRegistro(pos);
  if(id==tipoDeporte.get_id()){
        tipoDeporte.Mostrar();}

 return false;
 }

#endif // ARCHIVOCATEGORIAS_H_INCLUDED
