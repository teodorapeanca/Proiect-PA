#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include"homar.h"

int main(int argc, char* argv[])
{	

	//Declarare variabile

	unsigned long capacitate_plasa, numar_homari=0, dimensiune_temporara_homar, valoare_temporara_homar;
	clock_t inceput, sfarsit;

	inceput=clock();

	FILE *input, *output;  //fisiere I/O 

	homar* colectie_homari=malloc(sizeof(homar)); 

	// I/O initilalizare

	input=fopen(argv[1], "r");
	output=fopen("output","w");

	// Verificare erori

	if(argc!=2){
	       
		fprintf(stderr, " Este nevoie de un argument de linie de comanda");
		return 1;
	}

	if(input == NULL || output == NULL)
	{
		fprintf(stderr, " Nu s-au putut deschide fisierele");
		return 2;
	}

	
	//Input

	fscanf(input,"%lu",&capacitate_plasa);
	
	while(fscanf(input,"%s %lu %lu",
				colectie_homari[numar_homari].nume,
				&dimensiune_temporara_homar,
				&valoare_temporara_homar)
			!=EOF)
		if(valoare_temporara_homar<=capacitate_plasa) 
		{

			colectie_homari[numar_homari].valoare=valoare_temporara_homar;
			colectie_homari[numar_homari].dimensiune=dimensiune_temporara_homar;

			numar_homari++;
			colectie_homari=realloc(colectie_homari, sizeof(homar)*(numar_homari+2));
		}



	//Apelare functie
	

	programare_dinamica_homar(colectie_homari, numar_homari, capacitate_plasa, output);


	sfarsit=clock();

	fprintf(output, "\n Timp de executie: %lf secunde ", (double)((sfarsit-inceput))/CLOCKS_PER_SEC);
		
	//Incheiere

	free(colectie_homari);

	fclose(input);
	fclose(output);

	return 0;
}
