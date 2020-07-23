#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#ifndef O_BINARY
#define O_BINARY 0
#endif 

#define ELEM(mat, i, j) (mat->elem[(mat->cols)*i+j])



typedef struct{
    unsigned int rows;
    unsigned int cols;
    float *elem;
}MAT;


MAT *mat_create_with_type(unsigned int rows, unsigned int cols)
{
    MAT *mat = (MAT*)malloc(sizeof(MAT));

    if (mat == NULL)
        return NULL;

    mat->rows = rows;
    mat->cols = cols;

    mat->elem = (float *)malloc(sizeof(float)*rows*cols);

    if (mat->elem = NULL)
    {
        free(mat)
        return NULL;
    }

    return mat;
}

MAT *mat_create_by_file(char *filename){

    MAT *matica;
    unsigned int rows, cols;
    char typ_suboru[2] = {0};

    int subor = open(filename, O_RDONLY | O_BINARY, S_IRUSR);


    if ( subor < 0){
        return NULL;
    }

    // čitanie prvych dvoch bajtov
    read(subor, &typ_suboru[0], sizeof(char));
    read(subor, &typ_suboru[1], sizeof(char));

    if (typ_suboru[0] != 'M' || typ_suboru[1] != '1'){
       return NULL;
    }

    //čítanie rozmerov matice
    read(subor, &rows, sizeof(unsigned int));
    read(subor, &cols, sizeof(unsigned int));

    matica = mat_create_with_type(rows, cols);

    //čítanie prvkov matice - float
    read(subor, matica->elem, sizeof(float)*rows*cols);

    close(subor);
    return matica;
}

char mat_save(MAT *mat, char *filename){

    int subor = open(filename, O_CREAT | O_WRONLY | O_BINARY, S_IWUSR);

    if ( subor < 0){
        return NULL;
    }

    //zápis prvého riadku
    write(subor, "M1", sizeof(char)*2);

    //zápis rozmerov matice
    write(subor, &mat->rows, sizeof(unsigned int));
    write(subor, &mat->cols, sizeof(unsigned int));

    //zápis prvkov matice - float
    write(subor, mat->elem, sizeof(float)*(mat->rows)*(mat->cols));

    close(subor);
}

void mat_unit(MAT *mat){
    int i, j;

    for(i = 0; i < mat->rows; i++){
        for(j = 0; j < mat->cols; j++){
            if (i==j)
                ELEM(mat, i, j) = 1.0;
            else
            {
                ELEM(mat, i , j) = 0.0;
            }
            
        }
    }
}

void mat_random(MAT *mat){
    int i, j;

    for(i = 0; i < mat->rows; i++){
        for(j = 0; j < mat->cols; j++){

            ELEM(mat, i, j) = ((float)rand()/(float)(RAND_MAX));
        }
    }
}

void mat_print(MAT *mat){
    int i, j;

    for(i = 0; i < mat->rows; i++){
        for(j = 0; j < mat->cols; j++){

            printf("%f",ELEM(mat, i , j));
        }
        printf("\n");
    }
    printf("\n");
}

void mat_destroy(MAT *mat){
    free(mat->elem);
    free(mat);
}

char mat_invert(MAT *mat, MAT *inv){

    int i, j, m;
    
    if(mat->cols!=mat->rows){
        printf ("Matica musi byt štvorcová\n");
    }
    else{

    }

}


int main(){
    MAT *matica, *invert_matica, *matica2;

    unsigned int rows, cols;
    char filename[] = {0};

    printf("Zadaj rozmery 1. matice: \n");
    scanf("%d %d", &rows, &cols);

    matica = mat_create_with_type(rows, cols);

    mat_random(matica);

    mat_print(matica);

    printf("Zadaj názov súboru: \n");
    scanf("%s", filename);
    mat_save(matica, filename);

    matica2 = mat_create_by_file(filename);

    mat_print(matica2);

    invert_matica = mat_create_with_type(rows, cols);

    //mat_invert(matica, invert_matica);

}