#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX_PESSOAS 10

typedef struct{
  char nome[20]; //nome do usuário
  int tempo; //tempo em minutos
} Pessoa;

Pessoa pessoas[MAX_PESSOAS]; // Array de structs Pessoa
int numPessoas = 0; // Contador de pessoas armazenadas

int primeiro_i = 0; // Índice do primeiro elemento na fila
int ultimo_i = 0; // Índice do último elemento na fila
int cont = 0;

int adicionar_log(Pessoa p){
  FILE *file = fopen("./data/logs.txt", "w");
  if(file == NULL){
    printf("Error: Carregamento de 'file.txt'");
    return -1;
  }
  fseek(file, 0, SEEK_END);
  fprintf(file, "%s, %d", p.nome, p.tempo);
  fclose(file);
  return 0;
}

int carregar_arquivo(){
  FILE *file = fopen("fila.txt", "w");
  if (file == NULL){
    printf("Error: Carregamento de 'file.txt'");
    return -1;
  }

  for(int i = 0; i<numPessoas; i++){
    fprintf(file, "%s, %d", pessoas[i].nome, pessoas[i].tempo);
  }
  return 0;

  fclose(file);
}

//Adiciona a pessoa no fim da lista
void enqueue(Pessoa p) {
  if (numPessoas < MAX_PESSOAS) {
    pessoas[ultimo_i] = p;
    ultimo_i = (ultimo_i + 1) % MAX_PESSOAS; // Circular, para reutilizar espaço
    numPessoas++;
  }
  carregar_arquivo();
}

//Retorna a pessoa mais antiga da lista
Pessoa dequeue() {
    if (numPessoas > 0) {
        Pessoa p = pessoas[primeiro_i];
        // Mover todos os outros elementos para frente
        for (int i = 0; i < numPessoas - 1; i++) {
            int atual = (primeiro_i + i) % MAX_PESSOAS;
            int proximo = (primeiro_i + i + 1) % MAX_PESSOAS;
            pessoas[atual] = pessoas[proximo];
        }
        // Decrementar o número de pessoas na fila
        numPessoas--;

        adicionar_log(p);
        // Retornar a pessoa removida
        return p;
    }
    // Retorne uma pessoa vazia se a fila estiver vazia
    Pessoa vazia;
    strcpy(vazia.nome, "");
    vazia.tempo = 0;
    return vazia;

    carregar_arquivo();
}

int displayQueue(){
  FILE *file = fopen("./data/fila.txt", "r");
  if (file == NULL){
    printf("Erro: fila.txt");
    return -1;
  }

  char linha [100];

  printf("\n----------- FILA -----------\n");
  
  while(fscanf(file, "%[^,], %d\n", pessoas[cont].nome, &pessoas[cont].tempo) == 2){
    printf("%-20s | 0%d:00\n", pessoas[cont].nome, pessoas[cont].tempo);
    printf("---------------------+------\n");
    cont ++;
  }

  fclose(file);

  return 0; 
}

int counter(char name[], int tam, int time) {

  // tam o numero de vezes que vai ser rodado o contador
  // time o tempo que deseja rodar no contador (minutos)
  // name o nome do usuario

  int contador = 0;

  for (size_t i = 0; i < tam; i++) {
    
    time = 5;
    //time = time*60;

    while (contador != time) {
      contador++;
      printf("%d\n", contador);
      Sleep(1);

      if (contador + 1 == time) {
        printf("Time's up %s!\n", name);
        return 1;
        //  maneira de indicar que o tempo do contador do microondas acabou
      }
    }
  }
}