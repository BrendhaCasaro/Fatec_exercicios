/*
1 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.

2 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.

3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.

4 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.

5 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.
*/

#include <math.h>
#include <stdio.h>

#define ex1

#ifdef ex1
int main() {
  int dia, mes, ano;
  char opcao;

  do {
    printf("Digite a data (dia, mes, ano): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    if (mes < 3) {
      mes += 12;
      ano--;
    }
    int k = ano % 100;
    int j = ano / 100;
    int h = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;

    const char *diasSemana[] = {"Sábado", "Domingo", "Segunda", "Terça",
                                "Quarta", "Quinta",  "Sexta"};
    printf("O dia da semana é: %s\n", diasSemana[h]);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex2
int main() {
  int diaNasc, mesNasc, anoNasc;
  int diaAtual, mesAtual, anoAtual;
  char opcao;

  do {
    printf("Digite a data de nascimento (dia, mes, ano): ");
    scanf("%d %d %d", &diaNasc, &mesNasc, &anoNasc);
    printf("Digite a data atual (dia, mes, ano): ");
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

    // Calculando a idade
    int idadeAno = anoAtual - anoNasc;
    int idadeMes = mesAtual - mesNasc;
    int idadeDia = diaAtual - diaNasc;

    if (idadeDia < 0) {
      idadeDia += 30; // Ajuste para o dia
      idadeMes--;
    }

    if (idadeMes < 0) {
      idadeMes += 12; // Ajuste para o mês
      idadeAno--;
    }

    printf("Idade: %d anos, %d meses e %d dias\n", idadeAno, idadeMes,
           idadeDia);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex3
int main() {
  int num1, num2;
  char opcao;

  do {
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("Operações lógicas bit a bit:\n");

    printf("AND (decimal): %d, AND (hexadecimal): %X\n", num1 & num2,
           num1 & num2);
    printf("OR (decimal): %d, OR (hexadecimal): %X\n", num1 | num2,
           num1 | num2);
    printf("XOR (decimal): %d, XOR (hexadecimal): %X\n", num1 ^ num2,
           num1 ^ num2);

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex4
int main() {
  int num1, num2;
  char opcao;

  do {
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("Operações aritméticas:\n");
    printf("Soma: %d\n", num1 + num2);
    printf("Subtração: %d\n", num1 - num2);
    printf("Multiplicação: %d\n", num1 * num2);
    if (num2 != 0) {
      printf("Divisão: %.2f\n", (float)num1 / num2);
    } else {
      printf("Divisão: Não é possível dividir por zero!\n");
    }

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif

#ifdef ex5
int main() {
  int num1, num2;
  char opcao;

  do {
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("Operações aritméticas utilizando operadores compostos:\n");
    num1 += num2;
    printf("Soma: %d\n", num1);
    num1 -= num2;
    printf("Subtração: %d\n", num1);
    num1 *= num2;
    printf("Multiplicação: %d\n", num1);
    if (num2 != 0) {
      num1 /= num2;
      printf("Divisão: %.2f\n", (float)num1);
    } else {
      printf("Divisão: Não é possível dividir por zero!\n");
    }

    printf("\nDeseja executar novamente? (s/n): ");
    scanf(" %c", &opcao);
  } while (opcao == 's' || opcao == 'S');

  return 0;
}
#endif
