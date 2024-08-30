// Programa: Sistema de control de especies en un zoologico

// bibliotecas
#include <stdio.h>
#include <string.h>

// declaracion de constantes y variables globales
int nEspecies;

// prototipos de funciones
void datos(); // funcion que imprime los datos del estudiante
void opciones();

// funcion principal
int main() {
  datos();
  opciones();
} // fin de funcion principal

// definicion de funciones
void datos() { // funcion que imprime los datos del estudiante
  // declaracion de variables
  // impresion de bienvenida, datos del estudiante
  printf("BIENVENIDO AL SISTEMA DE CONTROL DE ESPECIES DEL ZOOLOGICO\n\n"
         "Estudiante: Luis Alberto Jauregui Escobar\n"
         "Matricula: ES231105647\n"
         "Grupo: DS-DFPR-2402-B1-018\n\n"
         "Ingrese la cantidad de especies a registrar: ");
  scanf("%d", &nEspecies);
} // fin de funcion datos
void opciones() {
  int opcion;
  char especies[nEspecies][20];
  int ejemplares[nEspecies];
  do {
    printf("\nMENU\n"
           "1. Nombre de la especie\n"
           "2. Numero de ejemplares\n"
           "3. Informe general de especies\n"
           "4. Salir\n"
           "Seleccione una opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1: // registro de nombre de las especies
      printf("\nNOMBRE DE LAS ESPECIES\n");
      for (int i = 0; i < nEspecies; i++) {
        printf("Especie %d: ", i + 1);
        scanf("%s", especies[i]);
      }
      break; // fin de case 1
    case 2:  // registro de numero de ejemplares por especie
      printf("\nNUMERO DE EJEMPLARES\n");
      for (int i = 0; i < nEspecies; i++) {
        printf("%s: ", especies[i]);
        scanf("%d", &ejemplares[i]);
      }
      break;
    case 3: // registro de numero de ejemplares por especie
      printf("\nINFORME GENERAL DE ESPECIES\n");
      for (int i = 0; i < nEspecies; i++) {
        printf("%s: %d\n", especies[i], ejemplares[i]);
      }
    }                   // fin de switch
  } while (opcion < 4); // fin de bucle do-while
  printf("\nHasta pronto...");
} // fin de funcion opciones
