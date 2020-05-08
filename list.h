#ifndef __LIST_H
#define __LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef enum
{
  Failure,
  Success
} Status;

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node *head;
  Node *last;
  int count;
} List;

typedef List *List_ptr;

List_ptr create_list(void);
Status add_to_end(List_ptr list, int value);
void display(List_ptr list);

#endif