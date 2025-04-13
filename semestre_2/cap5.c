/*
1 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
     e imprima-os no video no seguinte formato:(Declare os 5 vetores como
variaveis globais)

              10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3

2 - Escreva um programa que receba uma string (40) na funcao main(). Faca uma
funcao que calcula o comprimento de uma string recebida via teclado. Mostre o
valor do comprimento na funcao main(). (Declare o vetor como variavel global)
(nao pode usar funcao de biblioteca)

3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os
caracteres para letras maiusculas. (nao pode usar funcao de biblioteca)

4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os
caracteres para letras minusculas. (nao pode usar funcao de biblioteca)

5 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
     funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
     DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
     (Declare os vetores como variavel global) (nao pode usar funcao de
biblioteca)
*/
#include <stdio.h>

#define ex1

#ifdef ex1
char nome1[8], nome2[8], nome3[8], nome4[8], nome5[8];

int main() {
  char opcao;
  do {
    printf("Digite 5 nomes, cada um com até 7 caracteres:\n");
    scanf("%7s", nome1);
    scanf("%7s", nome2);
    scanf("%7s", nome3);
    scanf("%7s", nome4);
    scanf("%7s", nome5);

    printf("\n10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
    printf("  %-7s                             %-7s\n", nome1, nome5);
    printf("              %-7s           %-7s\n", nome2, nome4);
    printf("                        %-7s\n", nome3);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex2
char str[41];

int main() {
  char opcao;
  do {
    printf("Digite uma string de até 40 caracteres: ");
    scanf("%40[^\n]", str);
    getchar();

    int comprimento = 0;
    while (str[comprimento] != '\0') {
      comprimento++;
    }

    printf("Comprimento da string: %d\n", comprimento);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex3
char str[11];

int main() {
  char opcao;
  do {
    printf("Digite uma cadeia de caracteres (máximo 10 caracteres): ");
    scanf("%10s", str);

    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        str[i] = str[i] - 32;
      }
    }

    printf("Cadeia em maiúsculas: %s\n", str);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex4
char str[11];

int main() {
  char opcao;
  do {
    printf("Digite uma cadeia de caracteres (máximo 10 caracteres): ");
    scanf("%10s", str);

    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        str[i] = str[i] + 32;
      }
    }

    printf("Cadeia em minúsculas: %s\n", str);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex5
char str1[11], str2[11];

int main() {
  char opcao;
  do {
    printf("Digite a primeira string (máximo 10 caracteres): ");
    scanf("%10s", str1);
    printf("Digite a segunda string (máximo 10 caracteres): ");
    scanf("%10s", str2);

    int iguais = 1;

    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
      if (str1[i] != str2[i]) {
        iguais = 0;
        break;
      }
    }

    if (iguais) {
      printf("As strings são IGUAIS.\n");
    } else {
      printf("As strings são DIFERENTES.\n");
    }

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif
