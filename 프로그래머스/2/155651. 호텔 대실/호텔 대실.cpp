#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pairs;

// 시작시간 기준 빠른 순, 시작 시간이 같다면 끝나는 시간 기준 빠른 순으로 정렬
bool cmp(pairs a, pairs b) {

	// start.hour == start.hour
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return (a.first < b.first);
}

int solution(vector<vector<string>> book_time) {
	vector <pairs> hourMin;
	priority_queue <int, vector<int>, greater<int>> pq;

	// string -> 시간 단위로 바꿔서 저장
	for (int i = 0; i < book_time.size(); i++) {
		int start, end;

		start = stoi(book_time[i][0]) * 60 + stoi(&book_time[i][0][3]);
		end = stoi(book_time[i][1]) * 60 + stoi(&book_time[i][1][3]) + 10;
		hourMin.push_back({ start, end });
		printf("%d %d\n", start, end);
	}

	// 큐 정렬
	sort(hourMin.begin(), hourMin.end(), cmp);

	int ans = 0;

	// 끝나는 시간을 저장, 끝나는 시간 < 다음 예약의 시작 시간이면 큐에서 pop
	for (int i = 0; i < hourMin.size(); i++) {
		int startTime = hourMin[i].first;
		if (pq.size() && startTime >= pq.top())
			pq.pop();
		pq.push(hourMin[i].second);

		// queue에 저장된 방의 최대 개수를 구함
		ans = ans > pq.size() ? ans : pq.size();
	}
	return ans;
}