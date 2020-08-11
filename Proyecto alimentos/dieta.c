#include <stdio.h>
#include <string.h>
#include "comida.h"

#define GUARDAR_CONSUMIDO 1
#define CALCULAR_CONSUMIDO 2
#define GUARDAR_QUEMADO 3
#define CALCULAR_QUEMADO 4
#define CALCULAR_BALANCE 5
#define POSITIVO 'S'
#define NEGATIVO 'N'


int main(){
  int opcion;
  char continuar;
  char fecha[MAX_FECHA];

  printf("Que desea hacer?\n");
  printf("1. Agregar datos?\n");
  printf("2. Calcular calorias?\n");
  printf("3. Agregar ejercicios?\n");
  printf("4. Calcular quemado?\n");
  printf("5. Calcular balance?\n");
  scanf("%i", &opcion);
  if(opcion > CALCULAR_BALANCE){
    while(opcion > CALCULAR_BALANCE){
      printf("Opcion no valida, ingrese la opcion de nuevo.\n");
      scanf("%i", &opcion);
    }
  }

  if(opcion == GUARDAR_CONSUMIDO){

    printf("Ingrese la fecha de hoy con el siguiente formato: dd_mm_yy\n");
    scanf("%s", fecha);
    strcat(fecha, "_a.txt");

      guardar_datos_alimentos(fecha);
      printf("Desea ingresar algo mas? S/N\n");
      scanf(" %c", &continuar);
      while(continuar == POSITIVO){
        guardar_datos_alimentos(fecha);
        printf("Desea ingresar algo mas? S/N\n");
        scanf(" %c", &continuar);
      }
  }else if(opcion == CALCULAR_CONSUMIDO){
    printf("Ingrese la fecha de hoy con el siguiente formato: dd_mm_yy\n");
    scanf("%s", fecha);
    strcat(fecha, "_a.txt");

    calcular_calorias_ingeridas(fecha);
  }else if(opcion == GUARDAR_QUEMADO){
    printf("Ingrese la fecha de hoy con el siguiente formato: dd_mm_yy\n");
    scanf("%s", fecha);
    strcat(fecha, "_e.txt");

    guardar_datos_ejercicio(fecha);
    printf("Desea ingresar algo mas? S/N\n");
    scanf(" %c", &continuar);
    while(continuar == POSITIVO){
      guardar_datos_ejercicio(fecha);
      printf("Desea ingresar algo mas? S/N\n");
      scanf(" %c", &continuar);
    }
  }else if(opcion == CALCULAR_QUEMADO){
    printf("Ingrese la fecha de hoy con el siguiente formato: dd_mm_yy\n");
    scanf("%s", fecha);
    strcat(fecha, "_e.txt");

    calcular_calorias_gastadas(fecha);
  }else if(opcion == CALCULAR_BALANCE){
    printf("Ingrese la fecha de hoy con el siguiente formato: dd_mm_yy\n");
    scanf("%s", fecha);
    calcular_balance_calorico(fecha);
  }

}
