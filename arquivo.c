#include "include/arquivo.h"

#include <stdio.h>
#include <string.h>

FILE* abreArquivoEscrita(char* nome_do_arquivo){
    FILE * file_pointer;
    file_pointer = fopen(nome_do_arquivo,"w");
    return file_pointer;
}