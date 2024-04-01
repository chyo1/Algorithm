#include <stdio.h>
#include <assert.h>
#define MAX_HEAP_SIZE 100000
typedef int element;
element heap[MAX_HEAP_SIZE];
int heap_size = 0;
void insert_max_heap(element item)
{
	int i = ++heap_size;
	assert(i < MAX_HEAP_SIZE);

	while ((i != 1) && (item > heap[i / 2]))
	{
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}
int delete_max_heap() {
	int child = 2, parent = 1;
	element temp, item;
	item = heap[1], temp = heap[heap_size];
	if (!heap_size) return 0;
	heap_size -= 1;
	while (child <= heap_size) {
		if (child < heap_size && heap[child + 1] > heap[child]) child += 1;
		if (temp >= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
int main()
{
	int num, n, i, del;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &n);
		if (n > 0) insert_max_heap(n);
		else if (!n) {
			del = delete_max_heap();
			printf("%d\n", del);
		}
	}

	return 0;
}