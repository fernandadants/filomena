#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int num_t = 0;
  Pessoa p[LEN];
  int escolha;

  while (1) {

    printf("-------- MENU -------\n");
    printf("1 ......... Cadastrar\n");
    printf("2 ........... Remover\n");
    printf("3 ............ Editar\n");
    printf("4 . Iniciar(CONTAGEM)\n");
    printf("5 .............. Sair\n");
    scanf("%d", &escolha);
    if (escolha == 1) {
      zera();

      printf("Quantas pessoas voce deseja adicionar?");
      scanf("%d", &num_t);

      for (int i = 0; i < num_t; i++) {
        printf("Informe o nome:\n");
        scanf("%s", p[i].nome);
        printf("Informe o tempo em minutos:\n");
        scanf("%d", &p[i].tempo);
        adicionar_log(p[i]);
      }
    } else if (escolha == 2) {

      int linha = 0;
      printf("Digite o numero do usuario a ser removido: ");
      scanf("%d", &linha);
      apaga_log(linha);

    } else if (escolha == 3) {

      editar_log();

    } else if (escolha == 4) {

      counter();

    } else if (escolha == 5) {
      printf("Encerrando o programa.");
      zera();
      break;
    } else {
      printf("Opção invalida, por favor atente-se às opções");
    }
  }
}