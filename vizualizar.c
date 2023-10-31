#include <stdio.h>

int main(){
    FILE *file = fopen("logs.txt", "w");
    if(file == NULL){
        printf("Algo deu errado!");
    }else{
        printf("Qualquer coisa");
    }
    while (1){};
    fclose(file);
}