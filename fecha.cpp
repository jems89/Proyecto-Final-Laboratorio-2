#include <iostream>
#include<ctime>
using namespace std;
#include "fecha.h"


Fecha cargar_fecha(){
    Fecha reg;
    cout << "Día: ";
    cin >> reg.dia;
    cout << "Mes: ";
    cin >> reg.mes;
    cout << "Año: ";
    cin >> reg.anio;
    return reg;
}
void mostrar_fecha(Fecha reg){
    cout << reg.dia << "/" << reg.mes << "/" << reg.anio << endl;
}

FechaDeHoy hoy(){
  time_t t;
  t=time(NULL);
struct tm *e;
  e=localtime(&t);
  FechaDeHoy aux;
  aux.dia=e->tm_mday;
  aux.mes=e->tm_mon+1;
  aux.anioo=e->tm_year + 1900;

 return aux;
}
void mostrar_FechaHoy(FechaDeHoy a){
cout<<a.dia<<"/"<<a.mes<<"/"<<a.anioo<<endl;
}

int calcular_edad(Fecha reg){
FechaDeHoy a = hoy();
int edad;
edad=a.anioo-reg.anio;
if((a.dia<reg.dia && a.mes==reg.mes)||(a.mes<reg.mes)){
edad--;

}
return edad;
}

/*{
    struct date hoy;
    getdate(&hoy);

    int anios = hoy.da_year - fecha.da_year;

    if(hoy.da_mon < fecha.da_mon)
       anios--;
    else if(hoy.da_mon == fecha.da_mon && hoy.da_day < fecha.da_day)
        anios--;

   return anios;
}

/*void main()
{
   struct date fecha;

   fecha.da_day = 31;
   fecha.da_mon = 10;
   fecha.da_year= 1980;

   printf("Tienes %d anios...", edad(fecha));

   getchar();
}*/

