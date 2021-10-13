#ifndef _ARVORES_H
#define _ARVORES_H

#include<stdio.h>
#include<stdlib.h>

typedef struct arv{   
    int info;
    int nivel;
    struct arv* esq;
    struct arv* dir;
}Arv;

Arv* vazio(){
    return NULL;
}
//adicionar valor em uma arvore normal
Arv* add (int c, Arv* e, Arv* d){
    Arv* novo = (Arv *)malloc(sizeof(Arv));
    novo->info = c;
    novo->esq = e;
    novo->dir = d;
    return novo;
}
//adicionar valor em uma arvore de busca
Arv* add_busca(Arv* a, int v){
    if(a== NULL){
        a = (Arv*) malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if(v < a->info)
        a->esq = add_busca(a->esq, v);
    else 
        a->dir = add_busca(a->dir, v);
    return a;
}

//deletetar no em uma arvore binaria de busca 
Arv* remover(Arv* raiz, int c){
    if(raiz == NULL){
        return NULL;
    }
    else if(raiz->info > c)
        raiz->esq = remover(raiz->esq, c);
    else if(raiz->info < c)
        raiz->dir = remover(raiz->dir, c);
    else if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz);
        raiz = NULL;
    }
    else if(raiz->esq == NULL){
        Arv* aux = raiz;
        raiz = raiz->dir;
        free(aux);
    }
    else if(raiz->dir == NULL){
        Arv* aux = raiz;
        raiz = raiz->esq;
        free(aux);
    }
    else{
        Arv* aux = raiz->dir;
        while(aux->dir != NULL){
            aux = aux->dir;
        }
        raiz->info = aux->info;
        aux->info = c;
        raiz->esq = remover(raiz->esq, c);
    }
    return raiz;
}

int arv_vazia(Arv* a){
    return a == NULL;
}
//deletetar no normalmente
Arv* del(Arv* a){
    if(a != NULL){
        del(a->esq);
        del(a->dir);
        free(a);
    } 
    return NULL;
}

int posicao(Arv* a, int c){
    static i = 0;
    if(arv_vazia(a)){
        printf("Arvore vazia!"); 
    }
    if(a->info != c){
        i++;
        posicao(a->esq, c);
        posicao(a->dir, c);
    }
    return i;
}

static int max(int a, int b){
    return (a>b) ? a : b;
}

int altura(Arv *a){
    int i;
    if(arv_vazia(a))
        return -1;
    else
        i =  max(altura(a->esq),altura(a->dir));
        return 1 + i;
}

void atr_niveis(Arv* a, int n){
    if(a != NULL){
        n++;
        atr_niveis(a->esq,n);
        atr_niveis(a->dir,n);
    }
}


void imp_niveis(Arv* a, int niv){
    if(a != NULL && a->nivel == niv){
        imp_niveis(a->esq, niv);
        imp_niveis(a->dir, niv);
    }
    else if(a!= NULL){
        imp_niveis(a->esq, niv);
        imp_niveis(a->dir, niv);
    }
}

void imprimir_pre(Arv * a){
    if(a != NULL){
        printf("%d ", a->info);
        imprimir_pre(a->esq);
        imprimir_pre(a->dir);     
    }
}

void imprimir_ord(Arv* a){
    if(a != NULL){
        imprimir_ord(a->esq);
        printf("%d ", a->info);
        imprimir_ord(a->dir); 
    }
}

void imprimir_pos(Arv* a){
    if(a != NULL){
        imprimir_ord(a->esq);
        imprimir_ord(a->dir);
        printf("%d ", a->info); 
    }
}

#endif 