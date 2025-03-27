/*
* 1 - Escreva um programa que receba dois numeros inteiros e execute as
seguintes funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor
de retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes
entre eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros
existente entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.

2 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
     que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
     mostrado na funcao main().
     Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.

3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
     uma funcao para cada operacoes aritmeticas e passe como parametro os 2
     valores recebidos na funcao main(). Retorne os resultados usando o comando
     return e imprima os 4 resultados no video na funcao main().

4 - Reescreva o programa do exercicio anterior para receber via teclado n
     valores. Os n valores nao sao definidos previamente.

5 - Escreva um programa que receba n valores inteiros via teclado na funcao
main(). Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando
switch). As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve
ser mostrado na funcao main().
*/

#include <stdio.h>

#define ex5

#ifdef ex1
int eh_positivo(int num) {
  if (num == 0) {
    return -1;
  }

  return num > 0;
}

int soma_entre_numeros(int a, int b) {
  int soma = 0;
  if (a > b) {
    for (b++; b < a; b++) {
      soma += b;
    }
  } else {
    for (a++; a < b; a++) {
      soma += a;
    }
  }
  return soma;
}

int multi_entre_numeros(int a, int b) {
  int multiplicacao = 1;
  if (a < b) {
    for (a++; a < b; a++) {
      multiplicacao *= a;
    }
  } else {
    for (b++; b < a; b++) {
      multiplicacao *= b;
    }
  }
  return multiplicacao;
}

int main() {
  int num1, num2;
  char opcao;

  do {
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    int num1_eh_positivo = eh_positivo(num1);
    int num2_eh_positivo = eh_positivo(num2);

    if (num1_eh_positivo && num2_eh_positivo) {
      printf("Soma dos numeros entre eles: %d\n",
             soma_entre_numeros(num1, num2));
    } else if (!num1_eh_positivo && !num2_eh_positivo) {
      printf("Multiplicacao dos numeros entre eles: %d\n",
             multi_entre_numeros(num1, num2));
    } else if (num1_eh_positivo && !num2_eh_positivo) {
      printf("Divisao entre os numeros: %d\n", num1 / num2);
    }

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex2
int soma_dos_fat(int num) {
  int f = 1;
  for (int i = 2; i <= num; i++) {
    f *= i;
  }

  int soma = 0;
  while (f > 0) {
    soma += f % 10;
    f /= 10;
  }

  return soma;
}

int main() {
  char opcao = 's';
  do {
    int n;
    do {
      puts("Digite um numero maior que zero");
      scanf("%d", &n);
    } while (n <= 0);

    int soma = soma_dos_fat(n);
    printf("Soma de %d! é %d\n", n, soma);

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');
}
#endif

#ifdef ex3
int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }
int multiplicacao(int a, int b) { return a * b; }
int divisao(int a, int b) { return a / b; }

int main() {
  char opcao = 's';
  do {
    int num1, num2;

    printf("Digite o numero 1: ");
    scanf("%d", &num1);
    printf("Digite o numero: 2");
    scanf("%d", &num2);

    int res_soma = soma(num1, num2);
    int res_sub = subtracao(num1, num2);
    int res_mult = multiplicacao(num1, num2);
    int res_div = divisao(num1, num2);

    printf("Soma: %d\n", res_soma);
    printf("Subtracao: %d\n", res_sub);
    printf("Multiplicacao: %d\n", res_mult);
    printf("Divisao: %d\n", res_div);

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex4
int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }
int multiplicacao(int a, int b) { return a * b; }
int divisao(int a, int b) { return a / b; }

int main() {
  char opcao = 's';
  do {
    int init;
    printf("Digite um numero: ");
    scanf("%d", &init);

    int res_soma = init;
    int res_sub = init;
    int res_mult = init;
    int res_div = init;

    int n;
    while (1) {
      printf("Digite um numero (zero para parar): ");
      scanf("%d", &n);
      if (n == 0) {
        break;
      }

      res_soma = soma(res_soma, n);
      res_sub = subtracao(res_sub, n);
      res_mult = multiplicacao(res_mult, n);
      res_div = divisao(res_div, n);
    }

    printf("Soma: %d\n", res_soma);
    printf("Subtracao: %d\n", res_sub);
    printf("Multiplicacao: %d\n", res_mult);
    printf("Divisao: %d\n", res_div);

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex5
int soma(int a, int b) { return a + b; }
int subtracao(int a, int b) { return a - b; }
int multiplicacao(int a, int b) { return a * b; }
int divisao(int a, int b) { return a / b; }

int main() {
  char opcao = 's';
  do {
    int init;
    printf("Digite um numero: ");
    scanf("%d", &init);

    int n;
    int resultado = init;

    while (1) {
      printf("Digite o numero (zero para parar): ");
      scanf("%d", &n);
      if (n == 0) {
        break;
      }

      char operacao;
      printf("\nEscolha a operacao (+, -, *, /): ");
      scanf(" %c", &operacao);

      switch (operacao) {
      case '+':
        resultado = soma(resultado, n);
        break;
      case '-':
        resultado = subtracao(resultado, n);
        break;
      case '*':
        resultado = multiplicacao(resultado, n);
        break;
      case '/':
        resultado = divisao(resultado, n);
        break;
      default:
        printf("Operacao invalida!\n");
        continue;
      }
    }

    printf("Resultado final: %d\n", resultado);

    printf("Deseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif
