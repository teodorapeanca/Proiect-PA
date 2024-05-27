#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "homar.h"


//Functii matriciale

void seteaza_valoare_matrice(matrice matrice_tinta, unsigned long index_linie, unsigned long index_coloana, unsigned long valoare_element){
	unsigned long pozitie;
	pozitie = index_linie * matrice_tinta.numar_coloane + index_coloana;
	*(matrice_tinta.elemente_matrice + pozitie) = valoare_element;
}


unsigned long valoare_element_matrice(matrice matrice_tinta, unsigned long index_linie, unsigned long index_coloana){
	unsigned long pozitie;

	pozitie = index_linie * matrice_tinta.numar_coloane + index_coloana;
	return *(matrice_tinta.elemente_matrice + pozitie);
}

unsigned long max(unsigned long val1, unsigned long val2){
	if (val1 > val2)
		return val1;
	return val2;
}

void programare_dinamica_homar(homar *colectie_homari, unsigned long numar_homari, unsigned long capacitate_maxima, FILE* output){
	matrice matrice_dinamica;
	unsigned long iterator_homari;
	unsigned long iterator_dimensiune;
	unsigned long valoare_plasa;
	unsigned long dimensiune_curenta;
	unsigned long homar_curent;	

	matrice_dinamica.numar_linii = numar_homari + 1;
	matrice_dinamica.numar_coloane = capacitate_maxima + 1;

	matrice_dinamica.elemente_matrice = malloc((matrice_dinamica.numar_linii) * (matrice_dinamica.numar_coloane) * sizeof(unsigned long));	


	//Se completeaza matricea dinamica


	for(iterator_homari=0;iterator_homari<=numar_homari;iterator_homari++)
	{
		for(iterator_dimensiune=0;iterator_dimensiune<=capacitate_maxima;iterator_dimensiune++)
		{	

			if(iterator_dimensiune==0 || iterator_homari==0)
			{
				seteaza_valoare_matrice(matrice_dinamica,iterator_homari,iterator_dimensiune,0);
			}
			else if (colectie_homari[iterator_homari-1].dimensiune<=iterator_dimensiune)
			{
				seteaza_valoare_matrice(matrice_dinamica,iterator_homari,iterator_dimensiune,
						max(colectie_homari[iterator_homari-1].valoare +
							valoare_element_matrice(matrice_dinamica,iterator_homari-1,iterator_dimensiune-colectie_homari[iterator_homari-1].dimensiune),
							valoare_element_matrice(matrice_dinamica,iterator_homari-1,iterator_dimensiune)));
			}
			else {
				seteaza_valoare_matrice(matrice_dinamica,iterator_homari,iterator_dimensiune,valoare_element_matrice(matrice_dinamica,iterator_homari-1,iterator_dimensiune));	
			}
		}	
	}


	valoare_plasa = valoare_element_matrice(matrice_dinamica, matrice_dinamica.numar_linii - 1, matrice_dinamica.numar_coloane - 1);


	dimensiune_curenta=matrice_dinamica.numar_coloane-1;
	homar_curent=matrice_dinamica.numar_linii-1;

	//se gasesc homarii folositi

	while(homar_curent!=0 && dimensiune_curenta!=0) {

		if(valoare_element_matrice(matrice_dinamica,homar_curent,dimensiune_curenta)!=valoare_element_matrice(matrice_dinamica,homar_curent-1,dimensiune_curenta))	
		{			

			fprintf(output, "%s\n", colectie_homari[homar_curent-1].nume);
			dimensiune_curenta=(dimensiune_curenta>colectie_homari[homar_curent-1].dimensiune) ? dimensiune_curenta-colectie_homari[homar_curent-1].dimensiune:0;
		}
		homar_curent--;		
	} 



	free(matrice_dinamica.elemente_matrice);

	fprintf(output,"\n=== Valoare in plasa %lu ===", valoare_plasa);
}
