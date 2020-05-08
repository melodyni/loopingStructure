#include "looping_structure.h"

List_ptr map(mapperFn mapper, List_ptr list){
  Node_ptr p_walk = list->head;
  List_ptr mapped_array = create_list();
  while (p_walk != NULL)
  {
    int mapped_val = (*mapper)(p_walk->value);
    add_to_end(mapped_array, mapped_val);
    p_walk = p_walk->next;
  }
  return mapped_array;
}

