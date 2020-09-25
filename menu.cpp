#include <iostream>
using namespace std;
#include "ui.h"

#include "menu.h"
#include "usuario.h"

void menuPrincipal(){
    while(true){
        system ("cls");
        cout<<"MENU PRINCIPAL"<<endl;

        cout << "1 - USUARIOS" << endl;
        cout << "2 - ENTRETENIMIENTO" << endl;
        cout << "3 - REPORTES" << endl;
        cout << "4 - CONFIGURACIÓN" << endl;
        cout << "------------------" << endl;
        cout << "0 - SALIR DEL PROGRAMA" << endl;
        int pos;
        cin >> pos;

        switch(pos){
            case 1:
                menuParticipantes();
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 0:
                return ;
            break;
        }
    }
}

void menuParticipantes(){
    while(true){
       system ("cls");
        cout<<"MENU DE USUARIO"<<endl;

        cout << "1 - NUEVO USUARIO" << endl;
        cout << "2 - EDITAR USUARIO" << endl;
        cout << "3 - LISTAR USUARIO POR ID" << endl;
        cout << "4 - LISTAR TODOS LOS USUARIOS" << endl;
        cout << "5 - ELIMINAR USUARIO" << endl;
        cout << "----------------------" << endl;

        cout << "0 - VOLVER AL MENU PRINCIPAL" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                Participante reg;
                reg = cargar_participante();
                guardar_participante(reg);
                    cout << "Participante registrado.";


            break;
            case 2:
                modificar_participante();
            break;
            case 3:
                listar_participante_x_id();
            break;
            case 4:
                listar_participantes();
            break;
            case 5:
                baja_deportista();
            break;
            case 0:menuPrincipal();
                return;
            break;
        }
        cin.ignore();
       system ("pause");
    }
}

