//
// Created by 20765 on 2024/1/11.
//

#ifndef SLIST2_H
#define SLIST2_H

#ifdef __cplusplus
extern "C" {
#endif

#define nullptr ((void*)0)
typedef void* NodeValue;

typedef struct SListNode_{
  struct SListNode_* next;
  NodeValue value;
}SListNode;

typedef struct List_{
  struct SListNode** root;
  int size;
}List;



#ifdef __cplusplus
}
#endif

#endif//SLIST2_H
