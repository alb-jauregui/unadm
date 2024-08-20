// biblioteca de esntrada y salida estandar
#include <stdio.h>

// funcion principal
int main() {

  // declaracion de variables
  const char categorias[4][26] = {"Producto:", "Precio de venta:",
                                  "Stock disponible:",
                                  "Valor total en inventario:"},
             producto[5][11] = {"Smartphone", "Laptop", "Tablet", "Impresora",
                                "Monitor"};
  int opcion, oProducto, nUnidades, stock[5] = {25, 13, 20, 7, 5};
  float venta, vTotalInv, tVentas = 0,
                          pCompra[5] = {2500, 7500, 4500, 2500, 3500},
                          pVenta[5] = {3000, 8500, 5000, 3000, 4000};

  // inicio de bucle do-while
  do {

    // impresion de datos del estudiante
    printf("\nBienvenido al sistema de gestion de inventario y ventas PyroTEC\n"
           "***Luis Alberto Jauregui Escobar***\n"
           "***ES231105647***\n"
           "***DS-DFPR-2402-B1-018***\n\n");

    // impresion de menu
    printf("Menu de opciones:\n"
           "1. Mostrar inventario actualizado\n"
           "2. Realizar venta\n"
           "3. Agregar stock a un producto\n"
           "4. Calcular total de ventas del dia\n"
           "5. Salir\n\n"
           "Ingrese su opcion: ");
    scanf("%d", &opcion);

    // estructura switch para procesar la opcion del menu seleccionada
    switch (opcion) {
    case 1: // mostrar inventario
      printf("\nInventario actualizado:\n");
      for (int i = 0; i < 5; i++) {
        vTotalInv = pVenta[i] * stock[i];
        printf("%s %s,\n %s $%.2f, %s %d, %s $%.2f\n", categorias[0],
               producto[i], categorias[1], pVenta[i], categorias[2], stock[i],
               categorias[3], vTotalInv);
      }
      break;
    case 2: // realizar venta
      printf("\nSeleccione el producto a vender (1-5): ");
      scanf("%d", &oProducto);
      printf("Ingrese la cantidad de unidades a vender: ");
      scanf("%d", &nUnidades);
      venta = pVenta[oProducto - 1] * nUnidades;
      printf("\nVenta realizada exitosamente. Monto total: $%.2f\n", venta);
      tVentas += venta;
      break;
    case 3: // agregar stock
      printf("\nSeleccione el producto a agregar stock (1-5): ");
      scanf("%d", &oProducto);
      printf("Ingrese la cantidad de unidades a agregar: ");
      scanf("%d", &nUnidades);
      stock[oProducto - 1] += nUnidades;
      printf("\nStock actualizado. Nuevo stock de %s: %d unidades.\n",
             producto[oProducto - 1], stock[oProducto - 1]);
      break;
    case 4: // calcular las ventas del dia
      printf("\nTotal de ventas del dia: $%.2f\n", tVentas);
    }

    // condicion para salir del bucle cuando la variable opcion tome el valor de
    // 5
  } while (opcion != 5);

  // opcion 5: mensaje de despedida y termino del programa
  printf("\n!Hasta luego!\n");
}
