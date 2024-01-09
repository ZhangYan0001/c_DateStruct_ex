#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

int main() {
  SList* list = SListNew();
  int b = 20;
  SListAppend(list, &b);
  printf("%d \n", SListGetSize(list));
  SListForeach(list);
  printf("----------\n");
  SListErase(list);
  printf("%d \n", SListGetSize(list));
  SListForeach(list);
  printf("----------\n");
  int a = 30;
  SListAppend(list, &a);
  SListAppend(list, &a);
  SListAppend(list, &a);
  printf("%d \n", SListGetSize(list));
  SListForeach(list);
  SListFree(list);
  return 0;
}
