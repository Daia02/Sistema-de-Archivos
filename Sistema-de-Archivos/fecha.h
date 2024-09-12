
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int dia,mes,anio;
    int diaAct, mesAct, anioAct;

public:
    ///CONSTRUCTOR PARA SETTEAR FECHA ACTUAL, SOLO SE USARA PARA VALIDACIONES
    Fecha(){
    //NOS DA LA HORA
  time_t tiempo_actual = time(nullptr);

  // LIBRERIA CTIME CONVIERTE LA HORA A FECHA LEGIBLE
  tm* fecha_hora = localtime(&tiempo_actual);

  // GUARDAMOS DIA MES Y ANIO EN VARIABLES
   diaAct = fecha_hora->tm_mday;
   mesAct = fecha_hora->tm_mon + 1; // tm_mon empieza en 0
   anioAct = fecha_hora->tm_year + 1900; // tm_year cuenta desde 1900
    }

    ///METODOS
    void Cargar();
    void Mostrar();
    bool Bisiesto(int);
    ///GETS Y SETS


    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    int getDiaAct(){return diaAct;}
    int getMesAct(){return mesAct;}
    int getAnioAct(){return anioAct;}

};

 void Fecha::Cargar(){
    bool flag;
    do{
    flag=true;
    cout<<"INGRESAR DIA: "<<endl;
    cin>>dia;
    if(dia<0||dia>31){
        flag=false;
    }

    cout<<"INGRESAR MES: "<<endl;
    cin>>mes;
    if(mes<0||mes>12){
        flag=false;
    }
    cout<<"INGRESAR ANIO: "<<endl;
    cin>>anio;
    if(anio<1900||anio>anioAct){
        flag=false;
    }

    if((dia>30)&&(mes==4||mes==6||mes==9||mes==11)){
        flag=false;
    }

    if((dia>29&&mes==2&&Bisiesto(anio)==true) || (dia >28&&mes==2&&Bisiesto(anio)==false)){
        flag=false;
    }
    if(anio>=anioAct&&mes>=mesAct&&dia>diaAct){
        flag=false;
    }

    if(anio>=anioAct&&mes>mesAct){
            flag=false;
    }

    if(anio>anioAct){
        flag=false;
    }

    if(!flag){
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"FECHA INVALIDA, INGRESAR FECHA IGUAL O ANTERIOR A LA ACTUAL: ";
    cout<<diaAct<<"/"<<mesAct<<"/"<<anioAct<<"/"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<endl;
    }
}while(!flag);
setDia(dia);
setMes(mes);
setAnio(anio);
}

bool Fecha::Bisiesto(int anio){
    if((anio%100==0) && (anio%400==0)){
        return true;
    }else if(anio%4==0){
        return true;
    }else{
        return false;
    }
}

void Fecha::Mostrar(){
cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


#endif // FECHA_H_INCLUDED
