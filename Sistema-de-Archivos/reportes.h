
#ifndef REPORTES2_H_INCLUDED
#define REPORTES2_H_INCLUDED



class Deportes2{
private:
    int id;
    char nombre[30];
    int tipo; //Número entre 1 y  21
public:
    void set_id (int d){id=d;}
    void set_nombre (const char *n){strcpy(nombre,n); }
    void set_tipo (int t){tipo=t;}

    void Mostrar(){
    cout<<"ID DE DEPORTE: "<<id<<endl;
    cout<<"NOMBRE DE DEPORTE: "<<nombre<<endl;
    cout<<"TIPO : "<<tipo<<endl;}

};

class archivosDeportes2{
    private:
    char nombre [30];

public:
    archivosDeportes2 (const char *n){ strcpy (nombre,n);}

    archivoDeportes2(const char *n){
        strcpy(nombre, n);
    }
    Deportes2 leerRegistro(int pos){
        Deportes2 reg;

        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deportes2);
    }
    bool grabarRegistro(Deportes2 reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }


};

void Punto1();
void Punto2();





void menuReportes(){

 int opc=0;

    while(true){
        system("cls");
        cout << "************REPORTES**************" << endl;
        cout << "1. PUNTO 1 " << endl;
        cout << "2. PUNTO 2 " << endl;
        cout << "0. SALIR " << endl;
        cout << "*****************************" << endl;
        cout << "INGRESE OPCION" << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                Punto1();
                system("pause");
                break;
            case 2:
                Punto2();
                system("pause");
                  break;

            case 0:
                return ;
                break;

        }

    }
}

void Punto1(){
///Generar un archivo con los deportes que tengan un nivel de dificultad 2.

///Cada registro debe tener el ID de deporte, el nombre del deporte y el tipo de deporte
archivoDeportes archD ("deportes.dat");
archivoTipoDeportes archTipo ("tipodeportes.dat");
archivosDeportes2  archDeportes2 ("tipo2deportes.dat");

Deporte deporte;
TipoDeDeporte tipodeporte;
Deportes2 obj;

int cantRegD=archD.contarRegistros();
int cantRegT=archTipo.contarRegistros();

bool encontro=false;

for(int i=0;i<cantRegD;i++){
    deporte=archD.leerRegistro(i);
    for(int j=0;j<cantRegT;j++){
        tipodeporte=archTipo.leerRegistro(j);
        if(deporte.get_estado()  && tipodeporte.get_estado()){
        if(deporte.get_tipo()==tipodeporte.get_id()){
            if(tipodeporte.get_nivel()==2){
                obj.set_id(deporte.get_id());
                obj.set_nombre(deporte.get_nombre());
                obj.set_tipo(deporte.get_tipo());
                encontro=archDeportes2.grabarRegistro(obj);
                obj.Mostrar();
                cout<<endl;
            }
        }
        }
    }
}
if(encontro)cout<<"se grabaron los registros correctamente"<<endl;
else cout<<"no se encontraron registros para grabar"<<endl;


   }


void Punto2(){
///Informar el/los claustro/s con más de 15 de jugadores
archivoJugadores archJ("jugadores.dat");
Jugador jugador;
int cantRegJ=archJ.contarRegistros();
int claustro[4]={0};
bool encontro=false;


for(int i=0;i<cantRegJ;i++){
    jugador=archJ.leerRegistro(i);
    if(jugador.get_estado()){
        claustro[jugador.get_claustro() - 1]++;
    }
}


for(int i=0;i<4;i++){
    if(claustro[i]>15){
        encontro=true;
        cout << "El claustro "<<i+1<< " tiene más de 15 jugadores."<< endl;
    }


}
if(!encontro) cout<<"no se encontraron claustros con mas de 15 jugadores "<<endl;
}






#endif // REPORTES2_H_INCLUDED
