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
/* 
Novo->proximo = inicio: faz com que o campo "proximo" de Item passe a guardar o endereço de inicio.
Se for o primeiro item, inicio guarda um endereço de memória nulo (NULL). 
No entanto, depois que inicio = novo é realizado, inicio passa a guardar o endereço de memória do novo item criado;
Assim, apontando para o novo item.*/
void percorrerLista() {
    Item *atual = inicio;
    int contador = 0; 
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    atual = inicio;
    for (int i = 0; i < contador; i++) {
        printf("Item %d encontrado: %s", i + 1, atual->nome); // para printar a partir do 1 e não do 0
        atual = atual->proximo;
    }
}

void percorrerLista2() {
    Item *atual = inicio;
    int i = 0;
    while (atual != NULL) {
        printf("Item %d encontrado: %s\n", i+1, atual->nome);
        i++; 
        atual = atual->proximo; 
    }
}

void acharItem(const char *nome) {
    Item *atual = inicio; 
    while (atual != NULL) {
        if (strcmp(atual->nome, nome)== 0) {
            printf("Item encontrado: %s\n", atual->nome);
            return;
        } else {
        anterior = atual;
        atual = atual->proximo; 
        }
    }
}
/* Primeiro cria um bloco capaz de percorrer a lista e depois  */




