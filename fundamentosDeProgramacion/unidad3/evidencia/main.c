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
void registro();   // funcion para registro de estudiantes
void validacion(); // funcion que valida los resultados
void aceptados();  // funcion que imprime los estudiantes aceptados
void rechazados(); // funcion que imprime los estudiantes rechazados
void bubbleSortPorPromedioAreas(
    struct estudiante arreglo[]); // funcion bubblesort para ordenar el arreglo
                                  // de estructuras de forma descentente
void bubbleSortPorCampus(
    struct estudiante arreglo[]); // funcion bubblesort para ordenar el arregl
                                  // de estructuras de forma ascendente

// ***funcion main***
int main() {
  // declaracion de variables locales a main
  int opcion; // opcion del menu
  // impresion de datos del estudiante y titulo
  printf("Estudiante: Luis Alberto Jauregui Escobar\n"
         "Matricula: ES231105647\n"
         "Grupo: DS-DFPR-2402-B1-018\n\n"
         "**********VALIDACION DE ASPIRANTES**********\n");
  do { // bucle do-while
    // impresion de menu principal y lectura de opcion
    printf("\n**********MENU PRINCIPAL**********\n\n"
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
    case 2: // validar resultados
      bubbleSortPorPromedioAreas(
          estudiantes); // llamada a la funcion bubbleSortPorPromedioAreas
      validacion();     // llamada a la funcion validacion
      break;
    case 3: // imprimir estudiantes aceptados
      bubbleSortPorCampus(
          estudiantes); // llamada a la funcion bubbleSortPorCampus
      aceptados();      // llamada a la funcion aceptados
      break;
    case 4: // imprimir estudiantes rechazados
      bubbleSortPorCampus(
          estudiantes); // llamada a la funcion bubbleSortPorCampus
      rechazados();     // llamada a la funcion rechazados
    }
  } while (opcion != 5); // fin de bucle do-while
} // fin de funcion main

// ***definicion de funciones***
void registro() { // funcion para registro de estudiantes
  printf("\n**********REGISTRAR ESTUDIANTES**********\n");
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
  printf("\n**********VALIDAR RESULTADOS**********\n\n"
         "Estudiantes:\n");
  for (int i = 0; i < 5; i++) {
    if (estudiantes[i].resultado == 1) {
      printf("Validando datos de %s: %.3f *Aceptado*\n", estudiantes[i].nombre,
             estudiantes[i].promedioAreas);
    } else {
      printf("Validando datos de %s: %.3f *Rechazado*\n", estudiantes[i].nombre,
             estudiantes[i].promedioAreas);
    }
  }
} // fin de funcion validacion
void aceptados() { // funcion que imprime los estudiantes aceptados
  int n = 1;
  printf("\n**********ACEPTADOS**********\n\n"
         "Lista de estudiantes aceptados por campus:\n\n");
  for (int i = 0; i < 5; i++) {
    if (estudiantes[i].resultado == 1) {
      printf("%d. %s  Promedio Area: %.2f  Promedio General: %.2f  Campus: %d  "
             "Aceptado: Si\n",
             n, estudiantes[i].nombre, estudiantes[i].promedioAreas,
             estudiantes[i].promedioBachillerato, estudiantes[i].campus);
      n++;
    }
  }
} // fin de funcion aceptados
void rechazados() { // funcion que imprime los estudiantes rechazados
  int n = 1;
  printf("\n**********RECHAZADOS**********\n\n"
         "Lista de estudiantes rechazados por campus:\n\n");
  for (int i = 0; i < 5; i++) {
    if (estudiantes[i].resultado == 0) {
      printf("%d. %s  Promedio Area: %.2f  Promedio General: %.2f  Campus: %d  "
             "Aceptado: No\n",
             n, estudiantes[i].nombre, estudiantes[i].promedioAreas,
             estudiantes[i].promedioBachillerato, estudiantes[i].campus);
      n++;
    }
  }
} // fin de funcion rechazados
void bubbleSortPorPromedioAreas(
    struct estudiante arreglo[]) { // funcion bubblesort para ordenar el arreglo
                                   // de estructuras de forma descentente por el
                                   // promedio de areas
  struct estudiante temporal; // variable para guardar temporalmente el elemento
                              // que se va a intercambiar
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4 - i; j++) {
      // se intercambian los elementos si el siguiente es mayor
      if (arreglo[j].promedioAreas < arreglo[j + 1].promedioAreas ||
          arreglo[j].promedioBachillerato <
              arreglo[j + 1].promedioBachillerato) {
        temporal = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = temporal;
      }
    }
  }
} // fin de funcion bubbleSortPorPromedioAreas
void bubbleSortPorCampus(
    struct estudiante
        arreglo[]) { // funcion bubblesort para ordenar el arreglo de
                     // estructuras de forma escendente por numero de campus
  struct estudiante temporal; // variable para guardar temporalmente el elemento
                              // que se va a intercambiar
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4 - i; j++) {
      // se intercambian los elementos si el siguiente es menor
      if (arreglo[j].campus > arreglo[j + 1].campus) {
        temporal = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = temporal;
      }
    }
  }
} // fin de funcion bubbleSortPorCampus
