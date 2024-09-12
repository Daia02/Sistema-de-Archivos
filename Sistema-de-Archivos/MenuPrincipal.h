#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

#include "rlutil.h"

#include "reportes.h"

///PROTOTIPOS

void menuPrincipal();
void showItem(const char *text,int posx,int posy, bool selected);

void menuJugadores();
void menuJugadores(const char *text,int posx,int posy, bool selected);

void menuDeportes();
void menuDeportes(const char *text,int posx,int posy, bool selected);

void menuEquipos();
void menuEquipos(const char *text,int posx,int posy, bool selected);

void menuTipoDeportes();
void menuTipoDeportes(const char *text,int posx,int posy, bool selected);

void menuConfiguracion();
void menuConfiguracion(const char *text,int posx,int posy, bool selected);

///DESARROLLO DE FUNCIONES


void showItem(const char *text,int posx,int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx -2,posy);
    cout<<(char) 16 <<" "<<text<<endl;
}
else {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx -2,posy);
    cout<<" "<<text<<" "<<endl;
}

rlutil::locate(posx,posy);
rlutil::setBackgroundColor(rlutil::BLACK);

}



void menuPrincipal(){

 rlutil::cls();
 int opc=0,y=0;
 rlutil::setBackgroundColor(rlutil::BLACK);
 rlutil::setColor(rlutil::WHITE);
 rlutil::hidecursor();


    while(true){
        rlutil::locate(45,10);
        cout << "   MENU PRINCIPAL    " << endl;
        showItem("MENU JUGADORES",45,11,y==0);
        showItem("MENU DEPORTES",45,12,y==1);
        showItem("MENU EQUIPOS",45,13,y==2);
        showItem("MENU TIPO DE DEPORTES ",45,14,y==3);
        showItem("REPORTES ",45,15,y==04);
        showItem("CONFIGURACION ",45,16,y==5);
        showItem("SALIR ",45,17,y==6);


        switch(rlutil::getkey()){
            case 14:///up

                y--;
                if(y<0) y=0;
                break;
            case 15:///down

                y++;
                if(y>6) y=6;

                  break;
            case 1:///ENTER
                switch(y){
            case 0:
                menuJugadores();
                system("pause");
                system("cls");
                break;
            case 1:
                menuDeportes();
                system("pause");
                system("cls");
                break;
            case 2:
                menuEquipos();
                system("pause");
                system("cls");
                break;
            case 3:
                menuTipoDeportes();
                system("pause");
                system("cls");
                break;
            case 4:
                menuReportes();
                system("pause");
                system("cls");
                break;
            case 5:
                menuConfiguracion();
                system("pause");
                system("cls");
                break;
            case 6:
                exit(-1);
                break;
                }
                break;
        }

    }
}



void menuJugadores(const char *text,int posx,int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx -2,posy);
    cout<<(char) 16 <<" "<<text<<endl;
}
else {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx -2,posy);
    cout<<" "<<text<<" "<<endl;
}

rlutil::locate(posx,posy);
rlutil::setBackgroundColor(rlutil::BLACK);

}



