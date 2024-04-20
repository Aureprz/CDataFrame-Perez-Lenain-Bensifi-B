#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_COLUMN_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_COLUMN_H

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

typedef struct COLUMN{
    char* Title;
    int TPHYS;
    int TL;
    ENUM_TYPE TYPE;

    int* INDEX;
};




#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_COLUMN_H
