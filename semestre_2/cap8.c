#include <stdio.h>

#define ex1

#ifdef ex1

/*
 1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/

void main() {
  char opcao = 'n';
  do {
    char c, *pc = &c;
    int i, *pi = &i;
    long l, *pl = &l;
    unsigned u, *pu = &u;
    float f, *pf = &f;
    double d, *pd = &d;
    unsigned long ul, *pul = &ul;
    unsigned char uc, *puc = &uc;

    printf("Digite um int: ");
    scanf("%d", pi);
    printf("Digite um long: ");
    scanf("%ld", pl);
    printf("Digite um unsigned: ");
    scanf("%u", pu);
    printf("Digite um float: ");
    scanf("%f", pf);
    printf("Digite um double: ");
    scanf("%lf", pd);
    printf("Digite um char: ");
    scanf(" %c", pc);
    printf("Digite um unsigned long: ");
    scanf("%lu", pul);
    printf("Digite um unsigned char: ");
    scanf(" %c", puc);

    printf("\n        int                 long                unsigned\n");
    printf("%10d%20ld%20u\n", *pi, *pl, *pu);

    printf("              float               double              char\n");
    printf("%20.2f%20.2lf%20c\n", *pf, *pd, *pc);

    printf("         unsigned long       unsigned char\n");
    printf("%20lu%20c\n", *pul, *puc);

    puts("");
    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
}
#endif // ex1

#ifdef ex2
/*
2 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e
calcula a media dos valores digitados e mostrar o resultado. Todos os calculos
devem ser feitos usando ponteiro.

*/

int main() {
  char opcao = 'n';
  do {
    int num, *pnum = &num;
    int soma = 0, count = 0;
    int *psoma = &soma, *pcount = &count;

    while (1) {
      printf("Digite um numero positivo (negativo para sair): ");
      scanf("%d", pnum);
      if (*pnum < 0)
        break;
      *psoma += *pnum;
      (*pcount)++;
    }

    if (*pcount > 0)
      printf("Media: %.2f\n", (float)(*psoma) / *pcount);
    else
      printf("Nenhum valor positivo digitado.\n");

    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif // ex2

#ifdef ex3

/*
3 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faca uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel
global
*/

char str1[11], str2[11];

int compara(char *a, char *b) {
  while (*a && *b) {
    if (*a != *b)
      return 0;
    a++;
    b++;
  }
  return *a == *b;
}
int main() {
  char opcao == 'n';
  do {
    printf("Digite a primeira string: ");
    scanf("%10s", str1);
    printf("Digite a segunda string: ");
    scanf("%10s", str2);

    if (compara(str1, str2))
      printf("Resultado: IGUAIS (1)\n");
    else
      printf("Resultado: DIFERENTES (0)\n");

    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
}
#endif // ex3

#ifdef ex4

/*
4 - Escreva um programa que receba uma letra via teclado usando ponteiro.
Escreva uma funcao que pesquise esta letra existe no vetor abaixo usando
ponteiros. Imprima o resultado da pesquisa no video na funcao main(). Passe como
    informacao para a funcao a letra digitada. (utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

char letras[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm',
                 'o', 'q', 's', 'u', 'w', 'y'};

int pesquisa(char *letra) {
  for (int i = 0; i < 13; i++) {
    if (*letra == *(letras + i))
      return 1;
  }
  return 0;
}

int main() {
  char opcao = 'n';
  do {
    char l;
    printf("Digite uma letra: ");
    scanf(" %c", &l);

    if (pesquisa(&l))
      printf("Letra encontrada no vetor.\n");
    else
      printf("Letra NAO encontrada no vetor.\n");

    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');

  return 0;
}

#endif // ex4

#ifdef ex5

/*
5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa funcao usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep
*/

struct pessoa {
  char nome[50];
  char end[50];
  char cidade[30];
  char estado[3];
  char cep[10];
};

struct pessoa agenda[4];

void ler(struct pessoa *p) {
  for (int i = 0; i < 4; i++) {
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: ");
    scanf(" %[^\n]", (p + i)->nome);
    printf("Endereco: ");
    scanf(" %[^\n]", (p + i)->end);
    printf("Cidade: ");
    scanf(" %[^\n]", (p + i)->cidade);
    printf("Estado (UF): ");
    scanf(" %2s", (p + i)->estado);
    printf("CEP: ");
    scanf(" %9s", (p + i)->cep);
  }
}

void imprimir(struct pessoa *p) {
  for (int i = 0; i < 4; i++) {
    printf("\nPessoa %d:\n", i + 1);
    printf("Nome: %s\n", (p + i)->nome);
    printf("Endereco: %s\n", (p + i)->end);
    printf("Cidade: %s\n", (p + i)->cidade);
    printf("Estado: %s\n", (p + i)->estado);
    printf("CEP: %s\n", (p + i)->cep);
  }
}
int main() {
  char opcao = 'n';
  do {
    ler(agenda);
    imprimir(agenda);

    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');

  return 0;
}

#endif

#ifdef ex6

/*
6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
        estrutura: dia, mes e ano
*/

struct data {
  int dia, mes, ano;
};

int calculaDias(struct data *d1, struct data *d2) {
  int total1 = d1->ano * 365 + d1->mes * 30 + d1->dia;
  int total2 = d2->ano * 365 + d2->mes * 30 + d2->dia;
  int diff = total1 - total2;
  return diff < 0 ? -diff : diff;
}

int main() {
  char opcao = 'n';
  do {
    struct data datas[2];

    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &datas[0].dia, &datas[0].mes, &datas[0].ano);

    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &datas[1].dia, &datas[1].mes, &datas[1].ano);

    int dias = calculaDias(&datas[0], &datas[1]);
    printf("Numero de dias entre as datas: %d\n", dias);

    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');

  return 0;
}
#endif