void menuJugadores(){

 rlutil::cls();
 int opc=0,y=0;
 rlutil::setBackgroundColor(rlutil::BLACK);
 rlutil::setColor(rlutil::WHITE);
 rlutil::hidecursor();

 Jugador jugador;
 archivoJugadores obj("jugadores.dat");
 bool agrego,modifico,borro;


    while(true){

        rlutil::locate(45,10);
        cout << "    MENU JUGADORES     " << endl;
        menuJugadores("AGREGAR JUGADOR ",45,11,y==0);
        menuJugadores("LISTAR JUGADOR POR DNI ",45,12,y==1);
        menuJugadores("LISTAR TODOS LOS JUGADORES ",45,13,y==2);
        menuJugadores("MODIFICAR FECHA DE INSCRIPCION  ",45,14,y==3);
        menuJugadores("ELIMINAR REGISTRO DE JUGADOR ",45,15,y==04);
        menuJugadores("VOLVER A MENU PRINCIPAL ",45,16,y==5);


        switch(rlutil::getkey()){
            case 14:///up

                y--;
                if(y<0) y=0;
                break;
            case 15:///down

                y++;
                if(y>5) y=5;

                  break;
            case 1:///ENTER
                switch(y){
            case 0:
                system("cls");
                agrego=obj.agregarRegistro(jugador);
                if(agrego)cout<<"SE AGREGO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO "<<endl;
                system("pause");
                system("cls");

                break;
            case 1:
                system("cls");
                obj.ListarporDni();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                obj.mostrarRegistros();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                modifico=obj.ModificarFecha();
                if(modifico)cout<<"SE MODIFICO LA FECHA CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO MODIFICAR LA FECHA "<<endl;
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                borro=obj.bajaLogicaRegistro();
                if(modifico)cout<<"SE ELIMINO REGISTRO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO ELIMINAR EL REGISTRO"<<endl;
                system("pause");
                system("cls");
                break;
            case 5:
                menuPrincipal();
                break;
                }
                break;
        }

    }
}




void menuDeportes(const char *text,int posx,int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx -2,posy);
    cout<<(char) 16 <<" "<<text<<endl;
}
else {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx -2,posy);
    cout<<" "<<text<<" "<<endl;
}

rlutil::locate(posx,posy);
rlutil::setBackgroundColor(rlutil::BLACK);

}



void menuDeportes(){

 rlutil::cls();
 int opc=0,y=0;
 rlutil::setBackgroundColor(rlutil::BLACK);
 rlutil::setColor(rlutil::WHITE);
 rlutil::hidecursor();

 Deporte deporte;
 archivoDeportes obj("deportes.dat");
 bool agrego,modifico,borro;


    while(true){

        rlutil::locate(45,10);
        cout << "   MENU DEPORTES   " << endl;
        menuDeportes("AGREGAR DEPORTE ",45,11,y==0);
        menuDeportes("LISTAR DEPORTE POR ID ",45,12,y==1);
        menuDeportes("LISTAR TODO ",45,13,y==2);
        menuDeportes("MODIFICAR ANIO DE ORIGEN ",45,14,y==3);
        menuDeportes("ELIMINAR REGISTRO DE DEPORTE ",45,15,y==04);
        menuDeportes("VOLVER A MENU PRINCIPAL ",45,16,y==5);


        switch(rlutil::getkey()){
            case 14:///up

                y--;
                if(y<0) y=0;
                break;
            case 15:///down

                y++;
                if(y>5) y=5;

                  break;
            case 1:///ENTER
                switch(y){
            case 0:
                system("cls");
                agrego=obj.agregarRegistro(deporte);
                if(agrego)cout<<"SE AGREGO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO "<<endl;
                system("pause");
                 system("cls");

                break;
            case 1:
                system("cls");
                obj.listarPorId();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                cout<<left;
                cout << setw(6)  << "ID  ";
                cout << setw(30) << "NOMBRE  ";
                cout << setw(6) << "TIPO ";
                cout << setw(8)  << "ANIO"<<endl;

                cout<<"--------------------------------------------------"<<endl;

                obj.mostrarRegistros();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                modifico=obj.ModificarAnio();
                if(modifico)cout<<"SE MODIFICO LA FECHA CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO MODIFICAR LA FECHA "<<endl;
                system("pause");
                 system("cls");
                break;
            case 4:
                system("cls");
                borro=obj.bajaLogicaRegistro();
                if(borro)cout<<"SE ELIMINO REGISTRO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO ELIMINAR EL REGISTRO"<<endl;
                system("pause");
                 system("cls");
                break;
            case 5:
                menuPrincipal();
                break;
                }
                break;
        }

    }
}




void menuEquipos(const char *text,int posx,int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx -2,posy);
    cout<<(char) 16 <<" "<<text<<endl;
}
else {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx -2,posy);
    cout<<" "<<text<<" "<<endl;
}

