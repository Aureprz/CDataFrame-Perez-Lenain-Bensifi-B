#include "column.h"
#include "cdataframe.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}





    /* dllist *CDataFrame;
    COL_TYPE cell;
    ENUM_TYPE typecolumn;
    int temp, i, nb_val;
    int error;
    char title[31];
    COLUMN *column;


    do {
        error = init(CDataFrame);
    } while (!error);

    printf("Bonjour. Quel est le type de valeurs que vous souhaitez stocker parmi ces différents types ?\n");
    printf("UINT = 1\n INT = 2\n CHAR = 3\n FLOAT = 4\n DOUBLE = 5\n STRING = 6\n STRUCTURE = 7\n");
    do {
        scanf("%d", &temp);
        typecolumn = temp;
    } while ((1 <= temp) && (temp <= 5));

    printf("Et quel titre souhaitez-vous lui donner (pas plus de 30 caractères) ?\n");
    scanf(" %s", title);
    column = create_column(typecolumn, title);
    add_first(CDataFrame, column);
    printf("Combien de valeurs voulez-vous pouvoir stocker ?\n");
    scanf("%d", &nb_val);
    for (i = 0; i < nb_val; i++) {
        printf("Valeur %d : \n", (temp + 1));


        switch (typecolumn) {


            case UINT:
                scanf("%u", &cell.uint_value);
                break;
            case NULLVAL:
                break;
            case INT:
                scanf("%d", &cell.int_value);
                break;
            case CHAR:
                scanf("%c", &cell.char_value);
                break;
            case FLOAT:
                scanf("%f", &cell.float_value);
                break;
            case DOUBLE:
                scanf("%lf", &cell.double_value);
                break;
            case STRING:
                scanf(" %s", cell.string_value);
                break;
            case STRUCTURE:
                scanf("%p", &cell.struct_value);
                break;

        }
        insert_value(column, &cell);
    }

    show_cdataframe(CDataFrame);
     */


