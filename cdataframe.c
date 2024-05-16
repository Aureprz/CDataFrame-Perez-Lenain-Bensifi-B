#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    CDATAFRAME  *cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->list = lst_create_list();
    cdf->list_type =  cdftype;
    cdf->size = size;
    return cdf;
}


CDATAFRAME* create_cdf_user() {
    int size = 0;
    int value = 0;
    CDATAFRAME* cdf;
    do{
        printf("Veuillez saisir le nombre de colone du CDF:\n");
        scanf("%d", &size);
    }while(size <=0);
    ENUM_TYPE list_type[size];
    for(int i=0; i < size; i++){
        printf("============ Colone [%d] ============\n",i+1);
        do {
            printf("Veuiller saisir le type de la colone:\n");
            printf("NULLVAL [1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]\n");
            scanf(" %d", &value);
        } while ((value <=0) || (value>8));
        list_type[i] = value;
    }
    cdf = create_cdataframe(list_type, size);
    //TODO LE REMPLISSAGE DES COLONES
    return cdf;
}