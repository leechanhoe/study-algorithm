#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int tc;
	int N, M;
	int importance;
	int count;

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		count = 0;
		scanf("%d %d", &N, &M);
		
		priority_queue<int> pq; // 내림차순 정렬해야 pop할 때 높은게 빠져나옴.
		queue<pair<int, int>> q;

		for (int j = 0; j < N; j++) {
			scanf("%d", &importance);
			q.push({ j, importance });
			pq.push(importance);
		}

		while (!q.empty()) {
			// 위치값과, 우선순위 값을 가져온 뒤 pop수행
			int location = q.front().first;
			int value = q.front().second;
			q.pop();
            
			// 값 비교
			if (pq.top() == value) {
				pq.pop();
				++count;
				if (M == location) {
					printf("%d\n", count);
					break;
				}
			}
			else q.push({ location, value });
		}
	}
}