#include "cdataframe.h"
#include <stdlib.h>
#include "list.c"

CDATAFRAME* create_cdataframe(ENUM_TYPE* cdftype, int size){
    CDATAFRAME* cdf = NULL;
    cdf = lst_create_list();
    if (cdf == NULL){
        return cdf;
    }
    cdf->size = size;
    cdf->head->ln_data->column_type = (*cdftype);
    cdf->tail->ln_data->column_type = (*cdftype);
    return cdf;
}