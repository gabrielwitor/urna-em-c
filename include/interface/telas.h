/*

Header file contendo funções para imprimir as telas para a
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
#include "../macros.h"
#include "../eleicao.h"

#include "funcoes_auxiliares.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A função recebe uma struct tm para mostrar o dia atual
*/
void tela_inicial(struct tm dia_atual){
    system("clear");
    printf(BBLU"┏ URNA EM C 🖳 🖳 🖳 ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                         %02d/%02d/%d                                      ┃\n",dia_atual.tm_mday,dia_atual.tm_mon+1,dia_atual.tm_year+1900);
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃"HBLU"                     _   _                                     _____ TM                  ┃\n");
    printf("┃"HBLU"                    | | | |                                   /  __ \\                    ┃\n");
    printf("┃"HBLU"                    | | | |_ __ _ __   __ _    ___ _ __ ___   | /  \\/                    ┃\n");
    printf("┃"HBLU"                    | | | | '__| '_ \\ / _` |  / _ \\ '_ ` _ \\  | |                        ┃\n");
    printf("┃"HBLU"                    | |_| | |  | | | | (_| | |  __/ | | | | | | \\__/\\                    ┃\n");
    printf("┃"HBLU"                     \\___/|_|  |_| |_|\\__,_|  \\___|_| |_| |_|  \\____/                    "BBLU"┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf(BBLU"┃                       "reset BLUB"╔══════════════════════════════════════════╗"reset BBLU"                      ┃\n");
    printf(BBLU"┃                       "reset BLUB"║Pressione qualquer tecla para continuar...║"reset BBLU"                      ┃\n");
    printf(BBLU"┃                       "reset BLUB"╚══════════════════════════════════════════╝"reset BBLU"                      ┃\n");
    printf(reset BBLU"┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                             Criado por Gabriel Witor (2024)                             ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"COLOR_RESET);
}

void tela_opcoes(int numero_candidatos){
    system("clear");
    printf(BBLU"┏ TELA DE OPÇõES ⌂ ⌂ ⌂ ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                             "reset BLUB"╔════════════════════════════╗"reset BBLU"                              ┃\n");
    printf("┃                             "reset BLUB"║Pressione a opção que deseja║"reset BBLU"                              ┃\n");
    printf("┃                             "reset BLUB"╚════════════════════════════╝"reset BBLU"                              ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃    "reset BLUB"[1]"reset BWHT" - Gerenciar candidatos 🛠                                                         "BBLU"┃\n");
    printf("┃                                                                                         ┃\n");
    if(numero_candidatos != 0){
        printf("┃    "reset BLUB"[2]"reset BWHT" - Iniciar votação 🏳                                                              "BBLU"┃\n");
    } else {
        printf("┃    "reset REDB"[2]"reset BWHT" - Iniciar votação 🏳  "BRED"(Impossível pois não há candidatos registrados)             "BBLU"┃\n");
    }
    printf("┃                                                                                         ┃\n");
    printf("┃    "reset BLUB"[3]"reset BWHT" - Sair ↩                                                                         "BBLU"┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"COLOR_RESET);
}

void tela_gerenciar_candidatos(int numero_candidatos){
    system("clear");
    printf(BBLU"┏ GERENCIAR CANDIDATOS 🛠 🛠 🛠  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                             "reset BLUB"╔════════════════════════════╗"reset BBLU"                              ┃\n");
    printf("┃                             "reset BLUB"║Pressione a opção que deseja║"reset BBLU"                              ┃\n");
    printf("┃                             "reset BLUB"╚════════════════════════════╝"reset BBLU"                              ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                  Candidatos: "reset BWHT"[%02d/%02d]"reset BBLU"                                    ┃\n",numero_candidatos,MAX_CANDIDATOS);
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    if(numero_candidatos != 99){
        printf("┃    "reset BLUB"[1]"reset BWHT" - Adicionar candidato +                                                          "BBLU"┃\n");
    } else {
        printf("┃    "reset REDB"[1]"reset BWHT" - Adicionar candidato + "BRED"(Impossível pois o limite foi atingido)                  "BBLU"┃\n");
    }
    printf("┃                                                                                         ┃\n");
    if(numero_candidatos != 0){
        printf("┃    "reset BLUB"[2]"reset BWHT" - Retirar candidato -                                                            "BBLU"┃\n");
    } else {
        printf("┃    "reset REDB"[2]"reset BWHT" - Retirar candidato - "BRED"(Impossível pois não há candidatos registrados)            "BBLU"┃\n");
    }
    printf("┃                                                                                         ┃\n");
    if(numero_candidatos != 0){
        printf("┃    "reset BLUB"[3]"reset BWHT" - Listar candidatos 𝄚                                                            "BBLU"┃\n");
    } else {
        printf("┃    "reset REDB"[3]"reset BWHT" - Listar candidatos 𝄚 "BRED"(Impossível pois não há candidatos registrados)            "BBLU"┃\n");
    }
    printf("┃                                                                                         ┃\n");
    printf("┃    "reset BLUB"[4]"reset BWHT" - Voltar ↩                                                                       "BBLU"┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"COLOR_RESET);
}


void tela_gerenciar_votacao(int votos_validos){
    system("clear");
    printf(BBLU"┏ GERENCIAR VOTACAO 🏳 🏳 🏳  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                             "reset BLUB"╔════════════════════════════╗"reset BBLU"                              ┃\n");
    printf("┃                             "reset BLUB"║Pressione a opção que deseja║"reset BBLU"                              ┃\n");
    printf("┃                             "reset BLUB"╚════════════════════════════╝"reset BBLU"                              ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃    "reset BLUB"[1]"reset BWHT" - Adicionar voto 📩                                                              "BBLU"┃\n");
    printf("┃                                                                                         ┃\n");
    if(votos_validos != 0){
        printf("┃    "reset BLUB"[2]"reset BWHT" - Encerrar  votação 💾                                                           "BBLU"┃\n");
    } else{
        printf("┃    "reset REDB"[2]"reset BWHT" - Encerrar  votação 💾 "BRED"(Impossível pois não há votos válidos)                    "BBLU"┃\n");
    }
    printf("┃                                                                                         ┃\n");
    printf("┃    "reset BLUB"[3]"reset BWHT" - Sair ↩                                                                         "BBLU"┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┃                                                                                         ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"COLOR_RESET);
}
