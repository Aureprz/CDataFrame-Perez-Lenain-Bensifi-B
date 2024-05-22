#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H

#include "column.h"
#include "list.h"

typedef struct cdataframe{

    ENUM_TYPE* list_type;
    int size;
    dllist *list;

}CDATAFRAME;

/**
* @param1:  Possibles types of the soon to be CDataFrame
* @param2: Size of the CDataFrame
* @return: Pointer to the DataFrame
*/

CDATAFRAME* create_empty_cdataframe(ENUM_TYPE* cdftype,int size);


/**
* @brief: User gets to choose the parameters for his soon-to be Dataframe
* @return: Pointer to the Dataframe
*/
CDATAFRAME* create_cdf_user();

/**
 * @brief: Create a DataFrame by the program
 * @return: Pointer to the DataFrame
 */
CDATAFRAME* create_cdf_program();

/**
 * @brief: Printout each column name
 * @param: Dataframe
 */

void print_col_names(CDATAFRAME* cdf);

void viderBuffer();

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

/**
 * @brief: Display the entire DataFrame
 * @param1: Pointer to the DataFrame
 */
void display_dataframe(CDATAFRAME* cdf);

/**
 * @brief: Rename a column in the DataFrame
 * @param1: Pointer to the DataFrame
 * @param2: Title to be replaced
 */
void rename_col(CDATAFRAME* cdf, char* title_replaced);


/**
 * @brief: Delete a column in the DataFrame
 * @param1: Pointer to the DataFrame
 * @param2: Column name to be deleted
 */
void delete_column_cdf(CDATAFRAME *cdf, char *col_name);

/**
 * @brief: Delete a line within the DataFrame
 * @param1: Pointer to the DataFrame
 */
void delete_cdf_line(CDATAFRAME *cdf);

/**
 * @brief: Gives the user the number of columns the DataFrame holds
 * @param: Pointer to the DataFrame
 * @return: The number of columns within the DataFrame
 */
int column_number(CDATAFRAME* cdf);

/**
 * @brief: Gives the user the number of lines the DataFrame holds
 * @param1: Pointer to the DataFrame
 * @return: The number of lines within the DataFrame
 */
int line_number(CDATAFRAME* cdf);

/**
 * @brief: Adds a column in a certain position within the DataFrame
 * @param1: Pointer to the DataFrame
 */
void append_column_dataframe(CDATAFRAME* cdf);

/**
 * @brief: Adds a line in a certain position within the DataFrame
 * @param1: Pointer to the DataFrame
 */
void append_line_dataframe(CDATAFRAME *cdf);

/**
 * @brief: Display a certain number of columns
 * @param1: Pointer to the DataFrame
 */
void display_columns(CDATAFRAME* cdf);

/**
 * @brief: Display a certain number of lines
 * @param1: Pointer to the DataFrame
 */
void display_lines(CDATAFRAME* cdf);

/**
 * @brief: Allows the program to delete '\0' at the end of inputs
 * @param1: Input in the form of a string
 * @param2: Lenght of the string
 * @return: Either 0 if there's no problem, 1 otherwise
 */
int lire(char *chaine, int longueur);

/**
 * @brief: Allows the user to choose a column within the DataFrame and to sort it (either in ASC or DESC order)
 * @param1: Pointer to the DataFrame
 */
void sort_column_in_cdf(CDATAFRAME* cdf);

void sort_cdf(CDATAFRAME *cdf);

void display_dataframe_by_index(CDATAFRAME* cdf);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_CDATAFRAME_H