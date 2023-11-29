#ifndef HEADER_H
#define HEADER_H

struct arr {
  int *Space; // in the Heap memory
  int size;
  int length;
};

// ANSI color escape codes
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"

// Functions
void Display(struct arr Array);
void Append(struct arr *Array,int element);
void Insert(struct arr *Array,int position,int element);
void Delete(struct arr *Array,int index);
#endif
