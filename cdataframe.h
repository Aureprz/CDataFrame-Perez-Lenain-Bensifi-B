#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H

#include "column.h"
#include "list.h"

typedef struct cdataframe{

    ENUM_TYPE* list_type;
    int size;
    dllist *list;
    unsigned int nb_line;

}CDATAFRAME;

/**
@param1:  Possibles types of the soon to be CDataFrame
@param2: Size of the CDataFrame
*/

CDATAFRAME* create_empty_cdataframe(ENUM_TYPE* cdftype,unsigned int size);


/**
   * User gets to choose the parameters for his soon-to be Dataframe
*/
CDATAFRAME* create_cdf_user();

CDATAFRAME* create_cdf_program();


/**
 * @brief: Printout each column name
 * @param: Dataframe
 */

void print_col_names(CDATAFRAME* cdf);

/**
 * @brief:  Shows the totality of the CDataFrame
 * @param1: Pointer to the CDataFrame
 */
void show_cdataframe(CDATAFRAME* dataframe);

/**
 * @brief: Replace a value within the Dataframe
 * @param1: Dataframe
 * @param2: The row location in which the user wants to change the value
 * @param2: The column location in which the user wants to swap the value
 */
void replace_value_cdf(CDATAFRAME *cdf);


/**
 * @brief:  Looks for a value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: 1 if the value exists 0 otherwise
 */
int cellexist_cdataframe(CDATAFRAME* cdf, void* value);

/**
 * @brief:  Shows the numbers of cells match with the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells equals
 */
int cellsequal_cdataframe(CDATAFRAME* dataframe, void* value);

/**
 * @brief:  Shows the numbers of cells superior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells superior
 */
int cellssup_cdataframe(CDATAFRAME* dataframe, void* value);

/**
 * @brief:  Shows the numbers of cells inferior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: Value
 */
int cellsinf_cdataframe(CDATAFRAME* dataframe, void* value);

/**
 * @brief: Gives the user the number of cells in which the value is superior compared to a value in the CDataFrame
 * @param1: CDataFrame
 * @param2: User's value
 */

int cellssup_cdataframe(CDATAFRAME* dataframe, void* value);

void display_dataframe(CDATAFRAME* cdf);

void rename_col(CDATAFRAME* cdf, char* title_replaced);

void delete_column_cdf(CDATAFRAME *cdf, char *col_name);

void delete_cdf_line(CDATAFRAME *cdf);

int column_number(CDATAFRAME* cdf);

int line_number(CDATAFRAME* cdf);

void append_column_dataframe(CDATAFRAME* cdf);

void append_line_dataframe(CDATAFRAME *cdf);

void display_columns(CDATAFRAME* cdf);

void display_lines(CDATAFRAME* cdf);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
