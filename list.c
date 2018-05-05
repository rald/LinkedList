#include "list.h"

List *List_New(void *data,List *next) {
	List *list=malloc(sizeof(*list));
	if(list) {
		list->data=data;
		list->next=next;
	}
	return list;
}

void List_Free(List **head) {  
  List *curr=*head;
  List *next;
  while(curr) {
    next=curr->next;
    free(curr);
    curr=next;
  }
  *head=NULL;
}

int List_Length(List *head) {
	int length=0;
	List *iter=head;
	while(iter) {
		length++;
		iter=iter->next;
	}
	return length;
}

void List_PushFront(List **head,void *data) {
	List *newNode=List_New(data,*head);
	*head=newNode;
}

void List_PushBack(List **head,void *data) {
	List *curr=*head;
	List *newNode=malloc(sizeof(*newNode));
	newNode->data=data;
	newNode->next=NULL;
	if(curr==NULL) {
		*head=newNode;
	} else {
		while(curr->next) curr=curr->next;
		curr->next=newNode;
	}
}

List *List_PopFront(List **head) {
	return List_RemoveAt(head,0);
}

List *List_PopBack(List **head) {
	return List_RemoveAt(head,List_Length(*head)-1);
}


List *List_Get(List *head,int n) {
	int i=0;
	List *iter=head;
	while(iter) {
		if(n==i) return iter; 
		i++;
		iter=iter->next;
	}
	return NULL;
}

void List_Set(List **head,int n,void *data) {
	List *item=List_Get(*head,n);
	if(item) {
		free(item->data);
		item->data=data;
	}
}

List *List_RemoveAt(List **head,int n) {
	List *before=List_Get(*head,n-1);
	if(before) {
		List *item=before->next;
		before->next=item->next;
		item->next=NULL;
		return item;
	} else {
		List *item=*head;
		if(item) {
			(*head)=(*head)->next;
			item->next=NULL;
			return item;
		}
	}
	return NULL;
}

void List_Sort(List **head,List_Comparator listComparator) {
	bool swapped;
	List *iter1;
	List *iter2;
	iter1=*head;
	while(iter1) {
		iter2=iter1->next;
		while(iter2) {
			if(listComparator(iter1->data,iter2->data)==1) {
				void *tmp=iter1->data;
				iter1->data=iter2->data;
				iter2->data=tmp;
			}
			iter2=iter2->next;
		}
		iter1=iter1->next;
	}
}
