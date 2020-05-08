#include "list.h"

Node_ptr create_node(int value){
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

List_ptr create_list(void){
  List *list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Status add_to_end(List_ptr list, int value){
  Node_ptr new_node = create_node(value);
  Node_ptr *node_to_set = &list->head;
  if(list->head != NULL){
    node_to_set = &list->last->next;
  }
  (*node_to_set) = new_node;
  list->last = new_node;
  list->count++;
  return Success;
}

void display(List_ptr list){
  Node_ptr p_walk = list->head;
  while(p_walk != NULL){
    printf(" %d ",p_walk->value);
    p_walk = p_walk->next;
  }
}