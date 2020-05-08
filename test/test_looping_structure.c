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

int main()
{
  test_map();
  return 0;
}

