//
// Created by 20765 on 2024/1/3.
//

#ifndef C_LINK_H_
#define C_LINK_H_
#include <errno.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
  void* data;
  struct Node_* next;
} Node;

typedef struct Link_ {
  size_t size;
  Node* head;
  Node* tail;
  void (*dump)(void*);
  int (*cmp)(const void*, const void*);
} Link;

Link* create_link();
Link* create_link_n(size_t n);
void add_node_end(Link* link, Link* n);
void remove_node_end(Link* link);
void for_each(Link* link);
#endif//C_LINK_H_
