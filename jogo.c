#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char nome[40];
    char tipo[10]; 
    int quantidade;
    struct Item *proximo; 
} Item;

Item *inicio = NULL;
Item *anterior = NULL;

Item *criarItem(const char *nome, const char *tipo) {
    Item *novo = malloc(sizeof(Item));
    if (!novo) return NULL; 
    strncpy(novo->nome, nome, sizeof(novo->nome)-1); 
    novo->nome[sizeof(novo->nome)-1] = '\0'; 
    strncpy(novo->tipo, tipo, sizeof(novo->tipo)-1); 
    novo->tipo[sizeof(novo->tipo)-1] = '\0';
    novo->proximo = NULL;
    novo->quantidade = 1;
    printf("Item adicionado.\n");
    return novo;
}

void percorrerLista(Item *inicio) {
    Item *atual = inicio; 
    int i = 1; 
    while (atual != NULL) {
        
    }

}

Item *removerItem ()

void mostrarMochila(Item *inicio) {
    int i = 1;
    while (inicio != NULL) {
        printf("%d. %s (%s)\n", i, inicio->nome, inicio->tipo);
        inicio = inicio->proximo;
        i++;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        char nome[40];
        char tipo[10];
        snprintf(nome, sizeof(nome), "Item%d", i+1);
        snprintf(tipo, sizeof(tipo), "Item%d", i+1);

        Item *novo = criarItem(nome, tipo); 
        if (inicio == NULL) {
            inicio = novo; 
        } else {
            anterior->proximo = novo;
        } 
        anterior = novo;
    }

    printf("\nConteúdo da mochila:\n");
    mostrarMochila(inicio);

    return 0;
}