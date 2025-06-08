#include <stdio.h>
#include <string.h>

typedef struct {
  char musica[50];
  char autor[50];
  int estoque;
  float preco;
} Registro;

void entradaDados(Registro *r) {
  FILE *arquivo;
  Registro temp;
  int achou = 0;

  printf("Nome da m\u00fasica: ");
  scanf(" %[^\n]", r->musica);
  printf("Autor: ");
  scanf(" %[^\n]", r->autor);
  printf("Quantidade em estoque: ");
  scanf("%d", &r->estoque);
  if (r->estoque == 10)
    r->estoque = 11;
  printf("Pre\u00e7o: ");
  scanf("%f", &r->preco);

  arquivo = fopen("musicas.dat", "ab+");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  rewind(arquivo);
  while (fread(&temp, sizeof(Registro), 1, arquivo) == 1) {
    if (strcmp(temp.musica, r->musica) == 0) {
      achou = 1;
      break;
    }
  }

  if (achou) {
    printf("M\u00fasica j\u00e1 cadastrada.\n");
  } else {
    fwrite(r, sizeof(Registro), 1, arquivo);
    printf("M\u00fasica cadastrada com sucesso!\n");
  }

  fclose(arquivo);
}

void listarMusicas() {
  FILE *arquivo;
  Registro r;

  arquivo = fopen("musicas.dat", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    printf("\nM\u00fasica: %s\nAutor: %s\nEstoque: %d\nPre\u00e7o: %.2f\n",
           r.musica, r.autor, r.estoque, r.preco);
  }

  fclose(arquivo);
}

void pesquisarNome() {
  FILE *arquivo;
  Registro r;
  char nome[50];
  int achou = 0;

  printf("Digite o nome da m\u00fasica: ");
  scanf(" %[^\n]", nome);

  arquivo = fopen("musicas.dat", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (strcmp(r.musica, nome) == 0) {
      printf("\nM\u00fasica: %s\nAutor: %s\nEstoque: %d\nPre\u00e7o: %.2f\n",
             r.musica, r.autor, r.estoque, r.preco);
      achou = 1;
      break;
    }
  }

  if (!achou) {
    printf("M\u00fasica n\u00e3o encontrada.\n");
  }

  fclose(arquivo);
}

void pesquisarAutorLetra() {
  FILE *arquivo;
  Registro r;
  char letra;
  int encontrou = 0;

  printf("Digite a primeira letra do autor: ");
  scanf(" %c", &letra);

  arquivo = fopen("musicas.dat", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (r.autor[0] == letra) {
      printf("\nM\u00fasica: %s\nAutor: %s\nEstoque: %d\nPre\u00e7o: %.2f\n",
             r.musica, r.autor, r.estoque, r.preco);
      encontrou = 1;
    }
  }

  if (!encontrou) {
    printf("Nenhum autor encontrado.\n");
  }

  fclose(arquivo);
}

void listarPorPreco() {
  FILE *arquivo;
  Registro r;
  float min, max;
  int encontrou = 0;

  printf("Pre\u00e7o m\u00ednimo: ");
  scanf("%f", &min);
  printf("Pre\u00e7o m\u00e1ximo: ");
  scanf("%f", &max);

  arquivo = fopen("musicas.dat", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (r.preco >= min && r.preco <= max) {
      printf("\nM\u00fasica: %s\nAutor: %s\nEstoque: %d\nPre\u00e7o: %.2f\n",
             r.musica, r.autor, r.estoque, r.preco);
      encontrou = 1;
    }
  }

  if (!encontrou) {
    printf("Nenhuma m\u00fasica na faixa de pre\u00e7o informada.\n");
  }

  fclose(arquivo);
}

