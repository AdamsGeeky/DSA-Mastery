#include "header.h"
#include <stdio.h>
/*
* Author: ADAMU MUHAMMAD MUHAMMAD
* Date: 28 nov, 2023
* concept: traversing throght the Array
*/
void Display(struct arr Array)
{
  int i;
  printf("\n The Elements of the Array Are: \n");
  printf("{ ");
  for (i = 0; i < Array.length; i++)
    printf(",%d ", Array.Space[i]);
  printf("}\n");
}

