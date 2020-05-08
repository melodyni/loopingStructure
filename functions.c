#include "functions.h"

int increment(int num){
  return num+1;
}

Bool is_odd(int num){
  if(num % 2 != 0){
    return True;
  }
  return False;
}

int add(int num_a,int num_b){
  return num_a + num_b;
}