#include <stdio.h>
#include <string.h>
#include "comida.h"


alimento_t leer_comidas(FILE * archivo, int *cantidad_comida, int *calorias){
  alimento_t morfi;
  *cantidad_comida = fscanf(archivo, "%[^;];%i\n", morfi.nombre, calorias);
  return morfi;
}


alimento_t leer_alimento_actual(FILE * archivo, int *cantidad_alimento){
  alimento_t comida;
  *cantidad_alimento = fscanf(archivo, "%[^;];%i;%i\n", comida.nombre, &comida.cantidad, &comida.calorias);
  return comida;
}

ejercicio_t leer_ejercicio(FILE * archivo, int* cantidad_ejercicios, int* calorias){
  ejercicio_t deporte;
  *cantidad_ejercicios = fscanf(archivo, "%[^;];%i\n", deporte.nombre, calorias);
  return deporte;
}

ejercicio_t leer_ejercicio_actual(FILE * archivo, int *cantidad_ejercicio){
  ejercicio_t ejercicio;
  *cantidad_ejercicio = fscanf(archivo, "%[^;];%i;%i\n", ejercicio.nombre, &ejercicio.tiempo, &ejercicio.calorias);
  return ejercicio;
}

int guardar_datos_alimentos(char fecha[MAX_FECHA]){
  FILE * archivo;
  FILE * alimento;
  alimento_t comida;
  alimento_t ingresado;
  int calorias;
  int cantidad_comida;


  alimento = fopen(MORFI, LECTURA);
  if(alimento == NULL){
    printf("No se puede abrir alimento");
    return -1;
  }

  archivo = fopen(fecha, ABRIR);
  if(archivo == NULL){
    printf("No se puede abrir el archivo\n");
    fclose(archivo);
    fclose(alimento);
    return -1;
  }

  printf("Que comiste?\n");
  scanf(" %[^\n]", ingresado.nombre);

  printf("Cuanto comiste? Porciones\n");
  scanf(" %i", &ingresado.cantidad);


  comida = leer_comidas(alimento, &cantidad_comida, &calorias);
  while(cantidad_comida != EOF){
    if(strcmp(comida.nombre, ingresado.nombre)== 0){
      calorias = (ingresado.cantidad * calorias);
      fprintf(archivo, "%s;%i;%i\n", comida.nombre, ingresado.cantidad, calorias);
    }
    comida = leer_comidas(alimento, &cantidad_comida, &calorias);
  }

  fclose(alimento);
  fclose(archivo);
  return -1;
}


int calcular_calorias_ingeridas(char fecha[MAX_FECHA]){
  FILE * archivo;
  alimento_t morfi;
  int cantidad_alimento;
  int calorias = 0;

  archivo = fopen(fecha, LECTURA);
  if(archivo == NULL){
    printf("No se puede abrir el archivo\n");
    return -1;
  }

  morfi = leer_alimento_actual(archivo, &cantidad_alimento);
  calorias += morfi.calorias;
  while(cantidad_alimento != EOF){
    morfi = leer_alimento_actual(archivo, &cantidad_alimento);
    calorias += morfi.calorias;
  }

  calorias -= morfi.calorias;

  printf("Consumiste %i calorias\n", calorias);

  fclose(archivo);
  return 1;
}


