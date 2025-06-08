#include <stdio.h>
#include <string.h>

#define EX1

#ifdef EX1
void recebeDados(char *c, int *i, long *l, float *f, double *d,
                 unsigned char *uc, unsigned int *ui, unsigned long *ul) {
  printf("Digite um char: ");
  scanf(" %c", c);
  printf("Digite um int: ");
  scanf("%d", i);
  printf("Digite um long: ");
  scanf("%ld", l);
  printf("Digite um float: ");
  scanf("%f", f);
  printf("Digite um double: ");
  scanf("%lf", d);
  printf("Digite um unsigned char: ");
  scanf(" %c", uc);
  printf("Digite um unsigned int: ");
  scanf("%u", ui);
  printf("Digite um unsigned long: ");
  scanf("%lu", ul);
}

void imprimeDados(char c, int i, long l, float f, double d, unsigned char uc,
                  unsigned int ui, unsigned long ul) {
  printf("    char      int       long                float               "
         "double\n");
  printf("          unsigned char       unsigned int        unsigned long\n");
  printf("    %4c    %8d    %10ld    %20.2f    %20.2lf\n", c, i, l, f, d);
  printf("          %8c    %15u    %15lu\n", uc, ui, ul);
}

int main() {
  char opcao = 'n';
  do {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
    recebeDados(&c, &i, &l, &f, &d, &uc, &ui, &ul);
    imprimeDados(c, i, l, f, d, uc, ui, ul);

    printf("\nVocê deseja sair do programa? Digite s ou n: ");
    scanf(" %c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif

#ifdef EX2
int comparaStrings(char *s1, char *s2) { return strcmp(s1, s2) == 0 ? 1 : 0; }

int main() {
  char opcao = 'n';
  do {
    char str1[11], str2[11];
    printf("Digite a primeira string: ");
    scanf("%10s", str1);
    printf("Digite a segunda string: ");
    scanf("%10s", str2);

    if (comparaStrings(str1, str2))
      printf("Strings IGUAIS\n");
    else
      printf("Strings DIFERENTES\n");

    printf("Você deseja sair do programa? Digite s ou n: ");
    scanf(" %c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif

#ifdef EX3
void receberValor(float *valor, char *operacao) {
  printf("Digite um valor: ");
  scanf("%f", valor);
  printf("Digite a operacao (+, -, *, /) ou = para finalizar: ");
  scanf(" %c", operacao);
}

void executarOperacao(float *resultado, float valor, char operacao) {
  switch (operacao) {
  case '+':
    *resultado += valor;
    break;
  case '-':
    *resultado -= valor;
    break;
  case '*':
    *resultado *= valor;
    break;
  case '/':
    if (valor != 0)
      *resultado /= valor;
    break;
  }
}

int main() {
  char opcao = 'n';
  do {
    float resultado = 0, valor = 0;
    char operacao = '+';
    while (operacao != '=') {
      receberValor(&valor, &operacao);
      if (operacao != '=')
        executarOperacao(&resultado, valor, operacao);
    }
    printf("Resultado acumulado: %.2f\n", resultado);

    printf("Você deseja sair do programa? Digite s ou n: ");
    scanf(" %c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif

#ifdef EX4
int pesquisarLetra(char *letra, char *vetor) {
  for (int i = 0; i < 13; i++) {
    if (*(vetor + i) == *letra)
      return 1;
  }
  return 0;
}

int main() {
  char opcao = 'n';
  do {
    char letra;
    char vetor[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm',
                    'o', 'q', 's', 'u', 'w', 'y'};
    printf("Digite uma letra: ");
    scanf(" %c", &letra);
    if (pesquisarLetra(&letra, vetor))
      printf("Letra encontrada no vetor\n");
    else
      printf("Letra NÃO encontrada\n");
    printf("Você deseja sair do programa? Digite s ou n: ");
    scanf(" %c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif

#ifdef EX5
typedef struct {
  char nome[50];
  char end[50];
  char cidade[30];
  char estado[3];
  char cep[10];
} Registro;

void preencher(Registro *r) {
  for (int i = 0; i < 4; i++) {
    printf("Registro %d:\n", i + 1);
    printf("Nome: ");
    scanf(" %[^\n]", r[i].nome);
    printf("Endereco: ");
    scanf(" %[^\n]", r[i].end);
    printf("Cidade: ");
    scanf(" %[^\n]", r[i].cidade);
    printf("Estado: ");
    scanf(" %2s", r[i].estado);
    printf("CEP: ");
    scanf(" %9s", r[i].cep);
  }
}

void imprimir(Registro *r) {
  for (int i = 0; i < 4; i++) {
    printf("Registro %d:\n", i + 1);
    printf("Nome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCEP: %s\n\n",
           r[i].nome, r[i].end, r[i].cidade, r[i].estado, r[i].cep);
  }
}

int main() {
  char opcao = 'n';
  do {
    Registro registros[4];
    int escolha;
    do {
      printf("1 - Preencher\n2 - Imprimir\n3 - Sair\nEscolha: ");
      scanf("%d", &escolha);
      getchar();
      switch (escolha) {
      case 1:
        preencher(registros);
        break;
      case 2:
        imprimir(registros);
        break;
      case 3:
        break;
      default:
        printf("Opcao invalida\n");
      }
    } while (escolha != 3);
    printf("Você deseja sair do programa? Digite s ou n: ");
    scanf(" %c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif

#ifdef EX6
typedef struct {
  char nome[50];
  char end[50];
  char cidade[30];
  char estado[3];
  char cep[10];
} Registro;

void preencher(Registro *r) {
  for (int i = 0; i < 4; i++) {
    printf("Registro %d:\n", i + 1);
    printf("Nome: ");
    scanf(" %[^\n]", r[i].nome);
    printf("Endereco: ");
    scanf(" %[^\n]", r[i].end);
    printf("Cidade: ");
    scanf(" %[^\n]", r[i].cidade);
    printf("Estado: ");
    scanf(" %2s", r[i].estado);
    printf("CEP: ");
    scanf(" %9s", r[i].cep);
  }
}

void imprimir(Registro *r) {
  for (int i = 0; i < 4; i++) {
    if (r[i].nome[0] != '\0') {
      printf("Registro %d:\n", i + 1);
      printf("Nome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCEP: %s\n\n",
             r[i].nome, r[i].end, r[i].cidade, r[i].estado, r[i].cep);
    }
  }
}

void procurar(Registro *r) {
  char nome[50];
  printf("Digite o nome para procurar: ");
  scanf(" %[^\n]", nome);
  for (int i = 0; i < 4; i++) {
    if (strcmp(r[i].nome, nome) == 0) {
      printf("Encontrado:\n%s, %s, %s, %s, %s\n", r[i].nome, r[i].end,
             r[i].cidade, r[i].estado, r[i].cep);
      return;
    }
  }
  printf("Registro nao encontrado\n");
}

void alterar(Registro *r) {
  char nome[50];
  printf("Digite o nome para alterar: ");
  scanf(" %[^\n]", nome);
  for (int i = 0; i < 4; i++) {
    if (strcmp(r[i].nome, nome) == 0) {
      printf("Novo endereco: ");
      scanf(" %[^\n]", r[i].end);
      printf("Nova cidade: ");
      scanf(" %[^\n]", r[i].cidade);
      printf("Novo estado: ");
      scanf(" %2s", r[i].estado);
      printf("Novo CEP: ");
      scanf(" %9s", r[i].cep);
      return;
    }
  }
  printf("Registro nao encontrado\n");
}

void excluir(Registro *r) {
  char nome[50];
  printf("Digite o nome para excluir: ");
  scanf(" %[^\n]", nome);
  for (int i = 0; i < 4; i++) {
    if (strcmp(r[i].nome, nome) == 0) {
      r[i].nome[0] = '\0';
      printf("Registro excluido\n");
      return;
    }
  }
  printf("Registro nao encontrado\n");
}

int main() {
  char opcao = 'n';
  do {
    Registro registros[4];
    int preenchido = 0;
    int escolha;
    do {
      printf("1 - Preencher\n2 - Imprimir\n3 - Procurar\n4 - Alterar\n5 - "
             "Excluir\n6 - Sair\nEscolha: ");
      scanf("%d", &escolha);
      getchar();
      switch (escolha) {
      case 1:
        preencher(registros);
        preenchido = 1;
        break;
      case 2:
        if (preenchido)
          imprimir(registros);
        else
          printf("Registros vazios\n");
        break;
      case 3:
        if (preenchido)
          procurar(registros);
        else
          printf("Registros vazios\n");
        break;
      case 4:
        if (preenchido)
          alterar(registros);
        else
          printf("Registros vazios\n");
        break;
      case 5:
        if (preenchido)
          excluir(registros);
        else
          printf("Registros vazios\n");
        break;
      case 6:
        break;
      default:
        printf("Opcao invalida\n");
      }
    } while (escolha != 6);
    printf("Você deseja sair do programa? Digite s ou n: ");
    scanf(" %c", &opcao);
    getchar();
  } while (opcao == 'n');
  return 0;
}
#endif
