#include "looping_structure.h"
#include "functions.h"

int main()
{
  List_ptr list = create_list();
  add_to_end(list,2);
  add_to_end(list,3);
  add_to_end(list,4);
  add_to_end(list,5);
  display(list);
  printf("\n");
  List_ptr mapped_list = map(&increment,list);
  display(mapped_list);
}