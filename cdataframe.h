#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H

#include "column.h"
#include "list.h"



/**
 * @brief:  Shows the totality of the CDataFrame
 * @param1: Pointer to the CDataFrame
 */
void show_cdataframe(list* dataframe);

/**
 * @brief:  Shows part of the lines of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: number of the first line
 * @param3: number of the last line
 */
void showline_cdataframe(list* dataframe, int start, int end);

/**
 * @brief:  Shows part of the column of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: number of the first line
 * @param3: number of the last line
 */
void showcolumn_cdataframe(list* dataframe, int start, int end);

/**
 * @brief:  Shows names of the columns of the CDataFrame
 * @param1: Pointer to the CDataFrame
 */
void shownamecolumn_cdataframe(list* dataframe);

/**
 * @brief:  Shows number of lines of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @return: number of lines
 */
int shownumline_cdataframe(list* dataframe);

/**
 * @brief:  Shows number of columns of the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @return: number of columns
 */
int shownumcolumn_cdataframe(list* dataframe);

/**
 * @brief:  Looks for a value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: 1 if the value exists 0 otherwise
 */
int cellequal_cdataframe(list* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Shows the numbers of cells match with the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells equals
 */
int cellsequal_cdataframe(list* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Shows the numbers of cells superior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells superior
 */
int cellssup_cdataframe(list*, COLUMN* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Shows the numbers of cells inferior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells inferior
 */
int cellsinf_cdataframe(list* dataframe, COL_TYPE, ENUM_TYPE);

/**
 * @brief:  Rename a column in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: Position of the column
 * @param3: New title
 * @return: 1 if there is no error 0 otherwise
 */
int renamecolumn_cdataframe(list* dataframe, int index, char* title);


#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
