// Programa: Validacion de estudiantes

// ***bibliotecas***
#include <stdio.h>
#include <stdlib.h>

// ***declaracion de variables globales***
struct estudiante { // declaracion de estructura alumno
  char nombre[50];
  float comprensionLectora;
  float matematicas;
  float logica;
  float creatividad;
  float promedioAreas;
  float promedioBachillerato;
  int campus;
  int resultado;
};
int opcion; // opcion del menu
struct estudiante
    estudiantes[5]; // arreglo de estructuras de datos de los estudiantes

// ***declaracion de funciones***
void datos();      // funcion que imprime los datos del estudiante
void menu();       // funcion que imprime el menu de opciones
void registro();   // funcion para registro de estudiantes
void validacion(); // funcion que valida los resultados
void aceptados();  // funcion que imprime los estudiantes aceptados
void rechazados(); // funcion que imprime los estudiantes rechazados

// ***funcion main***
int main() {
  // declaracion de variables

  // impresion de datos del estudiante y titulo
  printf("Estudiante: Luis Alberto Jauregui Escobar\n"
         "Matricula: ES231105647\n"
         "Grupo: DS-DFPR-2402-B1-018\n\n"
         "VALIDACION DE ASPIRANTES\n");

  do { // bucle do-while
    // impresion de menu principal y lectura de opcion
    printf("\nMENU PRINCIPAL\n\n"
           "1. Registrar estudiantes\n"
           "2. Validar resultados\n"
           "3. Estudiantes aceptados\n"
           "4. Estudiantes rechazados\n"
           "5. Salir\n"
           "Opcion: ");
    scanf("%d", &opcion);
    getchar();

    // estructura switch para llevar a cabo la opcion seleccionada
    switch (opcion) {
    case 1:       // registrar estudiantes
      registro(); // llamada a la funcion registro
      break;
    case 2:
      validacion();
    }
  } while (opcion != 5); // fin de bucle do-while

} // fin de funcion main

// ***definicion de funciones***
void registro() { // funcion para registro de estudiantes
  float suma = 0;
  printf("\nREGISTRAR ESTUDIANTES\n");
  for (int i = 0; i < 5; i++) {
    printf("\nIngrese el nombre completo del estudiante %d: ", i + 1);
    fgets(estudiantes[i].nombre, 50, stdin);
    printf("Ingrese las calificaciones de las areas de evaluacion (valores de "
           "0 a 10): \n"
           "Comprension lectora: ");
    scanf("%f", &estudiantes[i].comprensionLectora);
    suma += estudiantes[i].comprensionLectora;
    printf("Matematicas: ");
    scanf("%f", &estudiantes[i].matematicas);
    suma += estudiantes[i].matematicas;
    printf("Logica: ");
    scanf("%f", &estudiantes[i].logica);
    suma += estudiantes[i].logica;
    printf("Creatividad: ");
    scanf("%f", &estudiantes[i].creatividad);
    suma += estudiantes[i].creatividad;
    estudiantes[i].promedioAreas = suma / 4;
    printf("El promedio de evaluacion de areas obtenido es: %.2f\n"
           "Ingrese el promedio general de bachillerato del estudiante: ",
           estudiantes[i].promedioAreas);
    scanf("%f", &estudiantes[i].promedioBachillerato);
    printf(
        "Ingrese el campus al que el estudiante desea ingresar (1, 2 o 3): ");
    scanf("%d", &estudiantes[i].campus);
    getchar();
  }
} // fin de funcion registro
int compare(const void *a,
            const void *b) { // funcion para comparar los elementos del array
  return (*(int *)a - *(int *)b);
}
void validacion() { // funcion que valida los resultados
  printf("\nVALIDAR RESULTADOS\n\n"
         "Estudiantes:\n");
  qsort(estudiantes, n, 5, compare);
  for (int i = 0; i < 5; i++) {
    printf("Validando datos de %s: ", estudiantes[i].nombre);
    if (estudiantes[i].resultado == 1) {
      printf("%.3f *Aceptado*\n", estudiantes[i].promedioAreas);
    } else {
      printf("%.3f *Rechazado*\n", estudiantes[i].promedioAreas);
    }
  }
} // fin de funcion validacion
