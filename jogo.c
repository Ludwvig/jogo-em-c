#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item {
    char nome[40];
    char tipo[10]; 
    int quantidade;
    struct Item *proximo; 
} Item;
// ponteiro: uma variável que pode guardar o endereço do qual se refere (do lado esquerdo do *) 


Item *inicio = NULL;
Item *anterior = NULL;

// checklist: 
// 1- criar função que retorne um ponteiro para um Item 
// 2- cria um ponteiro novo que pode apontar pra um Item
// 3- verifica se tem memória 
// 4- copia os caracteres de cada argumento e garante que o usuário só vai preencher até o penúltimo
// 5- acessa o último caractere e coloca um '\0', fim da leitura 
// 6- 

Item *criarItem(const char *nome, const char *tipo) { // adicionar parâmetros e tipos de cada um, utilizando ponteiros
    Item *novo = malloc(sizeof(Item)); // criar espaço na memória para um ponteiro * novo do tipo Item
    if (!novo) return NULL; // checar se malloc conseguiu dar um retorno válido de memória para novo
    strncpy(novo->nome, nome, sizeof(novo->nome)-1); // acessa o campo nome, copia o argumento, força o tamanho do campo a ter 39 (com 0, 40) chars
    novo->nome[sizeof(novo->nome)-1] = '\0'; // acessa o último char do campo nome e coloca quebra de array
    strncpy(novo->tipo, tipo, sizeof(novo->tipo)-1); // faz a mesma coisa que pro nome 
    novo->tipo[sizeof(novo->tipo)-1] = '\0';
    novo->proximo = NULL; // acessa o campo proximo do item adicionado nessa iteração com nulo (último a ser adicionado)
    novo->quantidade = 1; // acessa o campo quantidade do item com 1, pra simbolizar que tem apenas um dele adicionado à mochila
    printf("Item adicionado.\n"); 
    return novo; 
}
void removerItem (Item **inicio, const char *nome) {// **inicio aponta para o endereço de memória de *inicio, valor global de *inicio é alterado, não apenas Item1) {
    Item *atual = inicio;
    Item *anterior = NULL;
        while (atual != NULL) { // percorre a lista
            if (strcmp(atual->nome, nome == 0)) { // compara o dado no campo nome com o nome dado como argumento
                // caso 1: remove o primeiro nó
                if (anterior == NULL) {
                    *inicio = atual->proximo; 
                } else {
                    // caso 2: remover no meio ou no fim
                    anterior->proximo = atual->proximo; 
                }
            } 
        }
}

void percorrerLista(Item *inicio) { // Item *inicio significa dizer que a função vai receber um ponteiro pra item
    Item *atual = inicio; // cria um ponteiro que aponta para um Item, e recebe o endereço de memória de inicio (aponta pro mesmo nó)
    int i = 1; 
    while (atual != NULL) { // enquanto o endereço de memória de atual for diferente de nulo
        printf("%d. %s (%s)\n", i, atual->nome, atual->tipo); 
        atual = atual->proximo; // atualiza a localização de memória de atual para o endereço localizado no campo proximo do item criado
        i++;
    }
}

void percorrerComAnterior(Item *inicio) { 
    Item *atual = inicio; 
    Item *anterior = NULL;

    while (atual != NULL) {
        if (anterior == NULL) {
            printf("Primeiro nó: %s\n", atual->nome);
        } else {
            printf("Anterior: %s -> Atual: %s\n", anterior->nome, atual->nome);
        }
        anterior = atual;
        atual = atual->proximo; 
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
    percorrerLista(inicio);

    printf("\nPercorrendo com anterior:\n");
    percorrerComAnterior(inicio);

    return 0;
}