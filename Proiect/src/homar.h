#ifndef HOMAR_H
#define HOMAR_H

#define MAX_CARACTERE_NUME 150

#include<stdio.h>

typedef struct HOMAR{
    unsigned long dimensiune;
    unsigned long valoare;
    char nume[MAX_CARACTERE_NUME];
}homar;

typedef struct MATRICE{
    unsigned long numar_linii;
    unsigned long numar_coloane;
    unsigned long *elemente_matrice;
}matrice;

void seteaza_valoare_matrice(matrice matrice_tinta, unsigned long index_linie, unsigned long index_coloana, unsigned long valoare_element);
void programare_dinamica_homar(homar *colectie_homari, unsigned long numar_homari, unsigned long capacitate_maxima, FILE* output);
unsigned long valoare_element_matrice(matrice matrice_tinta, unsigned long index_linie, unsigned long index_coloana);
unsigned long max(unsigned long val1, unsigned long val2);

#endif 
