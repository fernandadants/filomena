#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX_PESSOAS 10

typedef struct{
  char nome[20]; //nome do usuário
  int tempo; //tempo em minutos
} Pessoa;

int maxPessoas = 10; // Número máximo de pessoas a serem armazenadas
Pessoa pessoas[MAX_PESSOAS]; // Array de structs Pessoa
int numPessoas = 0; // Contador de pessoas armazenadas

int primeiro_i = 0; // Índice do primeiro elemento na fila
int ultimo_i = 0; // Índice do último elemento na fila
int cont = 0;

//Adiciona a pessoa no fim da lista
void enqueue(Pessoa p) {
  if (numPessoas < maxPessoas) {
    pessoas[ultimo_i] = p;
    ultimo_i = (ultimo_i + 1) % maxPessoas; // Circular, para reutilizar espaço
    numPessoas++;
  }
}

//Retorna a pessoa mais antiga da lista
Pessoa dequeue() {
    if (numPessoas > 0) {
        Pessoa p = pessoas[primeiro_i];
        // Mover todos os outros elementos para frente
        for (int i = 0; i < numPessoas - 1; i++) {
            int atual = (primeiro_i + i) % maxPessoas;
            int proximo = (primeiro_i + i + 1) % maxPessoas;
            pessoas[atual] = pessoas[proximo];
        }
        // Decrementar o número de pessoas na fila
        numPessoas--;
        // Retornar a pessoa removida
        return p;
    }
    // Retorne uma pessoa vazia se a fila estiver vazia
    Pessoa vazia;
    strcpy(vazia.nome, "");
    vazia.tempo = 0;
    return vazia;
}

int displayQueue(){
  FILE *file = fopen("./data/fila.txt", "r");
  if (file == NULL){
    printf("Erro: fila.txt");
    return -1;
  }

  char linha [100];

  printf("\n----------- FILA -----------\n");
  
  while(fgets(linha, 100, file) != NULL){
    printf("%s\n", linha);
  }

  printf("-----------------------------");
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