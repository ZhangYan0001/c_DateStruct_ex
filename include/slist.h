//
// Created by 20765 on 2024/1/8.
//

#ifndef SLIST_H_
#define SLIST_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define nullptr ((void*) 0)
typedef void* NodeValue;


typedef struct SList_Node_ {
  struct SList_Node_* next;
  NodeValue data;
} Node;

typedef struct SList_ {
  int size;
  Node* first;
  Node* last;
} SList;

SList* SListNew();
void SListFree(SList* list);

int SListAppend(SList* list, NodeValue value);
int SListPrepend(SList* list, NodeValue value);
int SListErase(SList* list);

#define SListGetSize(list) ((list)->size)

void SListForeach(SList* list);

void SListInsert(SList* list, unsigned int n, NodeValue data);
void SListDelete(SList* list, unsigned int n);

SList* SListReverse(SList* list);
SList* SListRemove(SList* list);

#ifdef __cplusplus
}
#endif


#endif//SLIST_H_
