#ifndef __LOOPING_STRUCTURE_H
#define __LOOPING_STRUCTURE_H

#include "list.h"

typedef int (*mapperFn) (int);
typedef Bool (*predicateFn) (int);

List_ptr map(mapperFn, List_ptr);
List_ptr filter(predicateFn , List_ptr);

#endif
