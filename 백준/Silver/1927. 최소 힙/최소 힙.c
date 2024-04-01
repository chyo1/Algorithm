#include <stdio.h>
void INSERT_HEAP(int X);
int DELETE_HEAP();
int heap[100000]; // 최소 힙
int heap_size = 0;
int main() {
	int N, i, x, size;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x > 0) INSERT_HEAP(x); // 힙에 값 삽입
		else if (x == 0) printf("%d\n", DELETE_HEAP());
	}
	return 0;
}
void INSERT_HEAP(int X) {
	int i=++heap_size;
	while ((i != 1) && (X < heap[i / 2])) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = X;
}
int DELETE_HEAP() {
	int parent = 1, child = 2;
	int min = heap[parent], last = heap[heap_size];
	if (!heap_size) return 0; // 꼭 넣기
	heap_size -= 1; // 주의
	while (child <= heap_size) {
		if ((child < heap_size) && (heap[child] > heap[child + 1])) child += 1;
		if (last <= heap[child]) break; // 주의 
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
	return min;
}