//
// Created by 20765 on 2024/1/7.
//

#ifndef CLINKLIST_H_
#define CLINKLIST_H_

#include <stdlib.h>

typedef struct LinkList_ {
  void* data;
  struct LinkList_* next;
} LinkList;

LinkList* create_link_list();
void add_link_list(LinkList* link_list);
void remove_link_list(LinkList* link_list);

#endif//CLINKLIST_H_
