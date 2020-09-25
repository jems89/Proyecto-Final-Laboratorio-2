#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include "fecha.h"

struct Participante{
    int codigo;
    char apellidos[50];
    char nombres[50];
    Fecha nac;
    float altura;
    float peso;
    char perfil;
    int apto;
    bool estado;
    FechaDeHoy actual ;
};

Participante cargar_participante();
bool modificar_participante();
void mostrar_participante(Participante);
Participante leer_participante(int);//me devuelve el la posicion
int cantidad_participantes();
int buscar_participante(int);
void listar_participantes();
bool guardar_participante(Participante);
bool guardar_participante(Participante, int);
void listar_participante_x_id();
bool baja_deportista();
struct usuario{

int id;
int id_usuario;
Fecha nac;
int actividad;
float calorias;
int tiempo;
bool estado;
};




#endif // PARTICIPANTE_H_INCLUDED
