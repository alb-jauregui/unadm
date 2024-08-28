// Programa: Sistema de pago

// bibliotecas
#include <stdio.h>  // funciones entrada y salida estandar
#include <string.h> // funciones de manipulacion de series

// declaracion de constantes y variables globales
const int habitacion = 1500;
char nombre[50];
int sucursal, dias;
float totalConIVA;

// prototipos de funciones
// funcion que muestra los datos del estudiante
void datos();
// funcion que calcula el impuesto sobre el hospedaje y el iva
float impuesto();
// funcion que procesa el cobro
void cobro();
// funcion que calcula la cantidad total a pagar
void total();

// function principal
int main() {
  // declaracion de variables locales de la funcion main
  // llamada a la funcion datos
  datos();
  // ingreso y lectura de datos del cliente
  printf("***SISTEMA DE PAGO***\n\n"

         "Ingrese el nombre del cliente: ");
  fgets(nombre, 50, stdin);
  printf("Ingrese el numero correspondiente a la sucursal (1.CDMX "
         "2.Guadalajara 3.Aguascalientes): ");
  scanf("%d", &sucursal);
  printf("Ingrese el numero de dias de estancia: ");
  scanf("%d", &dias);
  totalConIVA = impuesto();
  cobro();
} // fin de la funcion principal

// definicion de funciones
// funcion que muestra los datos del estudiante
void datos() {
  printf("***DATOS DEL ESTUDIANTE***\n"
         "Nombre del estudiante: Luis Alberto Jauregui Escobar\n"
         "Matricula: ES231105647\n"
         "Grupo: DS-DFPR-2402-B1-018\n\n");
}
// funcion que calcula el impuesto sobre el hospedaje y el iva
float impuesto() {
  // declaracion constantes y variables locales de la funcion impuesto
  const float IVA = 0.16;
  char hotel[50];
  int totalPorDias, ish, totalAPagar;
  float impuesto, iva, totalConIVA;
  // ingreso de datos y asignacion de variables
  switch (sucursal) {
  case 1:
    strncpy(hotel, "Business Class CDMX", 50);
    impuesto = 0.035;
    break;
  case 2:
    strncpy(hotel, "Business Class Guadalajara", 50);
    impuesto = 0.03;
    break;
  case 3:
    strncpy(hotel, "Business Class Aguascalientes", 50);
    impuesto = 0.03;
  }
  // calculos
  totalPorDias = habitacion * dias;
  ish = totalPorDias * impuesto;
  totalAPagar = totalPorDias + ish;
  iva = totalAPagar * IVA;
  totalConIVA = totalAPagar + iva;
  // impresion de datos y resultados
  printf("\nNombre del cliente: %s"
         "Hotel: %s\n"
         "Dias de estancia: %d\n"
         "Total por dias: $%d\n"
         "ISH correspondiente al 3 porciento: $%d\n"
         "Total + IVA: $%.1f\n\n",
         nombre, hotel, dias, totalPorDias, ish, totalConIVA);
  return totalConIVA;
}
// funcion que procesa el cobro
void cobro() {
  // declaracion constantes y variables locales de la funcion
  int opcionPago;
  char formaPago[50];
  float descuento, totalConDescuento, porcentaje, comision, totalConComision;
  // impresion de titulo
  printf("***FORMA DE PAGO***\n");
  // inicio de bucle do-while
  do {
    // impresion del menu y lectura de eleccion
    printf("1) Pago al contado\n"
           "2) Pago con tarjeta de credito, en un unico pago\n"
           "3) Pago con tarjeta de credito a 6 meses\n"
           "Elige la forma de pago: ");
    scanf("%d", &opcionPago);
    // acciones segun la opcion elegida
    switch (opcionPago) {
    case 1: // pago al contado
      strncpy(formaPago, "1. Pago al contado", 50);
      if (dias > 7) {
        porcentaje = 6;
      } else {
        porcentaje = 4;
      }
      descuento = totalConIVA * (porcentaje / 100);
      totalConDescuento = totalConIVA - descuento;
      printf("\nOpcion %s\n"
             "Dias de estancia: %d\n"
             "El descuento que se obtuvo es del %.0f porciento y corresponde "
             "a la cantidad de: $%.2f\n"
             "La cantidad a pagar con descuento es de: $%.2f",
             formaPago, dias, porcentaje, descuento, totalConDescuento);
      break;
    case 2:
      strncpy(formaPago, "2. Pago con tarjeta de credito en un unico pago", 50);
      porcentaje = 7;
      comision = totalConIVA * (porcentaje / 100);
      totalConComision = totalConIVA + comision;
      printf("\nOpcion %s\n"
             "La comision del %.0f porciento es de: %.2f\n"
             "La cantidad total a pagar es de: %.2f",
             formaPago, porcentaje, comision, totalConComision);
      break;
    case 3:
      strncpy(formaPago, "3. Pago con tarjeta de credito a 6 meses", 50);
      break;
    default:
      printf("Opcion no valida. Ingresa el numero correspondiente a la opcian "
             "deseada.\n\n");
    }
  } while (opcionPago < 0 || opcionPago > 3); // fin de bucle do-while
}
