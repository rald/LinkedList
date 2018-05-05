#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef int (*List_Comparator)(const void*,const void*);

typedef struct List List;

struct List {
	void *data;
	List *next;
};

List *List_New(void *data,List *next);
void List_Free(List **head);
int List_Length(List *head);
void List_PushFront(List **head,void *data);
void List_PushBack(List **head,void *data);
List *List_PopFront(List **head);
List *List_PopBack(List **head);
List *List_RemoveAt(List **head,int n);
List *List_Get(List *head,int n);
void List_Set(List **head,int n,void *data);
void List_Swap(List *item1,List *item2);
void List_Sort(List **head,List_Comparator listComparator);

#endif
