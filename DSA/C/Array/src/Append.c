#include "header.h"
#include <stdio.h>
/*
* Author: ADAMU MUHAMMAD MUHAMMAD
* Date: 28 nov, 2023
* concept: Append that is Adding Element to Array
*/
void Append(struct arr *Array,int element)
{
    if(Array->length < Array->size){
        Array->Space[Array->length++] = element;
    }
}