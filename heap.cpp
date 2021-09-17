#include "heap.h"

Heap createHeap(int n){
	Heap heap;
	heap.capacity = n;
	heap.size = 0;
	heap.data = (Element*) malloc((n + 1) * sizeof(Element));

	if(heap.data == NULL)
		cout << "Error: could not allocate that much memory\n";

	return heap;
}

void heapify(Heap &heap, int index){
	int left = leftNode(index);
	int right = rightNode(index);
	int smallest;

	if(left <= heap.size && heap.data[left].key < heap.data[index].key){
		smallest = left;
	} else {
		smallest = index;
	}
	if(right <= heap.size && heap.data[right].key < heap.data[smallest].key){
		smallest = right;
	}
	if(smallest != index){
		swap(heap.data[smallest], heap.data[index]);
		heapify(heap, smallest);
	}
}

void buildHeap(Heap &heap, Element* element){
	heap.size = heap.capacity;
	for(int i = 1; i <= heap.size; i++){
		heap.data[i] = element[i];
	}
	//linear time?
	for(int i = floor(heap.size / 2); i >= 1; i--){
		heapify(heap, i);
	}
}

Element extractMin(Heap &heap){
	Element minimum;
	minimum = heap.data[1];
	heap.data[1] = heap.data[heap.size];
	heap.size--;
	heapify(heap, 1);
	return minimum;
}

void decreaseKey(Heap &heap, int element, int key){
	heap.data[element].key = key;
	heap.data[element].vertex = element;

	while(element > 1 && (heap.data[parentNode(element)].key > heap.data[element].key
			|| heap.data[parentNode(element)].vertex > heap.data[element].vertex)){
		swap(heap.data[parentNode(element)], heap.data[element]);
		element = parentNode(element);
	}
}

bool isEmpty(Heap &heap){
	bool empty;
	if(heap.size == 0)
		empty = true;
	else
		empty = false;
	return empty;
}


int parentNode(int i){
	return floor(i / 2);
}

int leftNode(int i){
	return (i * 2);
}

int rightNode(int i){
	return ((i * 2) + 1);
}
