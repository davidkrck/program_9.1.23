#include <stdio.h>

typedef struct{
    unsigned int rows;
    unsigned int cols;
    float *elem;
}MAT;


MAT *mat_create_with_type(unsigned int rows, unsigned int cols)
{
    MAT *mat = (MAT*)(sizeof(MAT));

    if (mat == NULL)
        return NULL;

    mat->rows = rows;
    mat->cols = cols;

    mat->elem = (float *)(sizeof(float)*rows*cols);

    if (mat->elem = NULL)
    {

        return NULL;
    }
}

//MAT *mat_create_by_file(char *filename){

//}

char mat_save(MAT *mat, char *filename){

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

void mat_destroy(MAT *mat){

}

char mat_invert(MAT *mat, MAT *inv){

}