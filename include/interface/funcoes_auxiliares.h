#include <stdio.h>
#include <time.h>

#include "../eleicao.h"

/*
Retorna uma struct do dia atual
*/
struct tm get_struct_dia_atual(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm;
}

int get_opcoes(){
    char opcao[255];
    scanf("%s",opcao);

    switch (opcao[0]){
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    default:
        return -1;
    }
}

void imprime_candidato_formatado (char * nome){
    int i = 0;
    int TAMANHO_MAX = 15;

    for(; i < TAMANHO_MAX && (nome[i] != '\n'); i++){
        printf("%c",nome[i]);
    }

    for(int espacos_vazios_counter = i+1; espacos_vazios_counter > 0; espacos_vazios_counter--){
        printf(" ");
    }

    printf("|\n");
}