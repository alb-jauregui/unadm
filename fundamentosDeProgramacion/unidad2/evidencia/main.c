// Programa: Calculo de apoyo a damnificados

// biblioteca de funciones estandar de entrada y salida
#include <stdio.h>

// funcion principal
int main() {

  // declaracion de variables
  int folio, estado, nIntegrantes, nHijos, mInicial, aIntegrantes, aHijos,
      mTotal, fAtendidas = 0;
  char continuar, nombre[15], pApellido[15], sApellido[15];

  // impresion de datos del alumno
  printf("Fundamentos de programacion U2 EA\n");
  printf("Alumno: Luis Alberto Jauregui Escobar - Matricula: ES231105647 - "
         "Grupo: DS-DFPR-2402-B1-018");

  // inicio del bucle principal
  do {

    // ingreso y lectura de datos
    printf("\n\nIngrese el folio de reguistro de la familia afectada: ");
    scanf("%d", &folio);
    printf("Ingrese el nombre de la persona que proporciona la informacion: ");
    scanf("%s", nombre);
    scanf("%s", pApellido);
    scanf("%s", sApellido);
    printf("Ingrese el estado donde radica la familia (1-Chiapas, 2-Guerrero, "
           "3-Oaxaca): ");
    scanf("%d", &estado);
    printf("Ingrese el numero de integrantes de la familia: ");
    scanf("%d", &nIntegrantes);
    printf("Ingrese el numero de hijos menores: ");
    scanf("%d", &nHijos);

    // asignacion de valor a la variable estado segun el caso
    switch (estado) {
    case 1:
      mInicial = 45000;
      break;
    case 2:
      mInicial = 60000;
      break;
    case 3:
      mInicial = 80000;
    }

    // asignacion de valor a la variable aIntegrantes segun el caso
    switch (nIntegrantes) {
    case 3:
    case 4:
      aIntegrantes = mInicial * 0.1;
      break;
    case 5:
    case 6:
    case 7:
      aIntegrantes = mInicial * 0.15;
      break;
    default:
      if (nIntegrantes > 7) {
        aIntegrantes = mInicial * 0.2;
      }
    }

    // asignacion de valor a la variable nHijos segun el caso
    switch (nHijos) {
    case 1:
    case 2:
    case 3:
      aHijos = nHijos * 4500;
      break;
    case 4:
    case 5:
    case 6:
      aHijos = nHijos * 3000;
      break;
    default:
      if (nHijos > 6) {
        aHijos = nHijos * 2000;
      }
    }

    // calculo de aTotal
    mTotal = mInicial + aIntegrantes + aHijos;

    // incremento de contador de familias atendidas fAtendidas
    fAtendidas++;

    // impresion de resultados
    printf("\nFolio de registro: %d\n", folio);
    printf("Nombre de quien proporciona los datos: %s %s %s\n", nombre,
           pApellido, sApellido);
    printf("Monto inical por estado donde radica: %d\n", mInicial);
    printf("Apoyo por integrantes de familia: %d\n", aIntegrantes);
    printf("Apoyo por hijos menores en la familia: %d\n", aHijos);
    printf("Monto total del apoyo: %d\n\n", mTotal);

    // ingreso y lectura de decision de continuar con el registro
    printf("¿Desea ingresar otro registro? s(si) n(no): ");
    scanf(" %c", &continuar);

    // fin del bucle principal si la variable continuar tiene el valor 'n'
  } while (continuar != 'n');

  // impresion del numero de familias atendidas
  printf("Numero de familias atendidas durante la sesion: %d", fAtendidas);

  return 0;
} // fin de la funcion principal