rlutil::locate(posx,posy);
rlutil::setBackgroundColor(rlutil::BLACK);

}



void menuEquipos(){

 rlutil::cls();
 int opc=0,y=0;
 rlutil::setBackgroundColor(rlutil::BLACK);
 rlutil::setColor(rlutil::WHITE);
 rlutil::hidecursor();

 Equipo equipo;
 archivoEquipos obj("equipos.dat");
 bool agrego,modifico,borro;


    while(true){

        rlutil::locate(45,10);
        cout << "   MENU EQUIPOS   " << endl;
        menuEquipos("AGREGAR EQUIPO ",45,11,y==0);
        menuEquipos("LISTAR EQUIPO POR ID ",45,12,y==1);
        menuEquipos("LISTAR TODO ",45,13,y==2);
        menuEquipos("MODIFICAR NOMBRE ",45,14,y==3);
        menuEquipos("ELIMINAR REGISTRO DE EQUIPO ",45,15,y==04);
        menuEquipos("VOLVER A MENU PRINCIPAL ",45,16,y==5);


        switch(rlutil::getkey()){
            case 14:///up

                y--;
                if(y<0) y=0;
                break;
            case 15:///down

                y++;
                if(y>5) y=5;

                  break;
            case 1:///ENTER
                switch(y){
            case 0:
                system("cls");
                agrego=obj.agregarRegistro(equipo);
                if(agrego)cout<<"SE AGREGO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO "<<endl;
                system("pause");
                 system("cls");

                break;
            case 1:
                system("cls");
                obj.listarPorId();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                cout<<left;
                cout << setw(6)  << "ID  ";
                cout << setw(30) << "NOMBRE  ";
                cout << setw(2) << "NIVEL ";
                cout << setw(8)  << "ESTADO "<<endl;

                cout<<"--------------------------------------------------"<<endl;
                obj.mostrarRegistros();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                modifico=obj.ModificarNombre();
                if(modifico)cout<<"SE MODIFICO  CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO MODIFICAR  "<<endl;
                system("pause");
                 system("cls");
                break;
            case 4:
                system("cls");
                borro=obj.bajaLogicaRegistro();
                if(modifico)cout<<"SE ELIMINO REGISTRO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO ELIMINAR EL REGISTRO"<<endl;
                system("pause");
                 system("cls");
                break;
            case 5:
                menuPrincipal();
                break;
                }
                break;
        }

    }
}



void menuTipoDeportes(const char *text,int posx,int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx -2,posy);
    cout<<(char) 16 <<" "<<text<<endl;
}
else {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx -2,posy);
    cout<<" "<<text<<" "<<endl;
}

rlutil::locate(posx,posy);
rlutil::setBackgroundColor(rlutil::BLACK);

}



