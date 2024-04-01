#include <stdio.h>
#include <assert.h>
#define MAX_HEAP_SIZE 100000
typedef int element;
element heap_M[MAX_HEAP_SIZE];
element heap_m[MAX_HEAP_SIZE];
int heap_size_M = 0;
int heap_size_m = 0;
void insert_max_heap(element item);
int delete_max_heap();
void insert_min_heap(element item);
int delete_min_heap();
int insert(element item, int num);
int main()
{
	int num, i, n;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &n);
		printf("%d\n", insert(n, i));
	}
	return 0;
}
void insert_max_heap(element item)
{
	int i = ++heap_size_M;
	assert(i < MAX_HEAP_SIZE);

	while ((i != 1) && (item > heap_M[i / 2]))
	{
		heap_M[i] = heap_M[i / 2];
		i /= 2;
	}
	heap_M[i] = item;
}
element delete_max_heap() {
	int child = 2, parent = 1;
	element temp, item;
	item = heap_M[1], temp = heap_M[heap_size_M];
	if (!heap_size_M) return 0;
	heap_size_M -= 1;
	while (child <= heap_size_M) {
		if (child < heap_size_M && heap_M[child + 1] > heap_M[child]) child += 1;
		if (temp >= heap_M[child]) break;
		heap_M[parent] = heap_M[child];
		parent = child;
		child *= 2;
	}
	heap_M[parent] = temp;
	return item;
}
void insert_min_heap(element item)
{
	int i = ++heap_size_m;
	assert(i < MAX_HEAP_SIZE);

	while ((i != 1) && (item < heap_m[i / 2]))
	{
		heap_m[i] = heap_m[i / 2];
		i /= 2;
	}
	heap_m[i] = item;
}
element delete_min_heap() {
	int child = 2, parent = 1;
	element temp, item;
	item = heap_m[1], temp = heap_m[heap_size_m];
	if (!heap_size_m) return 0;
	heap_size_m -= 1;
	while (child <= heap_size_m) {
		if (child < heap_size_m && heap_m[child + 1] < heap_m[child]) child += 1;
		if (temp <= heap_m[child]) break;
		heap_m[parent] = heap_m[child];
		parent = child;
		child *= 2;
	}
	heap_m[parent] = temp;
	return item;
}

int insert(element item, int num) {
	int tmp;
	if (num % 2 == 0) insert_max_heap(item);
	else insert_min_heap(item);
	if (num != 0 && (heap_M[1] > heap_m[1])) {
		tmp = heap_M[1];
		delete_max_heap();
		insert_max_heap(heap_m[1]);
		delete_min_heap();
		insert_min_heap(tmp);
	}
	return heap_M[1];
}