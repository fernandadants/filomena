#include <stdio.h>
#include <string.h>

struct Pessoa {
  char nome[20]; //nome do usuário
  int tempo; //tempo em minutos
};

const int maxPessoas = 10; // Número máximo de pessoas a serem armazenadas
Pessoa pessoas[maxPessoas]; // Array de structs Pessoa
int numPessoas = 0; // Contador de pessoas armazenadas

int primeiro_i = 0; // Índice do primeiro elemento na fila
int ultimo_i = 0; // Índice do último elemento na fila

//Adiciona a pessoa no fim da lista
void enqueue(const Pessoa &p) {
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