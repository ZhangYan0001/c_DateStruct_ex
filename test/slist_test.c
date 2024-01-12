//
// Created by 20765 on 2024/1/10.
//

#include "slist_test.h"
#include <stdio.h>

void append_test(){
  int a = 10;
  int b = 20;
  SList* list = SListNew();
  for(int i = 0;i<100;++i){
    SListAppend(list,&i);
  }
  SListForeach(list);
  SListFree(list);
  list = nullptr;
  printf("\n");
  SListForeach(list);
}

void prepend_test(){
  SList* list = SListNew();
  for(int i = 0;i<100;++i){
    SListPrepend(list,&i);
  }
  SListForeach(list);
  SListFree(list);
  list = nullptr;
  printf("\n");
  SListForeach(list);
}

void erase_test(){
  SList* list = SListNew();
  for(int i = 0;i<100;++i){
    SListAppend(list,&i);
  }
  SListForeach(list);
  for(int j = 0;j<100;++j){
    SListErase(list);
  }
  SListForeach(list);
  SListFree(list);
  list = nullptr;
  printf("\n");
//  SListForeach(list);
}