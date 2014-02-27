//
//  functions.h
//  alg2_compatibilidade
//
//  Created by Gabriel Bellon on 24/02/14.
//  Copyright (c) 2014 Gabriel Bellon. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//Valor das opções de componentes
extern int RAM_VAL_1GB;
extern int RAM_VAL_2GB;
extern int RAM_VAL_4GB;
extern int RAM_VAL_8GB;

extern int HD_VAL_250GB;
extern int HD_VAL_500GB;
extern int HD_VAL_750GB;
extern int HD_VAL_1000GB;

extern double PROC_CLOCK_VAL_423;
extern double PROC_CLOCK_VAL_428;
extern double PROC_CLOCK_VAL_823;
extern double PROC_CLOCK_VAL_828;

typedef struct comp {
    int cod;
    int ram_val;
    int hd_val;
    double proc_clock_val;
    double comp_val;
    struct comp* next;
} Lista;

typedef struct usr_comp {
    int ram_val;
    int hd_val;
    double proc_clock_val;
} PC;

Lista* criar (void);

PC* init_PC(int ram_val, int hd_val, double proc_clock_val);

Lista* inserir (Lista* lista, int cod, int ram_val, int hd_val, double proc_clock_val);

Lista* preparar_lista();

void imprimir (Lista *lista);

Lista* comparar(Lista *lista, PC *pc);

Lista* procurar (Lista* lista, int elem);

Lista* remover (Lista *lista, int elem);

void liberar (Lista *lista);

Lista* enqueue (Lista *f, int cod, int ram_val, int hd_val, double proc_clock_val, double comp_val);

Lista* dequeue (Lista *f);

int front (Lista *f);

int empty (Lista *f);

void print_menu();