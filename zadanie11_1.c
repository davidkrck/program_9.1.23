#include <stdio.h>

void nacitaj(FILE *obrazok_otvoreny){
    int vyska, max, sirka;
    char typ[10];

    fscanf(obrazok_otvoreny,"%s", typ);
    fscanf(obrazok_otvoreny,"%d", &sirka);
    fscanf(obrazok_otvoreny,"%d", &vyska);
    fscanf(obrazok_otvoreny,"%d", &max);

    //printf("typ = %s\n", typ);
    //printf("sirka  = %d\n",sirka);
    //printf("vyska = %d\n",vyska);
    //printf("max = %d\n",max);

    int DATA[vyska][sirka];

    int riadok, stlpec;
    int ch_int;

    for (riadok=0; riadok < vyska; riadok++){

        for (stlpec=0; stlpec < sirka; stlpec++)
        {    
            fscanf(obrazok_otvoreny,"%d", &ch_int);
            DATA[riadok][stlpec] = ch_int;
            //printf("%d", ch_int);
        }
    }
    printf("Obrazok bol nacitany.");
}
int main(){
    FILE *obrazok_otvoreny;
    
    if ((obrazok_otvoreny = fopen("kvety.pgm","r")) == NULL){
		printf("subor sa neotvoril.");
	}
    
    nacitaj(obrazok_otvoreny);

    
    fclose(obrazok_otvoreny);
}