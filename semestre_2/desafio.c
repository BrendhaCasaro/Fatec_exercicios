#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nome_musica[3][20];
char nome_autor[3][20];

void salva_arquivo() {
  FILE *arquivo = fopen("musicas", "w");

  fwrite(nome_musica, sizeof(nome_musica), 1, arquivo);
  fwrite(nome_autor, sizeof(nome_autor), 1, arquivo);

  if (fclose(arquivo) == EOF) {
    puts("Erro ao fechar o arquivo para escrita de dados, tente novamente.");
    exit(1);
  }
}

int verificar_string(char str1[20], char str2[20]) {
  for (int i = 0; i < 20; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
    if (str1[i] == '\0' || str2[i] == '\0') {
      break;
    }
  }

  return 1;
}

void inserir_musicas() {
  for (int i = 0; i < 3; i++) {
    printf("Digite o nome da %d musica: ", i + 1);
    scanf("%s", nome_musica[i]);

    printf("Digite o nome do %d autor: ", i + 1);
    scanf("%s", nome_autor[i]);
  }

  salva_arquivo();
}

void lista_musicas() {
  for (int i = 0; i < 3; i++) {
    if (nome_musica[i][0] == '*') {
      continue;
    }
    printf("Musica: %s | Autor: %s\n", nome_musica[i], nome_autor[i]);
  }
}

#include <stdio.h>
#include <stdlib.h>

char nome_musica[3][20];
char nome_autor[3][20];

void salva_arquivo() {
  FILE *arquivo = fopen("musicas", "w");

  fwrite(nome_musica, sizeof(nome_musica), 1, arquivo);
  fwrite(nome_autor, sizeof(nome_autor), 1, arquivo);

  if (fclose(arquivo) == EOF) {
    puts("Erro ao fechar o arquivo para escrita de dados, tente novamente.");
    exit(1);
  }
}

int verificar_string(char str1[20], char str2[20]) {
  for (int i = 0; i < 20; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
    if (str1[i] == '\0' || str2[i] == '\0') {
      break;
    }
  }

  return 1;
}

void inserir_musicas() {
  for (int i = 0; i < 3; i++) {
    printf("Digite o nome da %d musica: ", i + 1);
    gets(nome_musica[i]);

    printf("Digite o nome do %d autor: ", i + 1);
    gets(nome_autor[i]);
  }

  salva_arquivo();
}

void lista_musicas() {
  for (int i = 0; i < 3; i++) {
    if (nome_musica[i][0] == '*') {
      continue;
    }
    printf("Musica: %s | Autor: %s\n", nome_musica[i], nome_autor[i]);
  }
}

void pesquisa_autor() {
  printf("Digite a primeira letra do autor: ");
  char letra;
  scanf(" %c", &letra);

  int encontrou = 0;
  for (int i = 0; i < 3; i++) {
    if (nome_autor[i][0] == letra) {
      encontrou = 1;
      printf("Musica: %s | Autor: %s\n", nome_musica[i], nome_autor[i]);
    }
  }

  if (encontrou == 0) {
    puts("Nenhum autor encontrado.");
  }
}

void altera_dados() {
  printf("Digite o nome da musica que deseja alterar: ");
  char musica[20];
  gets(musica);

  int mudancas = 0;
  for (int i = 0; i < 3; i++) {
    if (verificar_string(musica, nome_musica[i])) {
      mudancas = 1;
      printf("Digite o novo nome da musica: ");
      gets(nome_musica[i]);

      printf("Digite o novo nome do autor: ");
      gets(nome_autor[i]);
    }
  }

  if (mudancas == 1) {
    salva_arquivo();
  } else {
    puts("Nenhuma musica com esse nome foi encontrada.");
  }
}

void exclui_dados() {
  printf("Digite o nome da musica que deseja excluir: ");
  char musica[20];
  gets(musica);

  int mudancas = 0;
  for (int i = 0; i < 3; i++) {
    if (verificar_string(musica, nome_musica[i])) {
      mudancas = 1;
      nome_musica[i][0] = '*';
    }
  }

  if (mudancas == 1) {
    salva_arquivo();
  } else {
    puts("Nenhuma musica com esse nome foi encontrada.");
  }
}

int main() {
  FILE *arquivo_musicas = fopen("musicas", "r");
  fread(nome_musica, sizeof(nome_musica), 1, arquivo_musicas);
  fread(nome_autor, sizeof(nome_autor), 1, arquivo_musicas);
  fclose(arquivo_musicas);

  while (1) {
    puts("\nO que deseja fazer?");
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
    scanf(" %d", &opcao);
    getchar();

    switch (opcao) {
    case 1:
      inserir_musicas();
      break;
    case 2:
      lista_musicas();
      break;
    case 3:
      pesquisa_musica();
      break;
    case 4:
      pesquisa_autor();
      break;
    case 5:
      altera_dados();
      break;
    case 6:
      exclui_dados();
      break;
    case 7:
      puts("Encerrando...");
      exit(0);
      break;
    default:
      puts("Comando invalido");
      break;
    }
  }
}
