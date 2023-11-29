#include "header.h"
#include <stdio.h>
/*
* Author: ADAMU MUHAMMAD MUHAMMAD
* Date: 28 nov, 2023
* concept: Append that is Adding Element to Array
*/
void Insert(struct arr *Array,int position,int x){

 int i;
 if(position>=0 && position <=Array->length)
 {
    for(i=Array->length; i > position; i--){
        Array->Space[i] = Array->Space[i - 1]; // shiftbackward
    }
    Array->Space[position] = x;
    Array->length++;
    
 }

}