//
//  functions.c
//  alg2_compatibilidade
//
//  Created by Gabriel Bellon on 24/02/14.
//  Copyright (c) 2014 Gabriel Bellon. All rights reserved.
//

#include "functions.h"

int RAM_VAL_1GB = 1;
int RAM_VAL_2GB = 2;
int RAM_VAL_4GB = 4;
int RAM_VAL_8GB = 8;

int HD_VAL_250GB = 250;
int HD_VAL_500GB = 500;
int HD_VAL_750GB = 750;
int HD_VAL_1000GB = 1000;

double PROC_CLOCK_VAL_423 = 4 * 2.3;
double PROC_CLOCK_VAL_428 = 4 * 2.8;
double PROC_CLOCK_VAL_823 = 8 * 2.3;
double PROC_CLOCK_VAL_828 = 8 * 2.8;

Lista* criar (void) {
    return NULL;
}

PC* init_PC(int ram_val, int hd_val, double proc_clock_val){
    PC* novo = (PC*)malloc(sizeof(PC));
    novo->ram_val = ram_val;
    novo->hd_val = hd_val;
    novo->proc_clock_val = proc_clock_val;
    return novo;
}

Lista* inserir (Lista* lista, int cod, int ram_val, int hd_val, double proc_clock_val) {
    Lista* novo =(Lista*)malloc(sizeof(Lista));
    novo->cod = cod;
    novo->ram_val = ram_val;
    novo->hd_val = hd_val;
    novo->proc_clock_val = proc_clock_val;
    novo->comp_val = 0;
    novo->next = lista;
    return novo;
}

//ADICIONAR AO HEADER
Lista* preparar_lista(){
    Lista* a = criar();
    
    a = inserir(a, 0, RAM_VAL_2GB, HD_VAL_500GB, PROC_CLOCK_VAL_428);
    a = inserir(a, 1, RAM_VAL_8GB, HD_VAL_1000GB, PROC_CLOCK_VAL_828);
    a = inserir(a, 2, RAM_VAL_8GB, HD_VAL_250GB, PROC_CLOCK_VAL_423);
    a = inserir(a, 3, RAM_VAL_4GB, HD_VAL_500GB, PROC_CLOCK_VAL_823);
    a = inserir(a, 4, RAM_VAL_1GB, HD_VAL_750GB, PROC_CLOCK_VAL_423);
    a = inserir(a, 5, RAM_VAL_1GB, HD_VAL_250GB, PROC_CLOCK_VAL_423);
    a = inserir(a, 6, RAM_VAL_2GB, HD_VAL_750GB, PROC_CLOCK_VAL_428);
    
    return a;
}

//ADICIONAR AO HEADER

Lista* enqueue (Lista *f, int cod, int ram_val, int hd_val, double proc_clock_val, double comp_val) {
    if (f == NULL) {
        Lista* novo = (Lista*)malloc(sizeof(Lista));
        novo->cod = cod;
        novo->ram_val = ram_val;
        novo->hd_val = hd_val;
        novo->proc_clock_val = proc_clock_val;
        novo->comp_val = 0;
        return novo;
    }
    Lista *tmp = f;
    Lista *aux;
    while (tmp != NULL) {
        aux = tmp;
        tmp = tmp->next;
    }
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->cod = cod;
    novo->ram_val = ram_val;
    novo->hd_val = hd_val;
    novo->proc_clock_val = proc_clock_val;
    novo->comp_val = 0;
    aux->next = novo;
    return f;
}

void imprimir (Lista *lista) {
    Lista *v;
    for (v = lista; v != NULL; v = v->next) {
        printf("Cod. da Máquina: %d\n", v->cod);
        printf("Qtde. de RAM: %D\n", v->ram_val);
        printf("Qtde. de HD: %D\n", v->hd_val);
        printf("Clock do Proc.: %f\n", v->proc_clock_val);
        printf("Qtde. de RAM: %D\n", v->ram_val);
        if(v->comp_val > 0){
            printf("Nível de compatibilidade: %f\n", v->comp_val);
        }
    }
}

Lista* comparar(Lista *lista, PC *pc){
    Lista *v;
    for (v = lista; v != NULL; v = v->next) {
        if (pc->ram_val > v->ram_val) {
            v->comp_val = 2 + v->comp_val;
        } else if(pc->ram_val == v->ram_val){
            v->comp_val = 3 + v->comp_val;
        } else if(pc->ram_val < v->ram_val) {
            v->comp_val = 1 + v->comp_val;
        } else {
            v->comp_val = 0 + v->comp_val;
        }
        
        if (pc->ram_val > v->hd_val) {
            v->comp_val = 2 + v->comp_val;
        } else if(pc->ram_val == v->hd_val){
            v->comp_val = 3 + v->comp_val;
        } else if(pc->ram_val < v->hd_val) {
            v->comp_val = 1 + v->comp_val;
        } else {
            v->comp_val = 0 + v->comp_val;
        }
        
        if (pc->ram_val > v->proc_clock_val) {
            v->comp_val = 2 + v->comp_val;
        } else if(pc->ram_val == v->proc_clock_val){
            v->comp_val = 3 + v->comp_val;
        } else if(pc->ram_val < v->proc_clock_val) {
            v->comp_val = 1 + v->comp_val;
        } else {
            v->comp_val = 0 + v->comp_val;
        }
    }
    
    return v;
}

void ordenar(Lista* lista){
    if(lista->next != NULL){
        if(lista->next->comp_val < lista->comp_val){
            int aux = lista->next->comp_val;
            lista->next->comp_val = lista->comp_val;
            lista->comp_val = aux;
            
            ordenar(lista->next);
        } else {
            ordenar(lista->next);
        }
    } else {
        return;
    }
}

Lista* procurar (Lista* lista, int elem) {
    Lista* v;
    for (v = lista; v != NULL; v = v->next) {
        if (v->cod == elem) {
            return v;
        }
    }
    return NULL;
}

Lista* remover (Lista *lista, int cod) {
    Lista* prv = NULL;
    Lista* v = lista;
    while ((v != NULL) && (v->cod != cod)) {
        prv = v;
        v = v->next;
    }
    if (v == NULL) { return lista; }
    if (prv == NULL) { lista = v->next; }
    else { prv->next = v->next; }
    free (v);
    return lista;
}

Lista* dequeue (Lista *lista) {
    Lista *tmp = lista;
    lista = lista->next;
    free (tmp);
    return lista;
}

int front (Lista *f) {
    return f->cod;
}

int empty (Lista *f) {
    if (f == NULL){ return 1; } else { return 0; }
}

void liberar (Lista *lista) {
    Lista* v;     v = lista;
    while (v != NULL) {
        Lista *aux = v->next;
        free (v);
        v = aux;
    }
}

//MENU
void print_menu(){
    printf("--- COMPARAÇÃO DE RESULTADOS ---\n");
    
}
