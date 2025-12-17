#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição fundamental 
/*Ponteiro: é uma variável que guarda o endereço de memória de alguma coisa.
-Logo quando criado, aponta para um endereço aleatório e não utilizável (lixo de memória).
-É necessário apontar para um endereço de memória específico se quiser utilizá-lo devidamente
-A inicialização de um ponteiro ocorre da mesma forma que com uma variável qualquer. 
Exemplo: int numero = 8 cria uma variável numero do tipo inteiro (ou seja, espera receber uma informação avaliada em inteiro;)
Caso não receba, acusará três possíveis erros:
1- Compilador vai guardar quantidade de bytes erradas para o tipo;
2- Diz ao compilador como interpretar (ler/escrever);
3- Previne erros ao checar tipos  .*/
// CHECKLIST:
/* 1- Incluir as seguintes bibliotecas: 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
2- Cria uma struct 
3- Criar dois ponteiros auxiliares: inicio e anterior, que esperam o endereço de um Item
4- Criar função de adição
5- Criar função de remoção
6- Listar todos os itens 
7- Ordenar os itens por critérios 
8- Realizar busca binária por nome 
9- Exitar 
*/


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
    novo->proximo = inicio; 
    inicio = novo; 
}
/* Observação:
Novo->proximo = inicio: faz com que o campo "proximo" de Item passe a guardar o endereço de inicio.
Se for o primeiro item, inicio guarda um endereço de memória nulo (NULL). 
No entanto, depois que inicio = novo é realizado, inicio passa a guardar o endereço de memória do novo item criado;
Assim, apontando para o novo item.*/




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