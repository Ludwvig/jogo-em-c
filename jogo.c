
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[40];
    char tipo[10]; 
    int quantidade;
} Item;


int main () {



Item *criarItem(const char *nome, const char *tipo) {
    Item *novo = malloc(sizeof(Item));
    if (!novo) return NULL; 
    strncpy(novo->nome, nome, sizeof(novo->nome)-1); 
    novo->nome[sizeof(novo->nome)-1] = '\0'; 
    strncpy(novo->tipo, tipo, sizeof(novo->tipo)-1); 
    novo->tipo[sizeof(novo->tipo)-1] = '\0';
    novo->proximo = NULL;
    return novo;
}

void mostrarMochila(Item *inicio) {
    int i = 1;
    while (inicio != NULL);
    printf("%d. %s (%s)\n", inicio->nome, inicio->tipo);
    inicio = inicio->proximo;
}


} 