void menuTipoDeportes(){

 rlutil::cls();
 int opc=0,y=0;
 rlutil::setBackgroundColor(rlutil::BLACK);
 rlutil::setColor(rlutil::WHITE);
 rlutil::hidecursor();

 TipoDeDeporte tipoDeporte;
 archivoTipoDeportes obj("tipoDeportes.dat");
 bool agrego,modifico,borro;


    while(true){

        rlutil::locate(45,10);
        cout << "     MENU TIPO DEPORTES      " << endl;
        menuTipoDeportes("AGREGAR TIPO ",45,11,y==0);
        menuTipoDeportes("LISTAR  POR ID ",45,12,y==1);
        menuTipoDeportes("LISTAR TODO ",45,13,y==2);
        menuTipoDeportes("MODIFICAR NIVEL DE DIFICULTAD ",45,14,y==3);
        menuTipoDeportes("ELIMINAR REGISTRO  ",45,15,y==04);
        menuTipoDeportes("VOLVER A MENU PRINCIPAL ",45,16,y==5);


        switch(rlutil::getkey()){
            case 14:///up

                y--;
                if(y<0) y=0;
                break;
            case 15:///down

                y++;
                if(y>5) y=5;

                  break;
            case 1:///ENTER
                switch(y){
            case 0:
                system("cls");
                agrego=obj.agregarRegistro(tipoDeporte);
                if(agrego)cout<<"SE AGREGO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO "<<endl;
                system("pause");
                 system("cls");

                break;
            case 1:
                system("cls");
                obj.listarPorId();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                   cout<<left;
                cout << setw(6)  << "ID  ";
                cout << setw(30) << "NOMBRE  ";
                cout << setw(2) << "NIVEL ";
                cout << setw(8)  << "ESTADO "<<endl;

                cout<<"--------------------------------------------------"<<endl;
                obj.mostrarRegistros();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                modifico=obj.ModificarNivelDeDificultad();
                if(modifico)cout<<"SE MODIFICO  CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO MODIFICAR "<<endl;
                system("pause");
                 system("cls");
                break;
            case 4:
                system("cls");
                borro=obj.bajaLogicaRegistro();
                if(modifico)cout<<"SE ELIMINO REGISTRO CORRECTAMENTE "<<endl;
                else cout<<"NO SE PUDO ELIMINAR EL REGISTRO"<<endl;
                system("pause");
                 system("cls");
                break;
            case 5:
                menuPrincipal();
                break;
                }
                break;
        }

    }
}




void menuConfiguracion(const char *text,int posx,int posy, bool selected){

if(selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::locate(posx -2,posy);
    cout<<(char) 16 <<" "<<text<<endl;
}
else {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::locate(posx -2,posy);
    cout<<" "<<text<<" "<<endl;
}

rlutil::locate(posx,posy);
rlutil::setBackgroundColor(rlutil::BLACK);

}



