#include "cdataframe.h"
#include <stdlib.h>
#include "list.h"

CDATAFRAME* create_empty_cdataframe(ENUM_TYPE* cdftype,unsigned int size){
    CDATAFRAME* cdf = NULL;
    cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->list = *lst_create_list();
    cdf->nb_col = size;
    cdf->cdataframe_type = (*cdftype);
    return cdf;
}

void show_cdataframe(dllist* dataframe){

}