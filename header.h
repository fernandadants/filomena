#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LEN 1001
#define MAX_PESSOAS 10

typedef struct {
  char nome[20]; // nome do usuário
  int tempo;     // tempo em minutos
} Pessoa, *ptrPessoa;

Pessoa pessoas[MAX_PESSOAS]; // Array de structs Pessoa
int numPessoas = 0;          // Contador de pessoas armazenadas

int cont = 0;

// Função para zerar as informações cadastradas na fila e enviar relátorio para o log
void zera() {

  FILE *arq2 = fopen("logs.txt", "a");
  FILE *arq1 = fopen("fila.txt", "w");

  while (fgetc(arq1) != EOF) {
    fputs("", arq1);
  }

  fputs("O Arquivo FILA foi apagado\n", arq2);
  fclose(arq2);
  fclose(arq1);
}

// Função para apagar usuário da lista
void apaga_log(int linha) {

  FILE *arq1 = fopen("fila.txt", "r+");
  FILE *arq2 = fopen("logs.txt", "w");
  FILE *output = fopen("transferindo.txt", "w");

  fseek(arq1, 0, SEEK_SET);
  int linha_atual = 1;
  char texto[LEN] = "";
  char texto_[LEN] = "";

  for (int j = 0; !feof(arq1); j++) {
    memset(texto, '\0', LEN);
    fgets(texto, LEN, arq1);
    if (linha_atual == linha) {
      fputs(texto_, output);
      linha_atual++;
      continue;
    }
    linha_atual = linha_atual + 1;
    fputs(texto, output);
  }
  fprintf(arq2, "O Usuario %d foi REMOVIDO\n", linha);
  fclose(arq2);
  fclose(arq1);
  fclose(output);
  remove("fila.txt");
  rename("transferindo.txt", "fila.txt");
}

// Função para adicionar pessoa na lista
int adicionar_log(Pessoa p) {

  FILE *arq1 = fopen("logs.txt", "a");
  if (arq1 == NULL) {
    printf("Falha ao registrar logs!");
  }

  FILE *file = fopen("fila.txt", "a");
  if (file == NULL) {
    printf("Error: Carregamento de 'file.txt'");
    return -1;
  }

  fprintf(file, "%s, %d\n", p.nome, p.tempo);
  fprintf(arq1, "%s, %d\n", p.nome, p.tempo);
  fclose(file);
  fclose(arq1);
  return 0;
}

// Função para editar usuário da lista
void editar_log() {

  int linha;
  char novo_nome[LEN];
  char novo_tempo[LEN];
  FILE *arq1 = fopen("fila.txt", "r");
  FILE *output = fopen("transferindo.txt", "w");

  printf("Digite o numero do usuario a ser editado: ");
  scanf("%d", &linha);

  printf("Digite o novo nome: ");
  scanf("%s", novo_nome);

  printf("Digite o novo tempo: ");
  scanf("%s", novo_tempo);

  fseek(arq1, 0, SEEK_SET);
  int linha_atual = 1;
  char texto[LEN] = "";
  char texto_[LEN] = "";

  strcat(texto_, novo_nome);
  strcat(texto_, ", ");
  strcat(texto_, novo_tempo);
  strcat(texto_, "\n");

  for (int j = 0; !feof(arq1); j++) {
    memset(texto, '\0', LEN);
    fgets(texto, LEN, arq1);
    if (linha_atual == linha) {
      fputs(texto_, output);
      linha_atual++;
      continue;
    }
    linha_atual = linha_atual + 1;
    fputs(texto, output);
  }
  fclose(arq1);
  fclose(output);
  remove("fila.txt");
  rename("transferindo.txt", "fila.txt");
}

// Função para contar tempo da primeira pessoa da lista
void counter() {

  FILE *arq1 = fopen("fila.txt", "r");
  int contador = 0;
  const int bar_width = 50;
  Pessoa fila;

  if (fgetc(arq1) == EOF) {
    printf("\nNao ha NENHUMA pessoa na fila!\n\n");
    return;
  }

  fseek(arq1, 0, SEEK_SET);
  fscanf(arq1, "%[^,], %d\n", fila.nome, &fila.tempo);

  while (contador != fila.tempo) {

    contador++;
    sleep(1);

    float progress = (float)contador / fila.tempo;
    int bar_length = progress * bar_width;

    printf("\rProgresso: [");
    for (int i = 0; i < bar_length; ++i) {
      printf("#");
    }
    for (int i = bar_length; i < bar_width; ++i) {
      printf(" ");
    }
    printf("] %.2f%%", progress * 100);

    fflush(stdout);

    if (contador == fila.tempo) {
      printf("\nAcabou o tempo de %s!\n", fila.nome);
      apaga_log(1);
    }
  }
  fclose(arq1);
}