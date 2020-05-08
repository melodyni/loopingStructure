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


Status remove_from_start(List_ptr list){
  if(list->head == NULL){
    return Failure;
  }
  Node_ptr node_to_remove = list->head;
  list->head = list->head->next;
  free(node_to_remove);
  list->count--;
  return Success;
}

Status remove_from_end(List_ptr list){
  if(list->head == NULL){
    return Failure;
  }
  if(list->count == 1){
    return remove_from_start(list);
  }
  Node_ptr p_walk = list->head;
  while(p_walk->next->next != NULL){
    p_walk = p_walk->next;
  }
  list->last = p_walk;
  free(p_walk->next);
  p_walk->next = NULL;
  list->count--;
  return Success;
}


Status clear_list(List_ptr list){
  Status status = Success;
  while(list->head != NULL){
    status =  remove_from_end(list);
  }
  list->last = NULL;
  return status;
}

void destroy_list(List_ptr list){
  clear_list(list);
  free(list);
}

Status compare(List_ptr list_a, List_ptr list_b){
  Status status = Success;
  Node_ptr p_walk_a = list_a->head;
  Node_ptr p_walk_b = list_b->head;
  while(p_walk_a == NULL){
    if(p_walk_a->value != p_walk_b->value){
      status = Failure;
    }
    p_walk_a = p_walk_a->next;
    p_walk_b = p_walk_b->next;
  }
  return status;
}