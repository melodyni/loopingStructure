#ifndef __LOOPING_STRUCTURE_H
#define __LOOPING_STRUCTURE_H

#include "list.h"

typedef int (*mapperFn) (int);
typedef Bool (*predicateFn) (int);
typedef int (*reducerFn) (int, int);

List_ptr map(mapperFn, List_ptr);
List_ptr filter(predicateFn , List_ptr);
int reduce(reducerFn, List_ptr, int);

#endif
