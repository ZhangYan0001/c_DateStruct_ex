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
  free(node->data);
  node->data = nullptr;
  free(node);
}

void SListFree(SList* list) {
  if (!list) {
    return;
  }
  Node* current = list->first;
  while (current != nullptr) {
    Node* next = current->next;
    //      free(current->data);
    free(current);
    current = next;
  }
  free(list);
  list = nullptr;
}

int SListAppend(SList* list, NodeValue value) {
  //todo 错误处理规范化
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == nullptr) {
    fprintf(stderr, "Error: failed to allocate for new node\n");
    return -1;
  }
  node->data = value;
  node->next = nullptr;

  if (list->first) list->last->next = node;
  else
    list->first = node;

  list->last = node;
  list->size++;
  return 1;
}

int SListPrepend(SList* list, NodeValue value) {
  //todo 错误处理规范化
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == nullptr) {
    fprintf(stderr, "Error: failed to allocate for new node\n");
    return -1;
  }
  if (list == nullptr) {
    fprintf(stderr, "Error: the list is null\n");
    return -1;
  }
  //todo 还有优化的空间
  if (list->size == 0) {
    list->last = node;
    node->next = nullptr;
  } else {
    node->next = list->first;
  }
  node->data = value;
  list->first = node;
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
    if (tmp->next != nullptr) tmp = tmp->next;
    else {
      printf("\n");
      break;
    }
  }
}

void SListInsert(SList* list, unsigned int n, NodeValue data) {
  if (list == nullptr) {
    fprintf(stderr, "Error: the list is null");
    return;
  }
  int length = list->size;
  if (n < 0 || n >= length) {
    fprintf(stderr, "Error: out of range");
  }
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == nullptr) {
    fprintf(stderr, "Error: failed to allocate the new node\n");
    return;
  }
  Node* tmp = list->first;
  while (n) {
    tmp = tmp->next;
    --n;
  }
  Node* next = tmp->next;
  node->next = next;
  node->data = data;
  tmp->next = node;

  list->size++;
}

void SListDelete(SList* list, unsigned int n) {
  if (list == nullptr) {
    fprintf(stderr, "Error: the list is null");
    return;
  }
  int length = list->size;
  if (n < 0 || n >= length) {
    fprintf(stderr, "Error: out of range");
  }
  Node* prev = list->first;
  if (n == 0) {
    free(list->first);
    list->first = prev->next;
    return;
  }
  --n;
  while (n) {
    prev = prev->next;
    --n;
  }
  if (prev->next->next == nullptr) {
    list->last = prev;
  }
  prev->next = prev->next->next;
  list->size--;
}
