//
// Created by 20765 on 2024/1/11.
//

#ifndef SLIST2_H
#define SLIST2_H

#ifdef __cplusplus
extern "C" {
#endif

#define nullptr ((void*) 0)
typedef void* NodeValue;

typedef struct SListNode_ {
  struct SListNode_* next;
  NodeValue data;
} SListNode;

void slist_free(SListNode* list);
SListNode* slist_prepend(SListNode** list, NodeValue data);
SListNode* slist_append(SListNode** list, NodeValue data);
SListNode* slist_next(SListNode* node);
NodeValue slist_data(SListNode* node);
void slist_set_data(SListNode* node, NodeValue value);
SListNode* slist_nth_node(SListNode* node, unsigned int n);
NodeValue slist_nth_data(SListNode* node, unsigned int n);
unsigned int slist_length(SListNode* node);
int slist_remove_node(SListNode** list, SListNode* node);
void slist_sort(SListNode** list);

#ifdef __cplusplus
}
#endif

#endif//SLIST2_H
