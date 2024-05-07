#ifndef COLLECTIONS_LIST_H
#define COLLECTIONS_LIST_H


typedef struct LIST {
	void ***Items;
	long Count;
	long Capacity;
} List;

typedef List Lifo;
typedef List Fifo;


/// @brief Create a new empty List of pointers.
List *ListNew();

/// @brief Free a List, will not free the items, just the pointers to the items.
void ListFree(List *list);

/// @brief Add an item to the end of a List. List will increase in size if required.
void ListAddLast(List *list, void *item);

/// @brief Add an item to the start of a List. List will increase in size if required.
void ListAddFirst(List *list, void *item);

/// @brief Remove the specified item from the List, List may decrease in capacity.
void ListRemove(List *list, void *item);

/// @brief Remove and return the first item in the List, List may decrease in capacity.
void *ListRemoveFirst(List *list);

/// @brief Remove and return the last item in the List, List may decrease in capacity.
void *ListRemoveLast(List *list);


/// @brief Add an item to the end of a Lifo. Lifo will increase in size if required.
void LifoPush(Lifo *lifo, void *item);

/// @brief Remove and return the last item in the Lifo, Lifo may decrease in capacity.
void *LifoPop(Lifo *lifo);


/// @brief Add an item to the end of a Fifo. Fifo will increase in size if required.
void FifoPush(Fifo *fifo, void *item);

/// @brief Remove and return the first item in the Fifo, Fifo may decrease in capacity.
void *FifoPop(Fifo *fifo);

#endif //COLLECTIONS_LIST_H
