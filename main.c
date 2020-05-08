#include "looping_structure.h"
#include "functions.h"

int main()
{
  List_ptr list = create_list();
  add_to_end(list,0);
  add_to_end(list,3);
  add_to_end(list,4);
  add_to_end(list,5);
  display(list);
  printf("\n");
  int result = reduce(&add,list,0);
  printf("%d",result);
}