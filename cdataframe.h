#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H

#include "column.h"
#include "list.h"



typedef struct cdataframe{
    ENUM_TYPE cdataframe_type; // liste des types
    unsigned int size;
    dllist list;
}CDATAFRAME;

/**

@param1:  Possibles types of the soon to be CDataFrame
@param2: Size of the CDataFrame
*/

CDATAFRAME* create_empty_cdataframe(ENUM_TYPE* cdftype,unsigned int size);

CDATAFRAME* create_cdf_user();

void print_col_names(CDATAFRAME* cdf, unsigned int size);

/**
 * @brief:  Shows the totality of the CDataFrame
 * @param1: Pointer to the CDataFrame
 */
void show_cdataframe(dllist* dataframe);

/**
 * @brief:  Shows part of the lines of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: number of the first line
 * @param3: number of the last line
 */
void showline_cdataframe(dllist* dataframe, int start, int end);

/**
 * @brief:  Shows part of the column of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: number of the first line
 * @param3: number of the last line
 */
void showcolumn_cdataframe(dllist* dataframe, int start, int end);

/**
 * @brief:  Shows names of the columns of the CDataFrame
 * @param1: Pointer to the CDataFrame
 */
void shownamecolumn_cdataframe(dllist* dataframe);

/**
 * @brief:  Shows number of lines of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @return: number of lines
 */
int shownumline_cdataframe(dllist* dataframe);

/**
 * @brief:  Shows number of columns of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @return: number of columns
 */
int shownumcolumn_cdataframe(dllist* dataframe);

/**
 * @brief:  Looks for a value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: 1 if the value exists 0 otherwise
 */
int cellequal_cdataframe(dllist* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Shows the numbers of cells match with the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells equals
 */
int cellsequal_cdataframe(dllist* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Shows the numbers of cells superior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells superior
 */
int cellssup_cdataframe(dllist*, COLUMN* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Shows the numbers of cells inferior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells inferior
 */
int cellsinf_cdataframe(dllist* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Rename a column in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: Position of the column
 * @param3: New title
 * @return: 1 if there is no error 0 otherwise
 */
int renamecolumn_cdataframe(dllist* dataframe, int index, char* title);


#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