int guardar_datos_ejercicio(char fecha[MAX_FECHA]){
  FILE * archivo;
  FILE * ejercicios;
  ejercicio_t ejercicio;
  ejercicio_t lista;
  int cantidad_ejercicios;
  int calorias;

  ejercicios = fopen(EJERCI, LECTURA);
  if(ejercicios == NULL){
    printf("No se puede abrir ejercicios");
    return -1;
  }
  archivo = fopen(fecha, ABRIR);
  if(archivo == NULL){
    printf("No se puede abrir el archivo\n");
    fclose(ejercicios);
    return -1;
  }

  printf("Que hiciste hoy?\n");
  scanf(" %[^\n]", ejercicio.nombre);

  printf("Cuanto tiempo hiciste? 30min = 1\n");
  scanf(" %i", &ejercicio.tiempo);

  lista = leer_ejercicio(ejercicios, &cantidad_ejercicios, &calorias);
  while(cantidad_ejercicios != EOF){
    if(strcmp(lista.nombre, ejercicio.nombre) == 0){
      ejercicio.calorias = (ejercicio.tiempo * calorias);
      ejercicio.tiempo = (ejercicio.tiempo * 30);
      fprintf(archivo,"%s;%i;%i\n", ejercicio.nombre, ejercicio.tiempo, ejercicio.calorias);
    }
    lista = leer_ejercicio(ejercicios, &cantidad_ejercicios, &calorias);
  }

  fclose(archivo);
  fclose(ejercicios);
}

int calcular_calorias_gastadas(char fecha[MAX_FECHA]){
  FILE * archivo;
  ejercicio_t deporte;
  int cantidad_deporte;
  int calorias = 0;

  archivo = fopen(fecha, LECTURA);
  if(archivo == NULL){
    printf("No se puede abrir el archivo\n");
    return -1;
  }

  deporte = leer_ejercicio_actual(archivo, &cantidad_deporte);
  calorias += deporte.calorias;
  while(cantidad_deporte =! EOF){
    deporte = leer_ejercicio_actual(archivo, &cantidad_deporte);
    calorias += deporte.calorias;
  }

  calorias -= deporte.calorias;

  printf("Quemaste %i calorias", calorias);

  fclose(archivo);
}


int calcular_balance_calorico(char fecha[MAX_FECHA]){
  FILE * alimento;
  FILE * ejercicios;
  alimento_t morfi;
  ejercicio_t deporte;
  int cantidad_deporte;
  float calorias_a;
  float calorias_e;
  float calorias;
  int cantidad_comidas;
  int cantidad_alimento;
  char fecha_a[MAX_FECHA];
  char fecha_e[MAX_FECHA];
  strcpy(fecha_a, fecha);
  strcpy(fecha_e, fecha);
  strcat(fecha_a, "_e.txt");
  strcat(fecha_e, "_a.txt");

  alimento = fopen(fecha_a, LECTURA);
  if(alimento == NULL){
    printf("No se puede abrir alimento\n");
    return -1;
  }

  ejercicios = fopen(fecha_e, ABRIR);
  if(ejercicios == NULL){
    printf("No se puede abrir ejercicios\n");
    fclose(alimento);
    return -1;
  }

  morfi = leer_alimento_actual(alimento, &cantidad_alimento);
  calorias_a += morfi.calorias;
  while(cantidad_alimento != EOF){
    morfi = leer_alimento_actual(alimento, &cantidad_alimento);
    calorias_a += morfi.calorias;
  }

  calorias_a -= morfi.calorias;

  deporte = leer_ejercicio_actual(ejercicios, &cantidad_deporte);
  calorias_e += deporte.calorias;
  while(cantidad_deporte =! EOF){
    deporte = leer_ejercicio_actual(ejercicios, &cantidad_deporte);
    calorias_e += deporte.calorias;
  }

  calorias_e -= deporte.calorias;

  calorias = (calorias_a - calorias_e);

  if(calorias > EQUILIBRIO){
    printf(ANSI_COLOR_RED "Hiciste un superavit calorico, tu balance es de %f calorias" ANSI_COLOR_RESET "\n", calorias);
  }else if(calorias < EQUILIBRIO){
    printf(ANSI_COLOR_CYAN "Hiciste un deficit calorico, tu balance es de %f calorias" ANSI_COLOR_GREEN "\n", calorias);
  }else{
    printf(ANSI_COLOR_GREEN"Tuviste un balance perfecto, ni Jebus era así de perfecto" ANSI_COLOR_RESET "\n");
  }
  
  fclose(ejercicios);
  fclose(alimento);
}
