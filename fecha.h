#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


struct Fecha{
  int dia, mes, anio;
};
int calcular_edad(Fecha);

void mostrar_fecha(Fecha);
Fecha cargar_fecha();

///ahora prototipo de la facha actual

struct FechaDeHoy{
int anioo,mes,dia;
};
FechaDeHoy hoy();
void mostrar_FechaHoy(FechaDeHoy);



#endif // FECHA_H_INCLUDED
