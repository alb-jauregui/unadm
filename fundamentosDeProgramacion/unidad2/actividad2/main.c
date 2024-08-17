// Programa que calcula el total a pagar por pedidos de platillos que realiza un
// cliente

// Directivas al procesador
#include <stdio.h> // biblioteca estandar de entrada y salida

// Funcion principal
int main() {

  // Declaraciones de variables y constantes
  const float TASA = 0.16;
  char nombreCliente[50], nombrePlatillo[50];
  int cantidadPlatillo;
  float precioPlatillo;

  // Impresion de datos del estudiante
  printf("***DATOS DEL ESTUDIANTE***\n");
  printf("Nombre del estudiante: Luis Alberto Jauregui Escobar\n");
  printf("Matricula: ES231105647\n");
  printf("Grupo: DS-DFPR-2402-B1-018\n\n");

  // Lecturo de datos del cliente y platillo
  printf("***DATOS DEL PEDIDO DE COMIDA***\n");
  printf("Ingrese el nombre del cliente: ");
  scanf("%s", nombreCliente);
  printf("Ingrese el nombre del platillo: ");
  scanf("%s", nombrePlatillo);
  printf("Ingrese el precio del platillo sin IVA: ");
  scanf("%f", &precioPlatillo);
  printf("Ingrese la cantidad de platillos: ");
  scanf("%d", &cantidadPlatillo);

  // Calculo de importe, iva y total
  float importe = precioPlatillo * cantidadPlatillo;
  float iva = importe * TASA;
  float total = importe + iva;

  // Impresion del importe e iva
  printf("Importe sin IVA: %.2f\n", importe);
  printf("IVA: %.2f\n\n", iva);

  // Impresion de datos del cliente y total
  printf("***DATOS DEL CLIENTE Y TOTAL A PAGAR CON IVA***\n");
  printf("Nombre del cliente: %s\n", nombreCliente);
  printf("Total a pagar del pedido con IVA: %.2f", total);

  return 0;
}
