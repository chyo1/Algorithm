#include <stdio.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0
#define NV 2001   // 노드 갯수
#define VER 50001 // 간선 갯수
#define INF 2000001  // 양방향 도로 거리의 최댓값

#define MAX_HEAP_SIZE 1001

int weight[NV][NV]; // 간선 간 거리
int distance[NV];  int found[NV];
int path[NV]; // 경로 
int st, nd, cnt, g, h;

int heap_size_m = 0;
int heap_m[MAX_HEAP_SIZE];

void shortestPath(int v, int n);
int choose(int distance[], int n, int found[]);
void print_path(int start, int end);

void insert_min_heap(int item);
int delete_min_heap();

int main()
{
	int T;	int n, m, t; 	int s; 	int a, b, d;

	int i, j, x;
	scanf("%d", &T); //테스트 케이스 
	while (T-- > 0) {
		scanf("%d%d%d", &n, &m, &t); //교차로, 도로, 후보의 개수
		scanf("%d%d%d", &s, &g, &h); //출발지, 흔적이 있는 간선

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i == j) weight[i][j] = 0;
				else weight[i][j] = INF;
			}
		}
		for (i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &d); //a, b 사이에 거리 d의 양방향 간선 존재
			weight[a][b] = weight[b][a] = d; //거리 저장
		}
		shortestPath(s, n);
		st = distance[g] < distance[h] ? g : h;
		nd = g + h - st;
		for (i = 0; i < t; i++) {
			scanf("%d", &x); //목적지 후보
			print_path(s, x);
		}
		while (heap_size_m > 0) printf("%d ", delete_min_heap());
		//printf("\n");
	}
	return 0;
}
void shortestPath(int v, int n) {
	int i, u, w, in, nd;
	for (i = 1; i <= n; i++) {
		found[i] = FALSE;
		distance[i] = weight[v][i];
		path[i] = v;
	}
	found[v] = TRUE;
	distance[v] = 0; //초기화`
	for (i = 0; i < n - 2; i++) {
		u = choose(distance, n, found);
		if (u < 0) continue;
		found[u] = TRUE;
		for (w = 1; w <= n; w++) {
			if (!found[w]) {
				if (distance[u] + weight[u][w] < distance[w]) {
					distance[w] = distance[u] + weight[u][w];
					path[w] = u;
				}
				else if (distance[u] + weight[u][w] == distance[w]) {
					in = u, nd = distance[g] > distance[h] ? g : h;
					if (w == nd) {
						if (in == (g + h - nd))
							path[w] = u;
					}
					else if (u == nd) path[w] = u;
					else {
						while (path[in] != nd) {
							if (in == v) break;
							in = path[in];
						}
						in = path[in];
						if (path[in] == (g + h - nd)) path[w] = u;
					}
				}
			}
		}
	} // 찾은 지점을 거쳐 가는 것이 더 빠를 때 수정
}
int choose(int distance[], int n, int found[]) {
	int i, min, minpos;  min = INF;  minpos = -1;
	for (i = 1; i <= n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_path(int start, int end) {
	int a = end;
	if (a != nd) {
		while (path[a] != nd) {
			if (path[a] == start) return;
			a = path[a];
		}
		a = path[a];
	}

	if (path[a] == st) {
		insert_min_heap(end);
	}
}

void insert_min_heap(int item)
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
int delete_min_heap() {
	int child = 2, parent = 1;
	int temp, item;
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