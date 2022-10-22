#include "cadeia.h"

int str_tamanho(char *s){
    int i = 0;
    
    while(s[i] != '\0'){
        i++;
    }

    return i;
}

void str_copiar(char *s, char *d){
    while(*s != '\0'){
        *d = *s;
        d++;
        s++;
    }

    *d = '\0';
}

// Concatena o conteúdo da cadeia de caracteres s no final da cadeia de caracteres d.
void str_concatenar(char *s, char *d){
    d = d + str_tamanho(d);
        
    while(*s != '\0'){
        *d = *s;
        d++;
        s++;
    }

    *d = '\0';
}