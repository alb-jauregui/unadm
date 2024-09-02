// Programa: Sistema de pago

// ----------bibliotecas----------
#include <stdio.h>  // funciones entrada y salida estandar
#include <string.h> // funciones de manipulacion de series

// ----------declaracion de constantes y variables globales----------
const int habitacion = 1500;
char nombre[50];
int sucursal, dias;
float totalConIVA;

// ----------prototipos de funciones----------
void datos();    // funcion que muestra los datos del estudiante
void impuesto(); // funcion que calcula el impuesto sobre el hospedaje y el iva
void cobro();    // funcion que procesa el cobro
void total();    // funcion que calcula la cantidad total a pagar

// ----------funcion principal----------
int main() {

  // ----------declaracion de variables locales de la funcion main----------
  datos(); // llamada a la funcion datos que imprime los datos del estudiante

  // ingreso y lectura de datos
  printf("----------SISTEMA DE PAGO----------\n\n"

         "Ingrese el nombre del cliente: ");
  fgets(nombre, 50, stdin);
  printf("Ingrese el numero correspondiente a la sucursal (1.CDMX "
         "2.Guadalajara 3.Aguascalientes): ");
  scanf("%d", &sucursal);
  printf("Ingrese el numero de dias de estancia: ");
  scanf("%d", &dias);
  impuesto();
  cobro();
} // fin de la funcion principal

// ----------definicion de funciones----------
void datos() { // funcion que muestra los datos del estudiante
  printf("----------DATOS DEL ESTUDIANTE----------\n"
         "Nombre del estudiante: Luis Alberto Jauregui Escobar\n"
         "Matricula: ES231105647\n"
         "Grupo: DS-DFPR-2402-B1-018\n\n");
} // fin de la funcion datos

void impuesto() { // funcion que calcula el impuesto sobre el hospedaje y el
                  // iva
  // declaracion de constantes y variables locales
  const float IVA = 0.16;
  char hotel[50];
  int totalPorDias, ish, totalAPagar;
  float impuesto, iva;
  // ingreso y lectura de datos
  switch (sucursal) {
  case 1:
    strncpy(hotel, "Business Class CDMX", 50);
    impuesto = 3.5;
    break;
  case 2:
    strncpy(hotel, "Business Class Guadalajara", 50);
    impuesto = 3;
    break;
  case 3:
    strncpy(hotel, "Business Class Aguascalientes", 50);
    impuesto = 3;
  }
  // calculos
  totalPorDias = habitacion * dias;
  ish = totalPorDias * (impuesto / 100);
  totalAPagar = totalPorDias + ish;
  iva = totalAPagar * IVA;
  totalConIVA = totalAPagar + iva;
  // impresion de resultados
  printf("\nNombre del cliente: %s"
         "Hotel: %s\n"
         "Dias de estancia: %d\n"
         "Total por dias: $%d\n"
         "ISH correspondiente al %.1f%%: $%d\n"
         "Total + IVA: $%.1f\n",
         nombre, hotel, dias, totalPorDias, impuesto, ish, totalConIVA);
} // fin de la funcion impuesto
void cobro() { // funcion que procesa el cobro
  // declaracion de constantes y variables locales
  int opcionPago;
  char formaPago[50], continuar;
  float descuento, totalConDescuento, porcentaje, comision, totalConComision,
      mensualidad;
  do { // inicio de bucle do-while
    printf("\n----------FORMA DE PAGO----------\n"
           "1) Pago al contado\n"
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
             "El descuento que se obtuvo es del %.0f%% y corresponde "
             "a la cantidad de: $%.2f\n"
             "La cantidad a pagar con descuento es de: $%.2f\n\n",
             formaPago, dias, porcentaje, descuento, totalConDescuento);
      printf("Deseas capturar otro nombre de cliente (s/n): ");
      scanf(" %c", &continuar);
      break;
    case 2: // pago con tarjeta de credito en un unico pago
      strncpy(formaPago, "2. Pago con tarjeta de credito en un unico pago", 50);
      porcentaje = 7;
      comision = totalConIVA * (porcentaje / 100);
      totalConComision = totalConIVA + comision;
      printf("\nOpcion %s\n"
             "La comision del %.0f%% es de: $%.2f\n"
             "La cantidad total a pagar es de: $%.2f\n\n",
             formaPago, porcentaje, comision, totalConComision);
      printf("Deseas capturar otro nombre de cliente (s/n): ");
      scanf(" %c", &continuar);
      break;
    case 3: // pago con tarjeta de credito a 6 meses
      strncpy(formaPago, "3. Pago con tarjeta de credito a 6 meses", 50);
      porcentaje = 10;
      comision = totalConIVA * (porcentaje / 100);
      mensualidad = (totalConIVA + comision) / 6;
      totalConComision = totalConIVA + comision;
      printf("Opcion %s\n"
             "La cantidad a pagar del %.0f%% es de: $%.2f\n"
             "El pago total a pagar es de: $%.2f\n"
             "y se distribuye en 6 pagos iguales de: $%.2f\n\n",
             formaPago, porcentaje, comision, totalConComision, mensualidad);
      printf("Deseas capturar otro nombre de cliente (s/n): ");
      scanf(" %c", &continuar);
      break;
    default:
      printf("Opcion no valida. Ingrese el numero correspondiente a la opcion "
             "deseada.\n\n");
    }
  } while (continuar != 'n'); // fin de bucle do-while
} // fin de la funcion cobro
