//
// Created by 20765 on 2024/1/8.
//

#include "slist.h"

SList* SListNew() {
  SList* list = (SList*) malloc(sizeof(SList));
  if (list == nullptr) {
    fprintf(stderr, "Error: failed to allocate for the slist\n");
    return nullptr;
  }
  list->first = nullptr;
  list->last = nullptr;
  list->size = 0;
  return list;
}

void NodeFree(Node* node) {
}

void SListFree(SList* list) {
  if (list != nullptr) {
    Node* current = list->first;
    while (current != nullptr) {
      Node* next = current->next;
      free(current);
      current = next;
    }
    free(list);
  }
}

int SListAppend(SList* list, NodeValue value) {
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == nullptr) {
    fprintf(stderr, "Error: failed to allocate for new node\n");
    return -1;
  }
  node->data = value;
  node->next = nullptr;

  if (list->first) {
    list->last->next = node;
    list->last = node;
  } else {
    list->first = node;
    list->last = node;
  }
  list->size++;
  return 1;
}

int SListErase(SList* list) {
  if (list == nullptr || list->size == 0) {
    fprintf(stderr, "Error: the list is null, can not remove\n");
    return -1;
  }
  if (list->first->next == nullptr) {
    free(list->first);
    list->first = nullptr;
  } else {
    Node* tmp = list->first;
    while (tmp->next->next != nullptr) {
      tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = nullptr;
    list->last = tmp;
  }
  list->size--;
  return 1;
}

void SListForeach(SList* list) {
  if (!list || list->size == 0) {
    printf("the list is null\n");
    return;
  }
  Node* tmp = list->first;
  while (tmp) {
    printf("%d ", *(int*) tmp->data);
    if (tmp != list->last) tmp = tmp->next;
    else {
      printf("\n");
      break;
    }
  }
}

