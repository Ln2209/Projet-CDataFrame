#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CreationCDataFrameVide(int NombreCases) {
    int* CDataFrame = (int*) malloc(NombreCases * sizeof(int));
    return CDataFrame;
}