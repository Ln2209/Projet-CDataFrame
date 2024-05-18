#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CreationCDataFrameVide(int NombreCases) {
    CDataframe * cdataframe = (int*) malloc(NombreCases * sizeof(int));
    return cdataframe;
}