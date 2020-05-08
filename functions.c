#include "functions.h"



int increment(int num){
  return num+1;
}

int is_odd(int num){
  if(num % 2 != 0){
    return 1;
  }
  return 0;
}