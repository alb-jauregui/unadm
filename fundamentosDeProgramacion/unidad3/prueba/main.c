#include <stdio.h>

struct numeros {
  int numeroUno;
  int numeroDos;
};
struct numeros arreglo[2];

void funcion(struct numeros array[]);

int main() {

  struct numeros estructuraUno, estructuraDos;

  printf("Ingrese un numero: ");
  scanf("%d", &arreglo[0].numeroUno);
  printf("Ingrese otro numero: ");
  scanf("%d", &arreglo[0].numeroDos);
  printf("Ingrese un numero: ");
  scanf("%d", &arreglo[1].numeroUno);
  printf("Ingrese otro numero: ");
  scanf("%d", &arreglo[1].numeroDos);

  funcion(arreglo);
}

void funcion(struct numeros array[]) {
  array[0] = array[1];
  printf("%d", array[0].numeroUno);
  printf("%d", array[0].numeroDos);
  printf("%d", array[1].numeroUno);
  printf("%d", array[1].numeroDos);
}