void alteraEstoque() {
  FILE *arquivo;
  Registro r;
  char nome[50];
  int qtd, achou = 0;
  long pos;

  printf("Digite o nome da m\u00fasica: ");
  scanf(" %[^\n]", nome);

  arquivo = fopen("musicas.dat", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (!achou && fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (strcmp(r.musica, nome) == 0) {
      pos = ftell(arquivo) - sizeof(Registro);
      printf("Quantidade atual: %d\n", r.estoque);
      printf("Digite a quantidade a alterar: ");
      scanf("%d", &qtd);
      r.estoque += qtd;
      if (r.estoque == 10)
        r.estoque++;
      fseek(arquivo, pos, SEEK_SET);
      fwrite(&r, sizeof(Registro), 1, arquivo);
      printf("Estoque atualizado.\n");
      achou = 1;
    }
  }

  if (!achou) {
    printf("M\u00fasica n\u00e3o encontrada.\n");
  }

  fclose(arquivo);
}

void alteraPreco() {
  FILE *arquivo;
  Registro r;
  char nome[50];
  float novo;
  long pos;
  int achou = 0;

  printf("Digite o nome da m\u00fasica: ");
  scanf(" %[^\n]", nome);

  arquivo = fopen("musicas.dat", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (!achou && fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (strcmp(r.musica, nome) == 0) {
      pos = ftell(arquivo) - sizeof(Registro);
      printf("Pre\u00e7o atual: %.2f\n", r.preco);
      printf("Novo pre\u00e7o: ");
      scanf("%f", &novo);
      r.preco = novo;
      fseek(arquivo, pos, SEEK_SET);
      fwrite(&r, sizeof(Registro), 1, arquivo);
      printf("Pre\u00e7o atualizado.\n");
      achou = 1;
    }
  }

  if (!achou) {
    printf("M\u00fasica n\u00e3o encontrada.\n");
  }

  fclose(arquivo);
}

void alteraTodosDados() {
  FILE *arquivo;
  Registro r;
  char nome[50];
  long pos;
  int achou = 0;

  printf("Digite o nome da m\u00fasica a alterar: ");
  scanf(" %[^\n]", nome);

  arquivo = fopen("musicas.dat", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  while (!achou && fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (strcmp(r.musica, nome) == 0) {
      pos = ftell(arquivo) - sizeof(Registro);
      printf("Novo nome da m\u00fasica: ");
      scanf(" %[^\n]", r.musica);
      printf("Novo autor: ");
      scanf(" %[^\n]", r.autor);
      printf("Nova quantidade: ");
      scanf("%d", &r.estoque);
      if (r.estoque == 10)
        r.estoque++;
      printf("Novo pre\u00e7o: ");
      scanf("%f", &r.preco);
      fseek(arquivo, pos, SEEK_SET);
      fwrite(&r, sizeof(Registro), 1, arquivo);
      printf("Dados atualizados.\n");
      achou = 1;
    }
  }

  if (!achou) {
    printf("M\u00fasica n\u00e3o encontrada.\n");
  }

  fclose(arquivo);
}

void excluirMusica() {
  FILE *arquivo;
  FILE *temp;
  Registro r;
  char nome[50];
  int achou = 0;

  printf("Digite o nome da m\u00fasica a excluir: ");
  scanf(" %[^\n]", nome);

  arquivo = fopen("musicas.dat", "rb");
  temp = fopen("temporario.dat", "wb");

  if (arquivo == NULL || temp == NULL) {
    printf("Erro ao abrir arquivos.\n");
    return;
  }

  while (fread(&r, sizeof(Registro), 1, arquivo) == 1) {
    if (strcmp(r.musica, nome) != 0) {
      fwrite(&r, sizeof(Registro), 1, temp);
    } else {
      achou = 1;
    }
  }

  fclose(arquivo);
  fclose(temp);

  if (achou) {
    remove("musicas.dat");
    rename("temporario.dat", "musicas.dat");
    printf("M\u00fasica exclu\u00edda com sucesso.\n");
  } else {
    remove("temporario.dat");
    printf("M\u00fasica n\u00e3o encontrada.\n");
  }
}

int main() {
  char opcao;

  do {
    printf("\nMenu de Músicas:\n");
    printf("1 - Cadastrar música\n");
    printf("2 - Listar todas as músicas\n");
    printf("3 - Pesquisar música por nome\n");
    printf("4 - Pesquisar músicas por primeira letra do autor\n");
    printf("5 - Listar músicas por faixa de preço\n");
    printf("6 - Alterar estoque\n");
    printf("7 - Alterar preço\n");
    printf("8 - Alterar todos os dados da música\n");
    printf("9 - Excluir música\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &opcao);

    switch (opcao) {
    case '1': {
      Registro r;
      entradaDados(&r);
      break;
    }
    case '2':
      listarMusicas();
      break;
    case '3':
      pesquisarNome();
      break;
    case '4':
      pesquisarAutorLetra();
      break;
    case '5':
      listarPorPreco();
      break;
    case '6':
      alteraEstoque();
      break;
    case '7':
      alteraPreco();
      break;
    case '8':
      alteraTodosDados();
      break;
    case '9':
      excluirMusica();
      break;
    case '0':
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != '0');

  return 0;
}
