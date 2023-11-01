#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_P 10
#define LEN 1001

typedef struct {
    char nome[20];
    int tempo;
} Pessoa, *ptrPessoa;

int main()
{
  Pessoa p[MAX_P];
  FILE *arq1;
  char s;
  int escolha;

  printf("Deseja realizar uma ação?\n");
  scanf(" %c", &s);

  for(int i = 0; i < MAX_P; i++)
  {
    if(s == 's')
      {
            printf("Escolha a ação: 1-Cadastrar, 2-Remover, 3-Editar\n");
            scanf("%d", &escolha);
            if(escolha == 1)
            {
                arq1 = fopen("logs.txt", "r+");
                if(arq1 == NULL)
                {
                    printf("Falha ao registrar logs!");
                }
                fseek(arq1, 0, SEEK_END);
                printf("Informe o nome:\n");
                scanf("%s", p[i].nome);
                printf("Informe o tempo em minutos:\n");
                scanf("%d", &p[i].tempo);
                fprintf(arq1, "NOME: %s, TEMPO: %d \n",p[i].nome, p[i].tempo);
                fclose(arq1);
            }
          if(escolha == 2){
            int linha;
            arq1 = fopen("logs.txt", "r+");
            FILE *output = fopen("transferindo.txt", "w");

            printf("Digite a linha a ser apagada no arquivo: ");
            scanf("%d", &linha);
            
            fseek(arq1, 0, SEEK_SET);
            int linha_atual = 1;
            char texto[LEN] = "";
            char texto_[LEN] = "";

            for(int j = 0; !feof(arq1);j++){
              memset(texto, '\0', LEN);
              fgets(texto, LEN, arq1);
              if(linha_atual == linha){
                fputs(texto_, output);
                linha_atual++;
                continue;
              }
              linha_atual = linha_atual + 1; 
              fputs(texto, output);
            }
            fclose(arq1);
            fclose(output);
            remove("logs.txt");
            rename("transferindo.txt", "logs.txt");

          }
            
        }
      }
  return 0;
    }
