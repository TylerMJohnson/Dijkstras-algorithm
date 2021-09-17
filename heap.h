#ifndef HEAP_H
#define HEAP_H
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Element{
	unsigned int key; //unsigned so we can convert to -1
	int vertex;
};

struct Heap{
	int size;
	int capacity;
	Element* data;
};

Heap createHeap(int n);
void buildHeap(Heap &heap, Element* elements);
void heapify(Heap &heap, int i);
Element extractMin(Heap &heap);

void decreaseKey(Heap &heap, int element, int key);
bool isEmpty(Heap &heap);

int parentNode(int i);
int leftNode(int i);
int rightNode(int i);
#endif
