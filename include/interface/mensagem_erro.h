/*

Header file contendo funções para mensagens de erros para a
terminal user interface (TUI) do programa "Urna em C"

Definições das cores cores ANSI obtidas em https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
Agradeço aos criadores dos sites:
- https://onlinetexttools.com/draw-box-around-text
- https://patorjk.com/software/taag/
- https://ozh.github.io/ascii-tables/
- https://www.utf8icons.com/
- https://www.compart.com/en/unicode/
- https://www.amp-what.com/unicode/
Criado por Gabriel Witor, 2024
*/

#include "ANSI-color-codes.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void erro_opcao_indisponivel(){
system("clear"); 
printf(BRED"╔ ERRO ⛌ ⛌ ⛌ ════════════════════════════════════╗\n");
printf("║                                                ║\n");
printf("║          !!!!!Opção indisponível!!!!!          ║\n");
printf("║                                                ║\n");
printf("╚════════════════════════════════════════════════╝\n"COLOR_RESET);
sleep(3);
}

void erro_entrada_invalida(){
system("clear");
printf(BRED"╔ ERRO ⛌ ⛌ ⛌ ════════════════════════════════════╗\n");
printf("║                                                ║\n");
printf("║           !!!!!Entrada inválida!!!!!           ║\n");
printf("║                                                ║\n");
printf("╚════════════════════════════════════════════════╝\n"COLOR_RESET);
sleep(3);
}

void erro_candidato_nao_encontrado(){
system("clear");
printf(BRED"╔ ERRO ⛌ ⛌ ⛌ ════════════════════════════════════╗\n");
printf("║                                                ║\n");
printf("║       !!!!!Candidato não encontrado!!!!!       ║\n");
printf("║                                                ║\n");
printf("╚════════════════════════════════════════════════╝\n"COLOR_RESET);
sleep(3);
}

void erro_chapa_ja_cadastrada(){
system("clear"); 
printf(BRED"╔ ERRO ⛌ ⛌ ⛌ ════════════════════════════════════╗\n");
printf("║                                                ║\n");
printf("║          !!!!!Chapa já cadastrada!!!!          ║\n");
printf("║                                                ║\n");
printf("╚════════════════════════════════════════════════╝\n"COLOR_RESET);
sleep(3);
}
