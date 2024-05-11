#include "column.h"
#include <stdio.h>
#include <stdlib.h>

COLUMN *create_column(ENUM_TYPE type, char *title){
    COLUMN* col;
    col = (COLUMN*) malloc(sizeof(COLUMN));
    col->title = title;
    col->column_type = type;
    col->data=NULL;
    return col;
}
