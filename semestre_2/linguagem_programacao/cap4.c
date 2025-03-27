#include <stdio.h>

#define ex1

#ifdef ex1
int main() {
  char opcao = 's';
  do {
    // Codigo aqui

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}
#endif