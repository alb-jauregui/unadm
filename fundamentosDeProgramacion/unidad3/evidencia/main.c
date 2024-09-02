// Programa: Validacion de estudiantes

// ***bibliotecas***
#include <stdio.h>

// ***declaracion de variables globales***
struct estudiante { // declaracion de estructura estudiante
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
struct estudiante
    estudiantes[5]; // arreglo de estructuras de datos de los estudiantes

// ***declaracion de funciones***
void datos();      // funcion que imprime los datos del estudiante
void menu();       // funcion que imprime el menu de opciones
void registro();   // funcion para registro de estudiantes
void validacion(); // funcion que valida los resultados
void aceptados();  // funcion que imprime los estudiantes aceptados
void rechazados(); // funcion que imprime los estudiantes rechazados
void bubbleSort(); // funcion bubblesort para ordenar el arreglo
                   // de estructuras de forma descentente

// ***funcion main***
int main() {
  // declaracion de variables
  int opcion; // opcion del menu

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
    case 1:                    // registrar estudiantes
      registro();              // llamada a la funcion registro
      bubbleSort(estudiantes); // llamada a la funcion bubbleSort
      break;
    case 2:
      validacion();
    }
  } while (opcion != 5); // fin de bucle do-while
} // fin de funcion main

// ***definicion de funciones***
void registro() { // funcion para registro de estudiantes
  printf("\nREGISTRAR ESTUDIANTES\n");
  for (int i = 0; i < 5; i++) {
    float suma = 0; // acumulador de calificaciones para calcular el promedio de
                    // evaluacion de areas
    printf("\nIngrese el nombre completo del estudiante %d: ", i + 1);
    fgets(estudiantes[i].nombre, 50, stdin);
    printf("Ingrese las calificaciones de las areas de evaluacion (valores de "
           "0 a 10): \n");
    do {
      printf("Comprension lectora: ");
      scanf("%f", &estudiantes[i].comprensionLectora);
    } while (estudiantes[i].comprensionLectora < 0 ||
             estudiantes[i].comprensionLectora > 10);
    suma += estudiantes[i].comprensionLectora;
    do {
      printf("Matematicas: ");
      scanf("%f", &estudiantes[i].matematicas);
    } while (estudiantes[i].matematicas < 0 || estudiantes[i].matematicas > 10);
    suma += estudiantes[i].matematicas;
    do {
      printf("Logica: ");
      scanf("%f", &estudiantes[i].logica);
    } while (estudiantes[i].logica < 0 || estudiantes[i].logica > 10);
    suma += estudiantes[i].logica;
    do {
      printf("Creatividad: ");
      scanf("%f", &estudiantes[i].creatividad);
    } while (estudiantes[i].creatividad < 0 || estudiantes[i].creatividad > 10);
    suma += estudiantes[i].creatividad;
    estudiantes[i].promedioAreas = suma / 4;
    if (estudiantes[i].promedioAreas >=
        7) { // se evalua el promedio de evaluacion de areas para ser aceptado o
             // rechazado
      estudiantes[i].resultado = 1;
    } else {
      estudiantes[i].resultado = 0;
    }
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
void validacion() { // funcion que valida los resultados
  printf("\nVALIDAR RESULTADOS\n\n"
         "Estudiantes:\n");
  for (int i = 0; i < 5; i++) {
    printf("Validando datos de %s: ", estudiantes[i].nombre);
    if (estudiantes[i].resultado == 1) {
      printf("%.3f *Aceptado*\n", estudiantes[i].promedioAreas);
    } else {
      printf("%.3f *Rechazado*\n", estudiantes[i].promedioAreas);
    }
  }
} // fin de funcion validacion
void bubbleSort(
    struct estudiante arreglo[]) { // funcion bubblesort para ordenar el arreglo
                                   // de estructuras de forma descentente
  struct estudiante temporal; // variable para guardar temporalmente el elemento
                              // que se va a intercambiar
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4 - i; j++) {
      // se intercambian los elementos si el siguiente es menor
      if (arreglo[j].promedioAreas < arreglo[j + 1].promedioAreas) {
        temporal = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = temporal;
      }
    }
  }
}
