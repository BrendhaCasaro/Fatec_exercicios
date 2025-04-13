/*
1 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

          10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double

2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o
programa deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.

3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.

4 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.

5 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.
*/

#include <stdio.h>

#define ex4

#ifdef ex1
int main() {
  char opcao = 's';
  do {
    int ints[3];
    long longs[3];
    unsigned int unsigneds[3];
    float floats[3];
    double doubles[3];

    printf("Digite 3 valores do tipo int: ");
    for (int i = 0; i < 3; i++)
      scanf("%d", &ints[i]);

    printf("Digite 3 valores do tipo long: ");
    for (int i = 0; i < 3; i++)
      scanf("%ld", &longs[i]);

    printf("Digite 3 valores do tipo unsigned int: ");
    for (int i = 0; i < 3; i++)
      scanf("%u", &unsigneds[i]);

    printf("Digite 3 valores do tipo float: ");
    for (int i = 0; i < 3; i++)
      scanf("%f", &floats[i]);

    printf("Digite 3 valores do tipo double: ");
    for (int i = 0; i < 3; i++)
      scanf("%lf", &doubles[i]);

    printf("\n         10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");

    for (int i = 0; i < 3; i++) {
      printf("%-10d %-20ld %-10u\n", ints[i], longs[i], unsigneds[i]);
      printf("          %-10.2f %-10.2lf\n", floats[i], doubles[i]);
    }

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}
#endif

#ifdef ex2
int main() {
  char opcao = 's';
  do {
    int vet[10];
    int contImpar = 0;
    int contPar = 0;

    for (int i = 0; i < 10; i++) {
      puts("Digite qualquer número");
      scanf("%d", &vet[i]);
    }

    int vetPar[5];
    int vetImpar[5];

    for (int i = 0, j = 0, k = 0; i < 10; i++) {
      if (i % 2 == 0) {
        vetPar[j] = vet[i];
        j++;
      } else {
        vetImpar[k] = vet[i];
        k++;
      }
    }

    for (int i = 0; i < 5; i++) {
      printf("Posição %d do vetor impar: %d\n", i, vetImpar[i]);
      puts("");
    }

    for (int i = 0; i < 5; i++) {
      printf("Posição %d do vetor par: %d\n", i, vetPar[i]);
      puts("");
    }

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}
#endif

#ifdef ex3
int main() {
  char opcao = 's';
  do {
    int vet[10];
    int contImpar = 0;
    int contPar = 0;

    for (int i = 0; i < 10; i++) {
      do {
        puts("Digite qualquer número");
        scanf("%d", &vet[i]);

        if (vet[i] <= 0) {
          puts("Valor não pode ser menor ou igual a zero");
        }
      } while (vet[i] <= 0);
    }

    for (int i = 0; i < 10; i++) {
      if (vet[i] % 2 == 0) {
        contPar++;
      } else {
        contImpar++;
      }
    }

    int vetPar[contPar];
    int vetImpar[contImpar];

    for (int i = 0, j = 0, k = 0; i < 10; i++) {
      if (vet[i] % 2 == 0) {
        vetPar[j] = vet[i];
        j++;
      } else {
        vetImpar[k] = vet[i];
        k++;
      }
    }

    for (int i = 0; i < contImpar; i++) {
      printf("Posição %d do vetor impar: %d\n", i, vetImpar[i]);
      puts("");
    }

    for (int i = 0; i < contPar; i++) {
      printf("Posição %d do vetor par: %d\n", i, vetPar[i]);
      puts("");
    }

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}

#endif

#ifdef ex4
int main() {
  char opcao = 's';

  do {
    int vet1[2][3];

    int vet2[2][3];

    int soma[2][3];

    // dados vet1
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {

        puts("Insira dados no vetor 1");
        scanf("%d", &vet1[i][j]);
      }
    }

    // dados vet2
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {

        puts("Insira dados no vetor 2");
        scanf("%d", &vet2[i][j]);
      }
    }

    puts("");
    puts("Vetor 1");
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {

        printf("%d ", vet1[i][j]);
      }
      puts("");
    }

    puts("");
    puts("Vetor 2");
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {

        printf("%d ", vet2[i][j]);
      }
      puts("");
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        soma[i][j] = vet1[i][j] + vet2[i][j];
      }
    }

    puts("");
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {

        printf("soma[%d][%d] = %d \n", i, j, soma[i][j]);
      }
    }

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}

#endif

#ifdef ex5
void ordenar(int *vet) {

  int aux;
  int n = 10;

  for (int i = 0; i < n; i++) {
    for (int index = 0; index < n - 1; index++) {
      if (vet[index] > vet[index + 1]) {
        aux = vet[index];
        vet[index] = vet[index + 1];
        vet[index + 1] = aux;
      }
    }
  }
}

void imprimir(int *vet) {
  for (int i = 0; i < 10; i++) {
    printf("%d ", vet[i]);
  }
  puts("");
}

int main() {
  char opcao = 's';

  do {
    int vet[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 9; i >= 0; i--) {
      puts("Digite um valor qualquer");
      scanf("%d", &vet[i]);

      imprimir(vet);

      ordenar(vet);
    }

    imprimir(vet);

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}

#endif
