#include "../looping_structure.h"
#include "../functions.h"


void green(){
  printf("\033[1;30m");
}

void red(){
  printf("\033[0;31m");
}

void white(){
  printf("\033[1;0m");
}

void print_result(int passed,char *message){
  if(passed){
    green();
    printf("   ✔ %s\n",message);
  }else{
    red();
    printf("   ✘ %s\n",message);
  }
  white();
}

void test_map(){
  printf("\nmap\n");
  List_ptr list = create_list();
  add_to_end(list,2); 
  add_to_end(list,3); 
  add_to_end(list,4);
  List_ptr expected = create_list();
  add_to_end(list,3); 
  add_to_end(list,4); 
  add_to_end(list,5);
  List_ptr actual = map(&increment,list);
  char message[] = "should increment each element in the given list by one";
  print_result(compare(actual,expected),message);
  destroy_list(list);
  destroy_list(actual);
  destroy_list(expected);
}

void test_filter(){
  printf("\nfilter\n");
  List_ptr list = create_list();
  add_to_end(list,3); 
  add_to_end(list,6); 
  add_to_end(list,8);
  add_to_end(list,7);
  add_to_end(list,4);
  List_ptr expected = create_list();
  add_to_end(list,3); 
  add_to_end(list,7); 
  List_ptr actual = filter(&is_odd,list);
  char message[] = "should filter odd numbers from the given list";
  print_result(compare(actual,expected),message);
  destroy_list(list);
  destroy_list(actual);
  destroy_list(expected);
}

void test_reduce(){
  printf("\nreduce\n");
  List_ptr list = create_list();
  add_to_end(list,1); 
  add_to_end(list,2); 
  add_to_end(list,3);
  add_to_end(list,4);
  add_to_end(list,5);
  int sum_of_list_elements = reduce(&add,list,0);
  char message[] = "should filter odd numbers from the given list";
  print_result(sum_of_list_elements == 15, message);
  destroy_list(list);
}

int main()
{
  test_map();
  test_filter();
  test_reduce();
  return 0;
}

