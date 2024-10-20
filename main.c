#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/interface/telas.h"
#include "include/interface/mensagem_erro.h"
#include "include/interface/mensagem_aviso.h"

#include "include/eleicao.h"
#include "include/arquivo.h"

#include "include/macros.h"

int main(){
    int houve_segundo_turno = 0;

    int numero_candidatos = 0;

    int votos_validos = 0;
    int votos_brancos = 0;
    int votos_nulos = 0;

    int opcao;

    struct tm dia_atual = get_struct_dia_atual();
    
    Lista* lista = criar_lista();
    Lista* buscar;

    char nome[MAX_CHAR];
    int chapa;
    struct tm data_nascimento;
    char nome_vice[MAX_CHAR];

    /* Inicio do programa */

    tela_inicial(dia_atual);
    getchar();

    tela_opcoes:
    tela_opcoes(numero_candidatos);
    opcao = get_opcoes();

    switch (opcao){
    case (1):
        goto tela_gerenciar_candidatos;
    case (2):
        goto tela_gerenciar_votacao;
    case (3):
        goto encerrar;
    default:
        erro_opcao_indisponivel();
        goto tela_opcoes;
    }

    tela_gerenciar_candidatos:
    tela_gerenciar_candidatos(numero_candidatos);
    opcao = get_opcoes();

    switch (opcao){
    case (1):
        if(numero_candidatos != 99){
           goto adicionar_candidato;
        } else {
            erro_opcao_indisponivel();
            goto tela_gerenciar_candidatos;
        }
    case (2):
        if(numero_candidatos != 0){
            goto retirar_candidato;
        } else {
            erro_opcao_indisponivel();
            goto tela_gerenciar_candidatos;
        }
    case (3):
        if(numero_candidatos != 0){
            goto listar_candidatos;
        } else {
            erro_opcao_indisponivel();
            goto tela_gerenciar_candidatos;
        }
    case (4):
        goto tela_opcoes;
    default:
        erro_opcao_indisponivel();
        goto tela_opcoes;
    }

    adicionar_candidato:
    aviso_digite_informacoes();
    getchar();

    aviso_digite_nome_candidato();
    fgets(nome,MAX_CHAR,stdin);
    imprime_candidato_formatado(nome);

    chapa:
    aviso_digite_chapa_candidato();
    scanf("%d",&chapa);
    if(chapa < 1 || chapa > 99){
        erro_entrada_invalida();
        goto chapa;
    }
    buscar = busca_candidato(lista, chapa);
    if(buscar != NULL){
        erro_chapa_ja_cadastrada();
        goto chapa;
    }

    data_nascimento:
    aviso_digite_data_nascimento();
    scanf("%d/%d/%d",&data_nascimento.tm_mday,&data_nascimento.tm_mon,&data_nascimento.tm_year);

    if(verifica_data_nascimento(dia_atual, data_nascimento)){
        erro_entrada_invalida();
        goto data_nascimento;
    }

    aviso_digite_nome_vice();
    getchar();
    fgets(nome_vice,MAX_CHAR,stdin);

    lista = insere_lista(lista, cria_candidato(nome,chapa,data_nascimento,nome_vice));
    numero_candidatos++;
    goto tela_gerenciar_candidatos;

    listar_candidatos:
    aviso_listando_candidatos();
    imprime_lista(lista);
    aviso_pressione_qualquer_tecla();
    
    getchar(); getchar();
    goto tela_gerenciar_candidatos;

    retirar_candidato:
    aviso_digite_chapa_candidato_retirar();
    scanf("%d",&chapa);
    if(chapa < 1 || chapa > 99){
        erro_entrada_invalida();
        goto tela_gerenciar_candidatos;
    }
    if(busca_candidato(lista, chapa) != NULL){
        lista = retira_lista(lista,chapa);
    } else {
        erro_candidato_nao_encontrado();
        goto tela_gerenciar_candidatos;
    }

    numero_candidatos--;
    goto tela_gerenciar_candidatos;
    
    tela_gerenciar_votacao:
    
    tela_gerenciar_votacao(votos_validos);
    opcao = get_opcoes();

    switch (opcao){
    case (1):
        aviso_digite_chapa_candidato_votar();
        scanf("%d",&chapa);
        if(chapa == 0){
            aviso_voto_branco();
            votos_brancos++;
        } else {
            buscar = busca_candidato(lista, chapa);
            if(buscar != NULL){
                aviso_voto_valido(chapa, get_nome_candidato(buscar),get_nome_vice(buscar));
                adiciona_voto_candidato(buscar);
                votos_validos++;
            } else {
                aviso_voto_nulo();
                votos_nulos++;
            }
        }
        goto tela_gerenciar_votacao;

    case (2):
        if(votos_validos != 0){
            lista = ordena_lista(lista);
            aviso_exibindo_resultados();
            imprime_lista_votos(votos_validos, lista);
            aviso_pressione_qualquer_tecla();
            getchar();getchar();
            
            if(verificar_empate(votos_validos,lista)){
                if(houve_segundo_turno){

                    Lista* candidato_mais_velho = desempatar_eleicao(lista);
                    aviso_vencedor_eleicao_empate(get_chapa_candidato(candidato_mais_velho),get_nome_candidato(candidato_mais_velho),get_nome_vice(candidato_mais_velho));

                    imprime_boletim_segundo_turno(lista, votos_validos, votos_nulos, votos_brancos);
                    goto encerrar;
                    
                } else {

                    imprime_boletim_primeiro_turno(lista,votos_validos,votos_nulos,votos_brancos);

                    aviso_segundo_turno();

                    votos_validos = 0;
                    votos_brancos = 0;
                    votos_nulos = 0;

                    houve_segundo_turno = 1;

                    lista = lista_segundo_turno(lista);

                    goto tela_gerenciar_votacao;
                }

            }
            aviso_vencedor_eleicao(get_chapa_candidato(lista),get_nome_candidato(lista),get_nome_vice(lista));

            if(houve_segundo_turno){
                    imprime_boletim_segundo_turno(lista,votos_validos,votos_nulos,votos_brancos);
                    goto encerrar;
            }

            imprime_boletim_primeiro_turno(lista,votos_validos,votos_nulos,votos_brancos);
            goto encerrar;
            

        } else {
            erro_opcao_indisponivel();
            goto tela_gerenciar_votacao;
        }

    case (3):
        goto encerrar;
    default:
        erro_opcao_indisponivel();
        goto tela_gerenciar_votacao;
    }

    encerrar:
    liberar_lista(lista);
    return 0;
}