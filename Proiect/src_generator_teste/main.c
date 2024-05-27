#include<stdio.h>
#include<stdlib.h>

#define min_lobster_name 3
#define max_lobster_name 20

int main(int argc, char* argv[])
	{
	
	//Declarere variabile 
	unsigned long numar_homari, index, capacitate_plasa;
       	unsigned long valuare_minima_homar, valuare_maxima_homar, dimensiune_minima_homar, dimensiune_maxima_homar;
	FILE* output, *input;
	short unsigned lungime_nume, j;
	
	input=fopen(argv[1], "r");
	output=fopen("output","w");

	//Error handling
	
	if(argc!=2)
	{
		fprintf(stderr, "Programul are nevoie exact de un argument");
		return 1;
	}

	if(input==NULL || output==NULL)
	{	
		fprintf(stderr, " Nu s-a putut deschide fisierul");
		return 2;
	}

	//input

	fscanf(input,"%lu",&capacitate_plasa);
	fscanf(input,"%lu",&numar_homari);
	fscanf(input,"%lu",&valuare_minima_homar);
	fscanf(input,"%lu",&valuare_maxima_homar);
	fscanf(input,"%lu",&dimensiune_minima_homar);
	fscanf(input,"%lu",&dimensiune_maxima_homar);

	//generating randomized output;
	
	fprintf(output,"%lu\n",capacitate_plasa);
	for(index=0;index<numar_homari;index++)
	{
		lungime_nume=min_lobster_name + rand()%(max_lobster_name-min_lobster_name);

		for(j=0; j<lungime_nume; j++)
		fprintf(output, "%c", 'a'+rand()%('z'-'a'));

		fprintf(output," %lu", dimensiune_minima_homar+rand()%(dimensiune_maxima_homar-dimensiune_minima_homar));
		fprintf(output," %lu\n", valuare_minima_homar+rand()%(valuare_maxima_homar-valuare_minima_homar));
	}

	//Clean up
	
	fclose(input);
	fclose(output);
		
	return 0;
	
	}
