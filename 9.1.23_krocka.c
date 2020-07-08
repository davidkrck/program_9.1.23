#include <stdio.h>

typedef struct{
    unsigned int rows;
    unsigned int cols;
    float *elem;
}MAT;

ELEM(mat, i, j)


MAT *mat_create_with_type(unsigned int rows, unsigned int cols)
{

}

//MAT *mat_create_by_file(char *filename){

//}

char mat_save(MAT *mat, char *filename){

}

void mat_destroy(MAT *mat){

}

void mat_unit(MAT *mat){

}

void mat_random(MAT *mat){
    int i, j;

    for(i = 0; i < mat -> rows; i++){
        for(j = 0, j < mat -> cols; j++){

            ELEM(mat, i, j) = ((float)rand()/(float)(RAND_MAX));
        }
    }
}

void mat_print(MAT *mat){

}

char mat_invert(MAT *mat, MAT *inv){

}