#include "include/eleicao.h"
#include "include/macros.h"
#include "include/arquivo.h"

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct candidato{
    char nome[MAX_CHAR];
    int chapa;
    int votos;
    struct tm data_de_nascimento;
    char nome_do_vice[MAX_CHAR];
};

struct lista{
    Candidato candidato;
    Lista* prox;
};

Candidato* cria_candidato(char* nome, int chapa, struct tm data_de_nascimento, char* nome_do_vice){
    Candidato* novo_candidato = (Candidato*) malloc (sizeof(Candidato));

    if (novo_candidato == NULL){
        return NULL;
    }

    strcpy(novo_candidato->nome, nome);
    novo_candidato->chapa = chapa;
    novo_candidato->votos = 0;
    novo_candidato->data_de_nascimento.tm_mday = data_de_nascimento.tm_mday;
    novo_candidato->data_de_nascimento.tm_mon = data_de_nascimento.tm_mon;
    novo_candidato->data_de_nascimento.tm_year = data_de_nascimento.tm_year;
    strcpy(novo_candidato->nome_do_vice,nome_do_vice);

    return novo_candidato;
}

Lista* criar_lista(void){
    return NULL;
}

Lista* insere_lista(Lista* lista, Candidato* candidato){
    Lista* novo;
    Lista* anterior = NULL;
    Lista* p = lista;

    while(p != NULL && p->candidato.chapa < candidato->chapa){
        anterior = p;
        p = p->prox;
    }
    novo = (Lista*) malloc (sizeof(Lista));
    novo->candidato = *candidato;

    if(anterior == NULL){
        novo->prox = lista;
        lista = novo;
    } else {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

    return lista;
}

Lista* retira_lista(Lista* lista, int chapa){
    Lista* anterior = NULL;
    Lista* p = lista;

    while(p != NULL && p->candidato.chapa != chapa){
        anterior = p;
        p = p->prox;
    }

    if(p == NULL){
        return lista;
    }

    if(anterior == NULL){
        lista = p->prox;
    } else {
        anterior->prox = p->prox;
    }
    
    free(p);
    return lista;
}

Lista* ordena_lista(Lista* lista){
    if (lista == NULL || lista->prox == NULL) {
        return lista;  // Lista vazia ou com apenas um elemento já está ordenada
    }

    Lista* atual;
    Lista* prox_no;
    Candidato temp;

    int trocou;

    do {
        trocou = 0;
        atual = lista;

        while (atual->prox != NULL) {
            prox_no = atual->prox;

            if (atual->candidato.votos < prox_no->candidato.votos) {
                // Troca os dados dos candidatos
                temp = atual->candidato;
                atual->candidato = prox_no->candidato;
                prox_no->candidato = temp;
                
                trocou = 1;
            }

            atual = atual->prox;
        }
    } while (trocou);

    return lista;
}

int verifica_data_nascimento(struct tm dia_atual, struct tm data_nascimento){
    if(data_nascimento.tm_year > dia_atual.tm_year+1900)
        return 1;
    
    if((data_nascimento.tm_year == dia_atual.tm_year+1900) && (data_nascimento.tm_mon > dia_atual.tm_mon+1))
        return 1;

    if((data_nascimento.tm_year == dia_atual.tm_year+1900) && (data_nascimento.tm_mon == dia_atual.tm_mon+1) && (data_nascimento.tm_mday > dia_atual.tm_mday))
        return 1;

    return 0;
}

void imprime_lista(Lista* lista){
    for(Lista* lst = lista; lst != NULL; lst = lst->prox){
        printf(" - Chapa: %d | Data de Nascimento: %02d/%02d/%04d",lst->candidato.chapa,lst->candidato.data_de_nascimento.tm_mday,
        lst->candidato.data_de_nascimento.tm_mon, lst->candidato.data_de_nascimento.tm_year);

        printf(" | Nome: ");
        for(int i = 0; lst->candidato.nome[i] != '\n'; i++)
            printf("%c",lst->candidato.nome[i]);

        printf(" | Nome do vice: ");
        printf("%s",lst->candidato.nome_do_vice);
    }
}

Lista* busca_candidato(Lista* lista, int chapa){
    if (lista == NULL)
        return NULL;

    if(lista->candidato.chapa == chapa)
        return lista;

    return busca_candidato(lista->prox, chapa);
}

void adiciona_voto_candidato(Lista* lista){
    lista->candidato.votos++;
}

int get_chapa_candidato(Lista* lista){
    return lista->candidato.chapa;
}

char* get_nome_candidato(Lista* lista){
    return lista->candidato.nome;
}

char* get_nome_vice(Lista* lista){
    return lista->candidato.nome_do_vice;
}

void imprime_lista_votos(int votos_validos, Lista* lista){
    for(Lista* p = lista; p != NULL; p = p->prox){
        printf("%.2f%% dos votos válidos (%d voto(s)) | Chapa: %d | Nome: %s",((float)p->candidato.votos/votos_validos)*100.0,p->candidato.votos,p->candidato.chapa,p->candidato.nome);
    }
}

int verificar_empate(int votos_validos, Lista* lista){
    return (votos_validos >= MIN_VOTOS_VALIDOS_SEGUNDO_TURNO && lista->candidato.votos < (votos_validos*0.5 + 1));
}

Lista* lista_segundo_turno(Lista* lista){
    lista->candidato.votos = 0;
    lista->prox->candidato.votos = 0;
    liberar_lista(lista->prox->prox);
    lista->prox->prox = NULL;
    return lista;
}

void liberar_lista(Lista* lista){
    Lista* t;
    Lista* p = lista;
    while (p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}

Lista* desempatar_eleicao(Lista* lista){
    if(lista->candidato.data_de_nascimento.tm_year > lista->prox->candidato.data_de_nascimento.tm_year)
        return lista;
    if(lista->candidato.data_de_nascimento.tm_year < lista->prox->candidato.data_de_nascimento.tm_year)
        return lista->prox;
    
    if((lista->candidato.data_de_nascimento.tm_year == lista->prox->candidato.data_de_nascimento.tm_year) && (lista->candidato.data_de_nascimento.tm_mon > lista->prox->candidato.data_de_nascimento.tm_mon))
        return lista;

    if((lista->candidato.data_de_nascimento.tm_year == lista->prox->candidato.data_de_nascimento.tm_year) && (lista->candidato.data_de_nascimento.tm_mon < lista->prox->candidato.data_de_nascimento.tm_mon))
        return lista->prox;

    if((lista->candidato.data_de_nascimento.tm_year == lista->prox->candidato.data_de_nascimento.tm_year) && (lista->candidato.data_de_nascimento.tm_mon == lista->prox->candidato.data_de_nascimento.tm_mon) && 
    (lista->candidato.data_de_nascimento.tm_mday > lista->prox->candidato.data_de_nascimento.tm_mday))
        return lista;

    if((lista->candidato.data_de_nascimento.tm_year == lista->prox->candidato.data_de_nascimento.tm_year) && (lista->candidato.data_de_nascimento.tm_mon == lista->prox->candidato.data_de_nascimento.tm_mon) && 
    (lista->candidato.data_de_nascimento.tm_mday < lista->prox->candidato.data_de_nascimento.tm_mday))
        return lista;

    return 0;
}

void imprime_boletim_primeiro_turno(Lista* lista, int votos_validos, int votos_nulos, int votos_brancos){
    FILE* arquivo = abreArquivoEscrita("boletim_primeiro_turno.txt");

    fprintf(arquivo,"Resultado do primeiro turno:\n\n");

    for(Lista* p = lista; p != NULL; p = p->prox){
        fprintf(arquivo,"Chapa: %d | %d votos (%.2f%% dos votos validos) | Nome do candidato: %s",p->candidato.chapa,p->candidato.votos, ((float)p->candidato.votos/votos_validos)*100.0, p->candidato.nome);
    }

    fprintf(arquivo,"\nNúmero de votos brancos: %d\n",votos_brancos);
    fprintf(arquivo,"\nNúmero de votos nulos: %d\n",votos_nulos);
    fprintf(arquivo,"\nNúmero de votos válidos: %d\n",votos_validos);
    fprintf(arquivo,"\nNúmero de votos totais: %d\n",votos_brancos+votos_nulos+votos_validos);
    fprintf(arquivo,"\nPorcentagem de votos válidos: %.2f%% dos votos totais\n",((float)votos_validos/(votos_brancos+votos_nulos+votos_validos))*100);

    if(verificar_empate(votos_validos,lista))
        fprintf(arquivo,"Haverá segundo turno.");

    fclose(arquivo);
}

void imprime_boletim_segundo_turno(Lista* lista, int votos_validos, int votos_nulos, int votos_brancos){
    FILE* arquivo = abreArquivoEscrita("boletim_segundo_turno.txt");

    fprintf(arquivo,"Resultado do segundo turno:\n\n");

    for(Lista* p = lista; p != NULL; p = p->prox){
        fprintf(arquivo,"Chapa: %d | %d votos (%.2f%% dos votos validos) | Nome do candidato: %s",p->candidato.chapa,p->candidato.votos, ((float)p->candidato.votos/votos_validos)*100.0, p->candidato.nome);
    }

    fprintf(arquivo,"\nNúmero de votos brancos: %d\n",votos_brancos);
    fprintf(arquivo,"\nNúmero de votos nulos: %d\n",votos_nulos);
    fprintf(arquivo,"\nNúmero de votos válidos: %d\n",votos_validos);
    fprintf(arquivo,"\nNúmero de votos totais: %d\n",votos_brancos+votos_nulos+votos_validos);
    fprintf(arquivo,"\nPorcentagem de votos válidos: %.2f%% dos votos totais\n",((float)votos_validos/(votos_brancos+votos_nulos+votos_validos))*100);

    fclose(arquivo);
}