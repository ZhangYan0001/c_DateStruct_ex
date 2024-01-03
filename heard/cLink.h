//
// Created by 20765 on 2024/1/3.
//

#ifndef C_LINK_H_
#define C_LINK_H_
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Link {
  struct Link* next;
  int value;
} Link;

Link* create_link();
Link* create_link_n(size_t n);
void add_node_end(Link* link, Link* n);
void remove_node_end(Link* link);
void for_each(Link* link);
#endif//C_LINK_H_
