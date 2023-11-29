#include "header.h"
#include <stdio.h>
#include <stdlib.h>
/* Author: ADAMU MUHAMMAD MUHAMMAD 
* Date: 27 nov, 2023
* concept: Array ADT( Abstract Data type)
*/
// Global
struct arr Array;
int num; 
int x;
int pos,element;

int main()
{
  int index;
  printf(BLUE " \n\n*********Welcome to Array "  RESET  RED  " ADT **********\n\n " RESET );
  printf("Enter the Size of an Array to be Created \n =: ");
  scanf("%d", &Array.size);
  Array.Space = (int *)malloc(Array.size * sizeof(int));
  Array.length = 0;

  printf("Enter number of numbers \n =: ");
  scanf("%d", &num); 

  printf("Enter All the Numbers \n");
  for (index = 0; index < num; index++)
    scanf("%d", &Array.Space[index]);

  Array.length = num;
  Display(Array);
 
  // Appending 
  x = 23;
  Append(&Array, x);
  printf("\n********After Appeding*************\n");
  Display(Array);

 // inserting
 pos = 4;
 element = 21;
 Insert(&Array,pos, element);
 printf("\n***********After insertion**********\n");
 Display(Array);

  /** Free allocated memory*/
  free(Array.Space);
  return 0;
}
