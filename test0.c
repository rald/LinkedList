#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

void Print_List(List *list) {
	List *iter=list;
	while(iter) {
		printf("%i ",*(int*)iter->data);
		iter=iter->next;
	}
	printf("\n");
}

int asccmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}

int dsccmp(const void *a,const void *b) {
	return *(int*)b-*(int*)a;
}

int main(int argc,char **argv) {
	
	int i;
	int *number;
	int *data;
	List *list=NULL;
	List *node=NULL;

	printf("Pushing Back Numbers 0-9\n");
	for(i=0;i<10;i++) {
		number=malloc(sizeof(*number));
		*number=i;
		printf("PushBack %i\n",*number);
		List_PushBack(&list,number);
		Print_List(list);
	}

	printf("Descending Sort\n");
	List_Sort(&list,dsccmp);
	Print_List(list);

	printf("Ascending Sort\n");	
	List_Sort(&list,asccmp);
	Print_List(list);

	printf("Remove Item At Index 5\n");	
	node=List_RemoveAt(&list,5);
	printf("Removed "); Print_List(node);
	List_Free(&node);
	
	printf("Set Item At Index 0 With -1\n");	
	number=malloc(sizeof(*number));
	*number=-1;
	List_Set(&list,0,number);
	Print_List(list);

	node=List_PopFront(&list);
	printf("PopFront "); Print_List(node);
	List_Free(&node);
	Print_List(list);

	node=List_PopBack(&list);
	printf("PopBack "); Print_List(node);
	List_Free(&node);
	Print_List(list);

	printf("Freeing List\n");
	List_Free(&list);

	printf("Pushing Front Numbers 0-9\n");
	for(i=0;i<10;i++) {
		number=malloc(sizeof(*number));
		*number=i;
		printf("PushFront %i\n",*number);
		List_PushFront(&list,number);
		Print_List(list);
	}
	
	return 0;
}
