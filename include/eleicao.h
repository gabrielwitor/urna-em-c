/*

Arquivo header contendo as declaração das variáveis e funções relacionadas à eleição.

*/

#include <time.h>

/* Struct que armazena as informações do candidato. */
typedef struct candidato Candidato;

/* Struct da lista encadeada que armazena os candidatos. */
typedef struct lista Lista;

/* Função que retorna candidato*/
Candidato* cria_candidato(char* nome, int chapa, struct tm data_de_nascimento, char* nome_do_vice);

/* Função que cria lista (Retorna ponteiro vazio) */
Lista* criar_lista(void);

/* Função que libera a lista da memória */
void liberar_lista(Lista* lista);

/* Função que insere candidatos na lista */
Lista* insere_lista(Lista* lista, Candidato* candidato);

/* Função que retira candidatos na lista */
Lista* retira_lista(Lista* lista, int chapa);

/* Função que ordena os itens de uma lista, ordenando-os*/
Lista* ordena_lista(Lista* lista);

/* Função que verifica se a lista está vazia */
int verifica_lista_vazia(Lista* lista);

/* Função que imprime a lista */
void imprime_lista(Lista* lista);

/*Função que busca o candidato na lista, retornando o nó na lista que contem o candidato*/
Lista* busca_candidato(Lista* lista, int chapa);

/* Função que verifica datas de nascimento 
retorna 1 se a data for inválida
*/
int verifica_data_nascimento(struct tm data_nascimento, struct tm dia_atual);

/*
Adiciona um voto ao candidato do nó da lista.
*/
void adiciona_voto_candidato(Lista* lista);

int get_chapa_candidato(Lista* lista);

char* get_nome_candidato(Lista* lista);

char* get_nome_vice(Lista* lista);

/*Imprime a lista de candidatos, exibindo também a quantidade de votos*/
void imprime_lista_votos(int votos_validos, Lista* lista);

/* Retorna 1 se houver empate */
int verificar_empate(int votos_validos, Lista* lista);

/* Zera os votos e também libera os itens da lista que não são os dois primeiros candidatos */
Lista* lista_segundo_turno(Lista* lista);

/* Retorna o nó contendo os mais velho velho dos dois candidatos mais votados */
Lista* desempatar_eleicao(Lista* lista);

void imprime_boletim_primeiro_turno(Lista* lista, int votos_validos, int votos_nulos, int votos_brancos);

void imprime_boletim_segundo_turno(Lista* lista, int votos_validos, int votos_nulos, int votos_brancos);