#include <stdio.h>
#include <string.h>

#define ABRIR "a+"
#define LECTURA "r"
#define MORFI "alimentos.txt"
#define EJERCI "ejercicios.txt"

#define MAX_NOMBRE 100
#define MAX_FECHA 20
#define UNIDAD_TIEMPO 30
#define EQUILIBRIO 0

#define ANSI_COLOR_RED     "\x1b[1;31m"
#define ANSI_COLOR_GREEN   "\x1b[1;32m"
#define ANSI_COLOR_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


typedef struct alimento{
  char nombre[MAX_NOMBRE];
  int cantidad;
  int calorias;
} alimento_t;

typedef struct ejercicio{
  char nombre[MAX_NOMBRE];
  int tiempo;
  int calorias;
} ejercicio_t;


int guardar_datos_alimentos();

int calcular_calorias_ingeridas();

int guardar_datos_ejercicio();

int calcular_calorias_gastadas();

int calcular_balance_calorico();
