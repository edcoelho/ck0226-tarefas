#ifndef CADEIA_H
#define CADEIA_H

// Retorna o tamanho da cadeia de caracteres s, sem contabilizar o ‘\0’ do final.
int str_tamanho(char *s);

// Copia, caractere a caractere, o conteúdo da cadeia de caracteres s para a cadeia de caracteres d.
void str_copiar(char *s, char *d);

// Concatena o conteúdo da cadeia de caracteres s no final da cadeia de caracteres d.
void str_concatenar(char *s, char *d);

#endif