void menuConfiguracion(){

 rlutil::cls();
 int opc=0,y=0;
 rlutil::setBackgroundColor(rlutil::BLACK);
 rlutil::setColor(rlutil::WHITE);
 rlutil::hidecursor();

archivoDeportes archD("deportes.dat");
 archivoJugadores archJ("jugadores.dat");
 archivoEquipos archE("equipos.dat");
 archivoTipoDeportes archT("tipoDeportes.dat");


 bool agrego,copiarD,copiarJ,copiarE,copiarT,restaurarD,restaurarJ,restaurarE,restaurarT;
 bool establecerD,establecerJ,establecerE,establecerT;


    while(true){

        rlutil::locate(45,10);
        cout << "         MENU CONFIGURACION       " << endl;
        menuConfiguracion ("COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES ",45,11,y==0);
        menuConfiguracion ("COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES ",45,12,y==1);
        menuConfiguracion ("COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS ",45,13,y==2);
        menuConfiguracion ("COPIA DE SEGURIDAD DEL ARCHIVO TIPO DE DEPORTES ",45,14,y==3);
        menuConfiguracion ("RESTAURAR EL ARCHIVO DE JUGADORES ",45,15,y==4);
        menuConfiguracion ("RESTAURAR EL ARCHIVO DE DEPORTES ",45,16,y==5);
        menuConfiguracion ("RESTAURAR EL ARCHIVO DE EQUIPOS ",45,17,y==6);
        menuConfiguracion ("RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES ",45,18,y==7);
        menuConfiguracion ("ESTABLECER DATOS DE INICIO  ",45,19,y==8);
        menuConfiguracion("VOLVER A MENU PRINCIPAL ",45,20,y==9);


        switch(rlutil::getkey()){
            case 14:///up

                y--;
                if(y<0) y=0;
                break;
            case 15:///down

                y++;
                if(y>9) y=9;

                  break;
            case 1:///ENTER
                switch(y){
            case 0:
                system("cls");
                copiarJ=archJ.copiaDeSeguridadJugadores();
                if(copiarJ)cout<<"SE REALIZO CORRECTAMENTE  LA COPIA DE SEGURIDAD DE JUGADORES "<<endl;
                else cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD "<<endl;
                system("pause");
                system("cls");
                break;
            case 1:
                system("cls");
                 copiarD=archD.copiaDeSeguridadDeportes();
                 if(copiarD)cout<<"SE REALIZO CORRECTAMENTE LA COPIA DE SEGURIDAD DE DEPORTES "<<endl;
                else cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD "<<endl;

                system("pause");
                system("cls");
                  break;
             case 2:
                 system("cls");
                 copiarE=archE.copiaDeSeguridadEquipos();
                 if(copiarE)cout<<"SE REALIZO CORRECTAMENTE LA COPIA DE SEGURIDAD DE EQUIPOS "<<endl;
                else cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD "<<endl;

                system("pause");
                system("cls");
                  break;
            case 3:
                system("cls");
                 copiarT=archT.copiaDeSeguridadTipoDeportes();
                 if(copiarT)cout<<"SE REALIZO CORRECTAMENTE LA COPIA DE SEGURIDAD DE EQUIPOS "<<endl;
                else cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD "<<endl;

                system("pause");
                system("cls");
                  break;

            case 4:
                system("cls");
                 restaurarE=archE.restaurarEquipos();
                  if(restaurarE)cout<<"ARCHIVOS EQUIPOS RESTAURADOS CORRECTAMENTE "<<endl;
                  else cout<<"ERROR AL RESTAURAR LOS ARCHIVOS EQUIPOS "<<endl;
                system ("pause");
                system("cls");
                break;

            case 5:
                system("cls");
                 restaurarJ=archJ.restaurarJugadores();
                 if(restaurarJ)cout<<"ARCHIVOS JUGADORES RESTAURADOS CORRECTAMENTE "<<endl;
                 else cout<<"ERROR AL RESTAURAR LOS ARCHIVOS JUGADORES "<<endl;

                  system("pause");
                  system("cls");
                break;
            case 6:
                system("cls");
                restaurarT=archT.restaurarTipoDeportes();
                if(restaurarT)cout<<"ARCHIVOS TIPO DE DEPORTES RESTAURADOS CORRECTAMENTE "<<endl;
                else cout<<"ERROR AL RESTAURAR LOS ARCHIVOS TIPO DE DEPORTES "<<endl;

                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                restaurarE=archE.restaurarEquipos();
                if(restaurarE)cout<<"ARCHIVOS TIPO DE DEPORTES RESTAURADOS CORRECTAMENTE "<<endl;
                else cout<<"ERROR AL RESTAURAR LOS ARCHIVOS TIPO DE DEPORTES "<<endl;

                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                establecerJ=archJ.datosInicioJugadores();
                if(establecerJ)cout<<"ARCHIVOS JUGADORES RESTABLECIDOS CORRECTAMENTE "<<endl;
                else cout<<"ERROR AL RESTABLECER LOS ARCHIVOS DE JUGADORES "<<endl;

                establecerD=archD.datosInicioDeportes();
                if(establecerD)cout<<"ARCHIVOS DEPORTES RESTABLECIDOS CORRECTAMENTE "<<endl;
                else cout<<"ERROR AL RESTABLECER LOS ARCHIVOS DEPORTES "<<endl;

                establecerE=archE.datosInicioEquipos();
                if(establecerE)cout<<"ARCHIVOS EQUIPOS RESTABLECIDOS CORRECTAMENTE "<<endl;
                else cout<<"ERROR AL RESTAURAR RESTABLECER LOS ARCHIVOS EQUIPOS "<<endl;

                establecerT=archT.datosInicioTipos();
                if(establecerT)cout<<"ARCHIVOS TIPOS DE DEPORTES RESTABLECIDOS CORRECTAMENTE "<<endl;
                else cout<<"ERRORR AL RESTABLECER LOS ARCHIVOS TIPOS DE DEPORTES "<<endl;


                system("pause");
                system("cls");
                break;
            case 9:
                menuPrincipal() ;
                break;

        }

                break;
        }

    }
}

#endif // MENUPRINCIPAL_H_INCLUDED

