#include <stdio.h>
#include <stdlib.h>
#define MAX_P 10

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
                printf("Informe o nome:\n");
                scanf("%s", p[i].nome);
                printf("Informe o tempo em minutos:\n");
                scanf("%d", &p[i].tempo);
                fprintf(arq1, "NOME: %s, TEMPO: %d",p[i].nome, p[i].tempo);
                fclose(arq1);
            }
        }

    }

    return 0;
}