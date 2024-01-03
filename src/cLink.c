//
// Created by 20765 on 2024/1/3.
//

#include "cLink.h"

Link* create_link() {
  Link* node = (Link*) malloc(sizeof(Link));
  node->next = NULL;
  node->value = 0;
  return node;
}

void add_node_end(Link* link, Link* n) {
  while (link->next != NULL) {
    link = link->next;
  }
  link->next = n;
  n->next = NULL;
}

void remove_node_end(Link* link) {
  if (link->next == NULL) {
    link = NULL;
    return;
  }
  while (link->next->next != NULL) {
    link = link->next;
  }
  link->next = NULL;
}

void for_each(Link* link) {
  while (link->next != NULL) {
    printf(" %d ", link->value);
    link = link->next;
  }
}