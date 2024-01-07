//
// Created by 20765 on 2024/1/7.
//

#include "CLinkList.h"

LinkList* create_link_list() {
  LinkList* link_list = (LinkList*) malloc(sizeof(LinkList));
  link_list->data = NULL;
  link_list->next = NULL;
  return link_list;
}

