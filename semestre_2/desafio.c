#include <stdio.h>
#include <stdlib.h>

char nome_musica[3][20];
char nome_autor[3][20];

int tamanho_str(char str[20]) {
  int i = 0;
  for (; str[i] != '\0'; i++) {
  }
  return i;
}

void inserir_musicas() {
  for (int i = 0; i < 3; i++) {
    char musica[20];
    char autor[20];

    printf("Digite o nome da %d musica: ", i);
    scanf("%s", &nome_musica[i]);

    printf("Digite o nome do %d autor: ", i);
    scanf("%s", &nome_autor[i]);
  }
  FILE *arquivo = fopen("musicas", "w");

  for (int i = 0; i < 3; i++) {
    fwrite(nome_musica[i], sizeof(char), tamanho_str(nome_musica[i]), arquivo);
    fwrite("\t", sizeof(char), 1, arquivo);
    fwrite(nome_autor[i], sizeof(char), tamanho_str(nome_autor[i]), arquivo);
    fwrite("\n", sizeof(char), 1, arquivo);
  }

  if (fclose(arquivo) == EOF) {
    puts("Erro ao fechar o arquivo para escrita de dados, tente novamente.");
    exit(1);
  }
}

void lista_musicas() {
  for (int i = 0; i < 3; i++) {
    printf("Musica: %s | Autor: %s\n", nome_musica[i], nome_autor[i]);
  }
}

void sair(FILE *arquivo_musicas) {
  if (fclose(arquivo_musicas) == EOF) {
    puts("Erro ao fechar o arquivo para leitura de dados, tente novamente.");
    exit(1);
  } else {
    puts("Encerrando...");
    exit(0);
  }
}

void pesquisa_musica() {}

int main() {
  FILE *arquivo_musicas = fopen("musicas", "r");

  while (1) {
    puts("O que deseja fazer?");
    puts("1 - entrada de dados.");
    puts("2 - lista todos os dados na tela.");
    puts("3 - pesquisa um nome_musica pelo nome completo e mostra todos os "
         "dados na tela");
    puts("4 - pesquisa o nome_autor pela 1. letra e mostra todos os dados na "
         "tela.");
    puts("5 - altera dados. Pesquisa pelo nome_musica completo.");
    puts("6 - exclui dados. Pesquisa pelo nome_musica completo.");
    puts("7 - saida");

    int opcao = 0;
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      inserir_musicas();
      break;
    case 2:
      lista_musicas();
      break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    default:
      puts("Comando invalido");
      break;
    }
  }
}
