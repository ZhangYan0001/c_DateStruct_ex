//
// Created by 20765 on 2024/1/10.
//

#include "slist_test.h"

#include <stdio.h>

void append_test() {
  int a = 10;
  int b = 20;
  SList* list = SListNew();
  for (int i = 0; i < 100; ++i) {
    SListAppend(list, &i);
  }
  SListForeach(list);
  SListFree(list);
  list = nullptr;
  printf("\n");
  SListForeach(list);
}

void prepend_test() {
  SList* list = SListNew();
  for (int i = 0; i < 100; ++i) {
    SListPrepend(list, &i);
  }
  SListForeach(list);
  SListFree(list);
  list = nullptr;
  printf("\n");
  SListForeach(list);
}

void erase_test() {
  SList* list = SListNew();
  for (int i = 0; i < 100; ++i) {
    SListAppend(list, &i);
  }
  SListForeach(list);
  for (int j = 0; j < 100; ++j) {
    SListErase(list);
  }
  SListForeach(list);
  SListFree(list);
  list = nullptr;
  printf("\n");
  //  SListForeach(list);
}

void insert_test() {
  SList* list = SListNew();
  for (int i = 0; i < 10; ++i) {
    SListPrepend(list,&i);
  }
  int a = 20;
  for (int i = 0; i < 20; i+=2) {
    SListInsert(list, i, &a);
  }
  SListForeach(list);
  printf("%d\n",SListGetSize(list));
  SListFree(list);
  list = nullptr;
  printf("\n");
  SListForeach(list);
}

void delete_test() {
  SList* list = SListNew();
  for (int i = 0; i < 10; ++i) {
    SListAppend(list, &i);
  }
  int a = 13;
  SListInsert(list,5,&a);
  SListForeach(list);
  SListDelete(list,0);
//  for (int i = 9; i >= 0; --i) {
//    SListDelete(list, i);
//    SListForeach(list);
//  }
  //  SListDelete(list,5);
  SListForeach(list);
  free(list);
  list = nullptr;
  SListForeach(list);
}