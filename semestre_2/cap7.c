#include <stdio.h>
#include <string.h>
#include <time.h>

#define ex3

#ifdef ex1
/* 1 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faca um menu com uma opcao para saida do programa.
        estrutura: nome, end, cidade, estado, cep
*/

typedef struct {
  char nome[50];
  char end[50];
  char cidade[50];
  char estado[50];
  char cep[50];
} Pessoa;

void recebeDados(Pessoa *p) {

  puts("Digite seu nome: ");
  fgets(p->nome, 50, stdin);
  p->nome[strcspn(p->nome, "\n")] = 0;

  puts("Digite seu endereço: ");
  fgets(p->end, 50, stdin);
  p->end[strcspn(p->end, "\n")] = 0;

  puts("Digite seu cidade: ");
  fgets(p->cidade, 50, stdin);
  p->cidade[strcspn(p->cidade, "\n")] = 0;

  puts("Digite seu estado: ");
  fgets(p->estado, 50, stdin);
  p->estado[strcspn(p->estado, "\n")] = 0;

  puts("Digite seu cep: ");
  fgets(p->cep, 50, stdin);
  p->cep[strcspn(p->cep, "\n")] = 0;
}

void mostraDados(Pessoa *p) {
  printf("\n--- Dados armazenados ---\n");
  printf("Nome: %s\n", p->nome);
  printf("Endereço: %s\n", p->end);
  printf("Cidade: %s\n", p->cidade);
  printf("Estado: %s\n", p->estado);
  printf("Cep: %s\n", p->cep);
}

void main() {
  char opcao = 'n';
  do {

    Pessoa pessoas[4];

    for (int i = 0; i < 4; i++) {
      recebeDados(&pessoas[i]);
    }

    for (int i = 0; i < 4; i++) {
      mostraDados(&pessoas[i]);
    }
    puts("");
    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
}
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
          estrutura: dia, mes, ano
*/

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

time_t calculaData(Data *d) {
  struct tm t = {0};
  t.tm_mday = d->dia;
  t.tm_mon = d->mes;
  t.tm_year = d->ano - 1900;
  return mktime(&t);
}

void main() {
  char opcao = 'n';
  do {
    Data data[2];

    for (int i = 0; i < 2; i++) {
      puts("Digite o dia");
      scanf("%d", &data[i].dia);

      puts("Digite o mês");
      scanf("%d", &data[i].mes);
      data[i].mes--;

      puts("Digite o ano");
      scanf("%d", &data[i].ano);
    }

    time_t t1 = calculaData(&data[0]);
    time_t t2 = calculaData(&data[1]);

    double segundos = difftime(t2, t1);
    int dias = segundos / (60 * 60 * 24);

    if (dias < 0)
      dias = -dias;

    printf("\nDiferença entre as datas: %d dias\n", dias);
    puts("");
    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
}

#endif // ex2

#ifdef ex3
/*3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/

typedef struct {
  char c;
  int i;
  long l;
  float f;
  double d;
  unsigned char uc;
  unsigned int ui;
  unsigned long ul;
} Dados;

void recebeDados(Dados *d) {
  printf("Digite um char: ");
  scanf(" %c", &d->c);
  getchar();

  printf("Digite um int: ");
  scanf("%d", &d->i);

  printf("Digite um long: ");
  scanf("%ld", &d->l);

  printf("Digite um float: ");
  scanf("%f", &d->f);

  printf("Digite um double: ");
  scanf("%lf", &d->d);

  printf("Digite um unsigned char: ");
  scanf(" %c", &d->uc);

  printf("Digite um unsigned int: ");
  scanf("%u", &d->ui);

  printf("Digite um unsigned long: ");
  scanf("%lu", &d->ul);
}

void mostraDados(Dados d) {
  printf("\n        10        20        30        40        50        60       "
         " 70\n");
  printf("123456789012345678901234567890123456789012345678901234567890123456789"
         "0\n");

  printf("%10c%10d%10ld%20.2f%20.2lf\n", d.c, d.i, d.l, d.f, d.d);
  printf("%20c%20u%20lu\n", d.uc, d.ui, d.ul);
}

int main() {
  char opcao = 'n';
  do {
    Dados d;

    recebeDados(&d);
    mostraDados(d);

    puts("");
    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif // ex3

#ifdef ex4
/*4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/

#define TAM 4

typedef struct {
  char nome[50];
  float peso;
  float altura;
} Pessoa;

void receberDados(Pessoa pessoas[]) {
  for (int i = 0; i < TAM; i++) {
    printf("\nPessoa %d:\n", i + 1);

    printf("Nome: ");
    getchar();
    fgets(pessoas[i].nome, 50, stdin);
    pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

    printf("Peso (kg): ");
    scanf("%f", &pessoas[i].peso);

    printf("Altura (m): ");
    scanf("%f", &pessoas[i].altura);
  }
}

void mostrarDados(Pessoa pessoas[]) {
  printf("\n--- Dados das Pessoas ---\n");
  for (int i = 0; i < TAM; i++) {
    printf("Pessoa %d\n", i + 1);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Peso: %.2f kg\n", pessoas[i].peso);
    printf("Altura: %.2f m\n\n", pessoas[i].altura);
  }
}

void calcularIMC(Pessoa pessoas[]) {
  printf("\n--- IMC das Pessoas ---\n");
  for (int i = 0; i < TAM; i++) {
    float imc = pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura);
    printf("%s: IMC = %.2f\n", pessoas[i].nome, imc);
  }
}

int main() {
  char opcao = 'n';
  do {
    Pessoa pessoas[TAM];
    int opcao;

    do {
      printf("\nMenu:\n");
      printf("1 - Receber todos os dados\n");
      printf("2 - Imprimir todos os dados\n");
      printf("3 - Calcular IMC de todas as pessoas\n");
      printf("4 - Sair\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        receberDados(pessoas);
        break;
      case 2:
        mostrarDados(pessoas);
        break;
      case 3:
        calcularIMC(pessoas);
        break;
      case 4:
        printf("Encerrando programa...\n");
        break;
      default:
        printf("Opcao invalida. Tente novamente.\n");
      }
    } while (opcao != 4);

    puts("");
    puts("Você deseja sair do programa? Digite s ou n");
    scanf("%c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif // ex4
