#include "ANSI-color-codes.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../macros.h"

void aviso_digite_informacoes(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ═══════════════════════════════════╗\n");
    printf("║                                                ║\n");
    printf("║       Digite as informações do candidato       ║\n");
    printf("║                                                ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    sleep(2);
}

void aviso_digite_nome_candidato(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ═══════════════════════════╗\n");
    printf("║       Digite o nome do candidato       ║\n");
    printf("║                                        ║\n");
    printf("║         [MÁXIMO %d CARACTERES]         ║\n",MAX_CHAR);
    printf("╚════════════════════════════════════════╝\n");
    printf("Digite: "COLOR_RESET);
    sleep(1);
}

void aviso_digite_chapa_candidato(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║       Digite a chapa do candidato       ║\n");
    printf("║                                         ║\n");
    printf("║             [ENTRE 1 e 99]              ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    printf("Digite: "COLOR_RESET);
    sleep(1);
}

void aviso_digite_data_nascimento(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ═════════════════════════════════════════╗\n");
    printf("║       Digite a data de nascimento do candidato       ║\n");
    printf("║                                                      ║\n");
    printf("║                 [FORMATO dd/mm/aaaa]                 ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
    printf("Digite: "COLOR_RESET);
    sleep(1);
}

void aviso_digite_nome_vice(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ══════════════════════╗\n");
    printf("║       Digite o nome do vice       ║\n");
    printf("║                                   ║\n");
    printf("║       [MÁXIMO %d CARACTERES]      ║\n",MAX_CHAR);
    printf("╚═══════════════════════════════════╝\n");
    printf("Digite: "COLOR_RESET);
    sleep(1);
}

void aviso_listando_candidatos(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ══════════════════════╗\n");
    printf("║                                   ║\n");
    printf("║      Listando os candidatos       ║\n");
    printf("║                                   ║\n");
    printf("╚═══════════════════════════════════╝\n\n"COLOR_RESET);
}

void aviso_pressione_qualquer_tecla(){
    printf(BYEL"\n╔ AVISO ⚠ ⚠ ⚠ ══════════════════════╗\n");
    printf("║     Pressione qualquer tecla      ║\n");
    printf("║                                   ║\n");
    printf("║          Para continuar           ║\n");
    printf("╚═══════════════════════════════════╝\n");
}

void aviso_digite_chapa_candidato_retirar(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║       Digite a chapa do candidato       ║\n");
    printf("║    a ser retirado (ação irreversível)   ║\n");
    printf("║             [ENTRE 1 e 99]              ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    printf("Digite: "COLOR_RESET);
    sleep(1);
}

void aviso_digite_chapa_candidato_votar(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ══════════════════════╗\n");
    printf("║    Digite a chapa do candidato    ║\n");
    printf("║                                   ║\n");
    printf("║    [DIGITE 0 PARA VOTAR BRANCO]   ║\n");
    printf("╚═══════════════════════════════════╝\n");
    printf("Digite: "COLOR_RESET);
    sleep(1);
}

void aviso_voto_nulo(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║                                         ║\n");
    printf("║          Registrando voto nulo          ║\n");
    printf("║                                         ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    sleep(3);
}

void aviso_voto_branco(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║                                         ║\n");
    printf("║        Registrando voto em branco       ║\n");
    printf("║                                         ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    sleep(3);
}

void aviso_voto_valido(int chapa, char* nome, char* vice){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║                                         ║\n");
    printf("║             Voto no candidato           ║\n");
    printf("║                                         ║\n");
    printf(BYEL"   ➮   Chapa: "COLOR_RESET"%d\n",chapa);
    printf(BYEL"   ➮   Nome: "COLOR_RESET"%s",nome);
    printf(BYEL"   ➮   Vice: "COLOR_RESET"%s",vice);
    printf(BYEL"║                                         ║\n");
    printf("║          Registrado com sucesso!        ║\n");
    printf("║                                         ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    sleep(2);
}

void aviso_exibindo_resultados(){
    system("clear");
    printf(BYEL"╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║                                         ║\n");
    printf("║     Exibindo os resultados da urna!     ║\n");
    printf("║                                         ║\n");
    printf("╚═════════════════════════════════════════╝\n\n"COLOR_RESET);
}

//     system("clear");
//     printf(BBLU"Digite o nome do candidato  "BWHT,MAX_CHAR);

void aviso_vencedor_eleicao(int chapa, char* nome, char* vice){
    printf(BYEL"\n╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║                                         ║\n");
    printf("║                O candidato              ║\n");
    printf("║                                         ║\n");
    printf(BYEL"   ➮   Chapa: "COLOR_RESET"%d\n",chapa);
    printf(BYEL"   ➮   Nome: "COLOR_RESET"%s",nome);
    printf(BYEL"   ➮   Vice: "COLOR_RESET"%s",vice);
    printf(BYEL"║                                         ║\n");
    printf("║             Venceu a eleição!           ║\n");
    printf("║                                         ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    sleep(2);
}

void aviso_vencedor_eleicao_empate(int chapa, char* nome, char* vice){
    printf(BYEL"\n╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║                                         ║\n");
    printf("║                O candidato              ║\n");
    printf("║                                         ║\n");
    printf(BYEL"   ➮   Chapa: "COLOR_RESET"%d\n",chapa);
    printf(BYEL"   ➮   Nome: "COLOR_RESET"%s",nome);
    printf(BYEL"   ➮   Vice: "COLOR_RESET"%s",vice);
    printf(BYEL"║                                         ║\n");
    printf("║   Venceu a eleição por ser mais velho!  ║\n");
    printf("║                                         ║\n");
    printf("╚═════════════════════════════════════════╝\n");
    sleep(2);
}


void aviso_segundo_turno(){
    printf(BYEL"\n╔ AVISO ⚠ ⚠ ⚠ ════════════════════════════╗\n");
    printf("║           Houve segundo turno,          ║\n");
    printf("║         nenhum candidato obteve         ║\n");
    printf("║        ⌊50%%⌋+1 dos votos válidos        ║\n");
    printf("╚═════════════════════════════════════════╝\n\n\a"COLOR_RESET);
    sleep(3);
}