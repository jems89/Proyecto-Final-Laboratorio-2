#include <iostream>
using namespace std;

#include"fecha.h"
#include "usuario.h"
#include"ctime"
const char *FILE_PARTICIPANTES = "deportista.dat";
Participante leer_participante(int pos){

    Participante reg;
    FILE *p = fopen(FILE_PARTICIPANTES, "rb");
    if (p == NULL){
        reg.codigo = 0;
        return reg;
    }
    fseek(p, pos * sizeof(Participante), SEEK_SET);
    fread(&reg, sizeof(Participante), 1, p);
    fclose(p);
    return reg;
}
int cantidad_participantes(){
    FILE *p = fopen(FILE_PARTICIPANTES, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END); // SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
    bytes = ftell(p);
    fclose(p);
    cant = bytes/sizeof(Participante);
    return cant;
}
void mostrar_participante(Participante reg){
    /*if(reg.estado==true)*/{
    cout << "Código    : " << reg.codigo << endl;
    cout << "Apellidos : " << reg.apellidos<< endl;
    cout << "Nombres   : " << reg.nombres << endl;
    cout << "Perfil de actividad    : " << reg.perfil << endl;
    cout<<"Altura : "<<reg.altura<<endl;
    cout<<"peso : "<<reg.peso<<endl;
    cout<<"apto medico : "<<reg.apto<<endl;
     cout << "Nacimiento: ";
    mostrar_fecha(reg.nac);
    cout<<"estado: "<<reg.estado<<" "<<endl;
}
}
int buscar_participante(int codigo_buscado){
    Participante reg;
    FILE *f;
    int pos=0;
    f = fopen("deportista.dat", "rb");
    if (f == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(Participante), 1, f)){
        if (codigo_buscado == reg.codigo){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}
Participante cargar_participante(){
    system ("cls");
    Participante reg;
    bool validado;
    while(!validado){
        cout << "Código ID : ";
        cin >>reg.codigo;
        if (!(reg.codigo >= 1000 && reg.codigo <= 9999)){
            validado = false;
            cout<<"Código de participante incorrecto.";
        }
        else if(buscar_participante(reg.codigo) >= 0){
            validado = false;
            cout<< "Código de participante repetido.";
        }
        else{
            validado = true;
        }
    };

///validar apellido

    cout << "Apellidos           : ";
    cin.ignore();
    cin.getline(reg.apellidos, 50);
    while(reg.apellidos[0]=='\0'){
    cout<<"  ///////POR FAVOR INGRESE SU APELLIDO ////"<<endl;
    system("pause");
    system("cls");
    cin.ignore();
    cin.getline(reg.apellidos, 50);}

//validar nombre

    cout << "Nombres             : ";
    cin.getline(reg.nombres, 50);
    while(reg.nombres[0]=='\0'){
    cout<<"  ///////POR FAVOR INGRESE SU NOMBRE ////"<<endl;
    system("pause");
    system("cls");
    cin.ignore();
    cin.getline(reg.nombres, 50);}
    ///validar perfil
    cout << "Perfil de actividad :";
    cin >> reg.perfil;
    while (reg.perfil != 'A'&&reg.perfil != 'a' && reg.perfil != 'B'&& reg.perfil != 'b'&& reg.perfil != 'C'&&reg.perfil != 'c'){
        cout <<"POR FAVOR INGRESAR UN PERFIL VALIDO ENTRE A Y C : " << endl;
    system("pause");
    system("cls");
        cin >> reg.perfil;
    }
    cout << "Fecha de nacimiento: ";
    reg.nac=cargar_fecha();
   /* cout<<"La fecha actual es  "<<endl;
    FechaDeHoy actual ;
    actual=hoy();*/
    /*mostrar_FechaHoy(hoy());*/


 /*cout<<"la edad es  "<<calcular_edad( reg.nac)<<endl;*/
while(!(calcular_edad(reg.nac)>=13)){
        cout <<"por favor reingrese nuevamente una edad valida "<<endl;
system("cls");
   cout << "Fecha de nacimiento: ";
    reg.nac=cargar_fecha();

}
    cout<<"altura              : ";
    cin>>reg.altura;
    while(reg.altura<=0){
        cout<<" NO PUEDE INGRESAR NUMERO NEGATIVO ///";
        cout<<"Ingrese nuevamente :";
        cin>>reg.altura;
    }
    cout<<"peso                : ";
    cin>>reg.peso;
    while(reg.peso<=0){
        cout<<" NO PUEDE INGRESAR NUMERO NEGATIVO /// ";
        cout<<"Ingrese nuevamente :";
        cin>>reg.peso;}
    cout<<"apto medico  solo 1 o 0        : ";
    cin>>reg.apto;
    while(!(reg.apto>=0 &&reg.apto<2)){
        cout<<" SOLO 1 o 0 ";
        cout<<"Ingrese nuevamente :";
        cin>>reg.apto;}



    reg.estado =true;

    return reg;
}
bool modificar_participante(){
   system ("cls");
    cout<<"MODIFICAR PARTICIPANTE"<<endl;

    int codigo, pos;
    cout << "POR FAVOR INGRESAR ID DEL SOLICITANTE";
    cin >> codigo;
    pos = buscar_participante(codigo);
    if (pos >= 0){
        cout << endl << "ESTE PARTICIPANTE SERA MODIFICADO " << endl;
        Participante reg = leer_participante(pos);
        mostrar_participante(reg);
        cout << endl;
        cout << "INGRESE SU PESO A MODIFICAR ";
        cin>>reg.peso;
        cout<<"INGRESE NUEVAMENTE SU PERFIL DE ACTIVIDAD : A, B o C ";
        cin>>reg.perfil;
        cout<<"INGRESE SU APTO MEDICO SI=1 NO=0 ";
        cin>>reg.apto;

        if (guardar_participante(reg, pos) == true){
            cout<<"Participante guardado correctamente.";
            return true;
        }
        else{
            cout<<"El participante no se guardó correctamente.";
            return true;

        }
    }
    else{
        cout<<"No existe el participante";
        return false;
    }
}
void listar_participante_x_id(){

    int codigo, pos;
    cout << "Código: ";
    cin >> codigo;
    pos = buscar_participante(codigo);
    if (pos >= 0){
        mostrar_participante(leer_participante(pos));
    }
    else{

        cout<<"No existe el participante";
        system ("cls");
    cout<<"Ingresar un codigo valido"<<endl;
        listar_participante_x_id();
    }
}
void listar_participantes(){

    int cant =  cantidad_participantes();
    for(int i = 0; i<cant; i++){
        Participante reg = leer_participante(i);
        mostrar_participante(reg);
        cout << endl;
    }
}
bool guardar_participante(Participante reg){
bool grabo;
    FILE *savee;
    savee = fopen("deportista.dat", "ab");
    if (savee == NULL){
        return false;
    }
    grabo=fwrite(&reg, sizeof(Participante),1,savee);
    fclose(savee);
return grabo;
}
bool guardar_participante(Participante reg, int pos){
    bool grabo;
    FILE *f;
    f = fopen(FILE_PARTICIPANTES, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(Participante), SEEK_SET);
    grabo = fwrite(&reg, sizeof(Participante), 1, f);
    fclose(f);
    return grabo;
}
bool baja_deportista(){
bool grabo= true;
int id,pos;
cout<<"INGRESE EL ID DEL DEPORTISTA QUE DESEA ELIMINAR";
cin>>id;
pos=buscar_participante(id);
if(pos!=-1){
    Participante reg;
    reg=leer_participante(pos);
    reg.estado=false;
    grabo=guardar_participante(reg,pos);

}
else{grabo=false;}

return grabo;

}
/*Participante  oontar los registros_Logica(){
    cls();
    FILE *p
    participante reg;
    int cont=0;
    p=fopen("alumno.dat","rb+")
    if(p==null){return -1;}
        fclose(p);
        return cont;
        fseek(p.0,2);
        cantbytes=ftell(p);
        fclose(p);
        cantbytes/sizeof(participantes);
        /////////////////////////
    int codigo, pos;
    bool validado;
    do{
        cout << "Código   : ";
        cin >> codigo;
        if (!(codigo >= 1000 && codigo <= 9999)){
            validado = false;
            cout<<"Código de participante incorrecto.";
        }
        else if(buscar_participante(codigo) >= 0){
            validado = false;
            cout<< "Código de participante repetido.";
        }
        else{
            validado = true;
        }
    }while(!validado);
    // Fin de la validación de código
    cout << "Apellidos: ";
    cin.ignore();
    cin.getline(ingreso.apellidos, 50);
    cout << "Nombres  : ";
    cin.getline(ingreso.nombres, 50);
    cout << "Género   : ";
    cin >> ingreso.genero;
    while (ingreso.genero != 'M' && ingreso.genero != 'F' && ingreso.genero != 'X'){
        cout << endl <<  "> Género   : " << ingreso.genero << endl;
        cin >> ingreso.genero;
    }
    cout << "Fecha de nacimiento: ";
    cin >> ingreso.nac.dia;
    cin >> ingreso.nac.mes;
    cin >> ingreso.nac.anio;

    ingreso.estado = true;

    return a;*/

