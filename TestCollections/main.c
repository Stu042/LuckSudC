#include <stdio.h>
#include "Collections.h"

typedef struct VALUE {
	int A;
} Value;


// internal protos
void PrintInfo();

void TestAddFirst();

void TestAddLast();

void TestRemoveLast();
void TestRemoveFirst();


const Value value1 = {111};
const Value value2 = {2222};
const Value value3 = {33333};
const Value value4 = {444444};
const Value values[] = {value1, value2, value3, value4};

int main(void) {
	PrintInfo();
	TestAddFirst();
	TestAddLast();
	TestRemoveLast();
	TestRemoveFirst();
	return 0;
}

const char *boolString(int boolValue) {
	return boolValue ? "true" : "false";
}

void PrintInfo() {
	printf("value1 address: %p\n", &value1);
	printf("value2 address: %p\n", &value2);
	printf("value3 address: %p\n", &value3);
	printf("value4 address: %p\n", &value4);
}


void TestAddFirst() {
	printf("\nTestAddFirst\n");
	List *list = ListNew();
	ListAddFirst(list, (void *) &value1);
	ListAddFirst(list, (void *) &value2);
	ListAddFirst(list, (void *) &value3);
	for (int i = 0; i < list->Count; ++i) {
		void **itemAddr = list->Items[i];
		int value = *((int *) itemAddr);
		printf("Item: %d, Value address: %p, Value: %d %s\n", i, itemAddr, value, boolString(value == values[2 - i].A));
	}
}

void TestAddLast() {
	printf("\nTestAddLast\n");
	List *list = ListNew();
	ListAddLast(list, (void *) &value1);
	ListAddLast(list, (void *) &value2);
	ListAddLast(list, (void *) &value3);
	for (int i = 0; i < list->Count; i++) {
		void **itemAddr = list->Items[i];
		int value = *((int *) itemAddr);
		printf("Item: %d, Value address: %p, Value: %d %s\n", i, itemAddr, value, boolString(value == values[i].A));
	}

}

void TestRemoveLast() {
	printf("\nTestRemoveLast\n");
	List *list = ListNew();
	ListAddLast(list, (void *) &value3);
	ListAddLast(list, (void *) &value2);
	ListAddLast(list, (void *) &value1);
	int index = 0;
	while (list->Count > 0) {
		void *val = ListRemoveLast(list);
		int fromList = ((Value*)val)->A;
		int fromArray = (values[index]).A;
		printf("from list == from array: %d == %d = %s\n", fromList, fromArray, boolString(fromList == fromArray));
		index++;
	}
}

void TestRemoveFirst() {
	printf("\nTestRemoveLast\n");
	List *list = ListNew();
	ListAddFirst(list, (void *) &value3);
	ListAddFirst(list, (void *) &value2);
	ListAddFirst(list, (void *) &value1);
	int index = 0;
	while (list->Count > 0) {
		void *val = ListRemoveFirst(list);
		int fromList = ((Value*)val)->A;
		int fromArray = (values[index]).A;
		printf("from list == from array: %d == %d = %s\n", fromList, fromArray, boolString(fromList == fromArray));
		index++;
	}
}
