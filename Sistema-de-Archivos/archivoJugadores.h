#ifndef ARCHIVOJUGADORES_H_INCLUDED
#define ARCHIVOJUGADORES_H_INCLUDED



class archivoJugadores {
private:
    char nombre [30];

public:
    archivoJugadores (const char *n){ strcpy (nombre,n);}
    int buscarJugador(int dni);

    ///Leer/listar registro
    Jugador leerRegistro(int pos){
    Jugador jugador;    ///Instancia de objeto --> El objeto esta VACIO
    FILE *p;
    p= fopen(nombre,"rb"); ///Sin comillas nombre, xq es una variable que va a tener el nombre dentro de la variable.
        if(p==NULL) return jugador;
    fseek (p,sizeof jugador*pos,0);     ///File buscar !
    fread (&jugador,sizeof jugador, 1, p);
        fclose(p);
    return jugador;
    }
///Agregar registro
    bool agregarRegistro(Jugador jugador){
    Jugador obj;
    FILE *p;
    p= fopen(nombre,"ab");
        if(p==NULL) return false;
    int dni;
    cout<<"INGRESE DNI: "<<endl;
    cin>>dni;

  if (buscarJugador(dni) >= 0) {
    do {
        rlutil::setColor(rlutil::RED);
        cout << "EL DNI YA EXISTE" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "POR FAVOR, INTENTELO DE NUEVO." << endl;
        cout << "INGRESE DNI: ";
        cin >> dni;
    } while (buscarJugador(dni) >= 0);
}
    jugador.Cargar(dni);
    int escribio= fwrite(&jugador,sizeof jugador, 1,p);
        fclose(p);
    return escribio;
    }
///Mostrar registros
    int mostrarRegistros(){
    Jugador jugador;
    bool bandera=false;
    FILE *p;
    p= fopen(nombre,"rb");
        if(p==NULL) return -1;
    while(fread(&jugador,sizeof jugador, 1,p)== 1){///Encontro un registro y me muestra el registro
        if (jugador.get_estado()==false){
            bandera=true;
        }
        jugador.Mostrar();

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
    return tam/sizeof(Jugador); /// Nos devuelve la cantidad de registro del archivo, este es un entero (int).

    }


///borrar registro
    bool bajaLogicaRegistro(){
    int dni, pos;
    Jugador jugador;
   // ArchivoEmpresa ae;
    char opc;
    cout << "Ingresar el dni del jugador a dar de baja ";
    cin >> dni;
    ///Buscar si el jugador existe en el archivo
    pos= buscarJugador(dni);///Recibo la posición del jugador si existe.
        if(pos == -1){
        cout << "No existe ese JUGADOR." << endl;
        return false;
        }
          if(pos == -2){
        cout << "No se pudo abrir el archivo" << endl;
        return false;
        }
        jugador= leerRegistro(pos);  ///me devuelve el OBJETO completo de empresa enviandole la posición.
        cout << "EL registro a borrar: " << endl;
        jugador.Mostrar();
        cout<< endl;
        cout << "Esta seguro de borrar el registro?(S/N)";
        cin >> opc;
        if(opc == 'S' || opc== 's'){
            jugador.set_estado(false);
    bool escribio= sobreEscribirRegistro(jugador, pos);

        return escribio;
        }
        return false;

    }





 bool sobreEscribirRegistro(Jugador jugador, int pos){//Registro que ya esta en el archivo, escribe de nuevo en la posicion que le manda por parametro

 FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL){
        return false;
        }
    fseek(p,sizeof jugador*pos,0);
    bool escribio=fwrite(&jugador,sizeof jugador,1,p);
    fclose(p);
    return escribio;
 }



 bool ModificarFecha(){
 Jugador jugador;
 int dni,pos;
 ///buscar el registro a modificar
 cout<<"INGRESE EL DNI DEL REGISTRO A MODIFICAR : ";
 cin>>dni;
 ///leer si existe el registro
 pos=buscarJugador(dni);
 if(pos==-1){
    cout<<"NO EXISTE EL DNI EN EL ARCHIVO"<<endl;
    return false;
 }
 jugador=leerRegistro(pos);
 ///cambiar la fecha del registro
 Fecha aux;
 aux.Cargar();
 jugador.set_fecha(aux);
 ///sobreescribir el registro
 return sobreEscribirRegistro(jugador,pos);
 }

bool ListarporDni();
///COPIA DE SEGURIDAD JUGADORES
bool copiaDeSeguridadJugadores(){
    Jugador jugador;
    FILE *p;
    p=fopen("jugadores.bkp","wb");
    if(p==NULL){return false ;}
    int cantReg=contarRegistros();
    for(int i=0;i<cantReg;i++){
        jugador=leerRegistro(i);
        fwrite(&jugador,sizeof jugador,1,p);
    }
   fclose (p);
   return true;

}

///restaurar archivos
bool restaurarJugadores() {
    FILE* pJ;
    FILE* pBkp;

    pJ = fopen("jugadores.bkp", "rb");
    if (pJ == NULL) {
        cout << "Error al abrir el archivo jugadores.bkp" << endl;
        return false;
    }

    pBkp= fopen("jugadores.dat", "wb");
    if (pBkp == NULL) {
        cout << "Error al abrir el archivo jugadores.dat." << endl;
        fclose(pJ);
        return false;
    }

    Jugador jugador;
    while (fread(&jugador, sizeof(Jugador), 1, pJ) == 1) {
        if (jugador.get_estado()) {
            fwrite(&jugador, sizeof(Jugador), 1, pBkp);
        }
    }

    fclose(pJ);
    fclose(pBkp);
    return true;
}


bool datosInicioJugadores() {
    FILE* pJugadores;
    FILE* pJugadoresinicio;

    pJugadores = fopen("jugadoresinicio.dat", "rb");
    if (pJugadores == NULL) {
        cout << "Error al abrir el archivo jugadoresinicio.dat." << endl;
        return false;
    }

    pJugadoresinicio = fopen("jugadores.dat", "wb");
    if (pJugadoresinicio == NULL) {
        cout << "Error al abrir el archivo jugadores.dat." << endl;
        fclose(pJugadores);
        return false;
    }

    Jugador jugador;
    while (fread(&jugador, sizeof(Jugador), 1, pJugadores) == 1) {
        if (jugador.get_estado()) {
            fwrite(&jugador, sizeof(Jugador), 1, pJugadoresinicio);
        }
    }

    fclose(pJugadores);
    fclose(pJugadoresinicio);
    return true;
}

};

int archivoJugadores::buscarJugador(int dni){
Jugador jugador;
int pos=0;

FILE *p;
    p= fopen(nombre, "rb");
    if(p==NULL){
        return -2;
        }
  int cantRegistros= contarRegistros();
  while(pos < cantRegistros){
      jugador= leerRegistro(pos);
    if(jugador.get_dni()==dni){
        fclose(p);
        return pos;
    }
    pos++;
  }
    fclose(p);
    return -1;
}


bool archivoJugadores::ListarporDni(){
Jugador ju;
 int dni;
 cout<<"INGRESE DNI QUE DESEA LISTAR: ";
 cin>>dni;
int pos=buscarJugador(dni);
 if(pos==-1){
    cout<<"NO EXISTE EL DNI EN EL ARCHIVO"<<endl;
    return false;
 }

 ju=leerRegistro(pos);
  if(dni==ju.get_dni()){
        ju.Mostrar();}

 return false;


 }






#endif // ARCHIVOJUGADORES_H_INCLUDED

