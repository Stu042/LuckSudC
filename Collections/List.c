#include "List.h"
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>


const int LIST_INITIAL_SIZE = 8;


void listChangeCapacity(List *list, long newCapacity);

void incCapacity(List *list);

void decCapacity(List *list);


List *ListNew() {
	List *list = (List *) malloc(sizeof(List));
	list->Count = 0;
	list->Capacity = LIST_INITIAL_SIZE;
	list->Items = (void ***) malloc(sizeof(void **) * LIST_INITIAL_SIZE);
	return list;
}


void ListFree(List *list) {
	if (list == NULL) {
		return;
	}
	if (list->Capacity > 0) {
		free(list->Items);
	}
	free(list);
}

void ListAddLast(List *list, void *item) {
	if (list == NULL) {
		return;
	}
	incCapacity(list);
	list->Items[list->Count] = item;
	list->Count++;
}

void ListAddFirst(List *list, void *item) {
	if (list == NULL) {
		return;
	}
	incCapacity(list);
	void *dst = &(list->Items[1]);
	void *src = list->Items;
	size_t size = list->Count * sizeof(void **);
	memmove(dst, src, size);
	list->Items[0] = item;
	list->Count++;
}


void ListRemove(List *list, void *item) {
	if (list == NULL || item == NULL) {
		return;
	}
	for (long i = 0; i < list->Count; i++) {
		if (list->Items[i] == item) {
			void *dst = &(list->Items[i]);
			void *src = dst + sizeof(void **);
			size_t size = (list->Count - i) * sizeof(void **);
			memmove(dst, src, size);
			--list->Count;
			decCapacity(list);
			return;
		}
	}
}

void *ListRemoveFirst(List *list) {
	if (list == NULL || list->Count == 0) {
		return NULL;
	}
	void *item = list->Items[0];
	void *dst = list->Items;
	void *src = &(list->Items[1]);
	size_t size = (list->Count - 1) * sizeof(void *);
	memmove(dst, src, size);
	--list->Count;
	decCapacity(list);
	return item;
}


void *ListRemoveLast(List *list) {
	if (list == NULL || list->Count == 0) {
		return NULL;
	}
	--list->Count;
	void *item = list->Items[list->Count];
	decCapacity(list);
	return item;
}

void ListClear(List *list) {
	list->Count = 0;
	decCapacity(list);
}


void *LifoPop(Lifo *lifo) {
	void *item = ListRemoveLast(lifo);
	return item;
}

void LifoPush(Lifo *lifo, void *item) {
	ListAddLast(lifo, item);
}

void FifoPush(Fifo *fifo, void *item) {
	ListAddLast(fifo, item);
}

void *FifoPop(Fifo *fifo) {
	void *item = ListRemoveFirst(fifo);
	return item;
}




///////////////////////////////////////
/// private functions


void listChangeCapacity(List *list, long newCapacity) {
	if (list->Capacity == newCapacity) {
		return;
	}
	void *newMem = realloc(list->Items, newCapacity);
	if (newMem == NULL) {
		perror("List, unable to change capacity, out of memory.");
		exit(1);
	}
	list->Items = newMem;
	list->Capacity = newCapacity;
}


void decCapacity(List *list) {
	long quartCurrentCapacity = list->Capacity / 4;
	long targetCapacity = quartCurrentCapacity < LIST_INITIAL_SIZE ? LIST_INITIAL_SIZE : quartCurrentCapacity;
	long setCapacity = quartCurrentCapacity < LIST_INITIAL_SIZE ? LIST_INITIAL_SIZE : quartCurrentCapacity * 2;
	if (list->Count <= targetCapacity) {
		listChangeCapacity(list, setCapacity);
	}
}


void incCapacity(List *list) {
	if (list->Count >= list->Capacity) {
		listChangeCapacity(list, list->Capacity * 2);
	}
}
