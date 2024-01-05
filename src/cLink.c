//
// Created by 20765 on 2024/1/3.
//

#include "cLink.h"

Link* create_link(){
  Link* link = (Link*) malloc(sizeof(Link));
  link->size = 1;
  link->head = (Node*) malloc(sizeof(Node));
  link->tail = link->head;
  link->head->next = NULL;
  link->head->data = NULL;
  return link;
}

Link* create_link_n(size_t n){
  Link* link = (Link*) malloc(sizeof(Link));
  Link* tmp = link;
  link->size = n;
  while(--n){
    link->head = (Node*)malloc(sizeof(Node));
    link->head->data = NULL;
    link->head=link->head->next;
  }
  link->tail = link->head;
  return tmp;
}

void link_add_node(Link* link,Node* node){

}