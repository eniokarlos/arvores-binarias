#include<stdio.h>
#include<stdlib.h>
#include "arvores.h"

int main (void){
    //criar uma arvore normal manualmente
    Arv * a1 = add(2, vazio(), vazio());
    Arv * a2 = add(5, vazio(), vazio());
    Arv * a3 = add(6, vazio(), vazio());
    Arv * a4 = add(8, a1, a2);
    Arv * a5 = add(7, a3, a4);
    //criar arvore de busca
    Arv* busca = NULL;
    unsigned short int x = 5, info;
    while(x){
        printf("digite um numero: ");
        scanf("%hu", &info);
        busca = add_busca(busca, info);
        x--;
    }
    printf("imprimindo arvore de busca\n");
    imprimir_ord(busca);
    printf("\n");
    printf("imprimindo arvore normal\n");
    imprimir_ord(a5);
    printf("\n");
    imprimir_pos(a5);
    printf("\n");
    imprimir_pre(a5);
    return 0;
}