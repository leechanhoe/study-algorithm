// #include <iostream>
// #include <algorithm>
// #define INF 2147483647
// using namespace std;

// int N, M;
// pair<int, int> meat[100000];
// int ps[100000]; // 누적합

// bool cmp(pair<int, int> a, pair<int, int> b){
//     if (a.second == b.second)
//         return a.first > b.first;
//     return a.second < b.second;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> N >> M;
//     for (int i = 0; i < N; i++)
//         cin >> meat[i].first >> meat[i].second;

//     if (N == 1){
//         if (meat[0].first >= M)
//             cout << meat[0].second;
//         else
//             cout << -1;
//         return 0;
//     }

//     sort(meat, meat + N, cmp);

//     int cost = meat[N-1].second;
//     int ans = 0;
//     int same = 0;
//     bool flag = false;
//     ps[0] = meat[0].first;
//     for (int i = 1; i < N; i++){
//         ps[i] = ps[i-1] + meat[i].first;
//         if (meat[i].second == meat[i-1].second){
//             same += meat[i].second;
//         }
//         else{
//             if (same > 0){
//                 ans = min(same, meat[i].second);
//             }
//             else{
//                 same = 0;
//                 ans = meat[i].second;
//             }
//         }

//         if (ps[i] >= M){
//             flag = true;
//             ans = cost;
//         }
//     }

//     // for (int i = 0; i < N; i++)
//     //     cout << ps[i] << ' ';
//     // cout << '\n';
//     if (!flag)
//         cout << -1;
//     else
//         cout << ans;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//가격 싼 순
// 같은 가격이면, 무거운거
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first > b.first;

	return a.second < b.second;
}

int n,need;
int answer = 2147483647;
vector<pair<int, int> > meat;


int main()
{
	cin >> n >> need;
	for (int i = 0; i < n; i++)
	{
		int price;
		int weight;
		cin >> weight >> price;
		meat.push_back(make_pair(weight, price));
	}

	sort(meat.begin(), meat.end(),cmp);

	//고기를 사면 그 아래 값은 전부 덤

	int sum_weight = 0;
	int sum_price = 0;
	int before = -1;
	for (int i = 0; i < meat.size(); i++)
	{
		if (sum_weight < need)
		{
			//동일 가격인놈이 있을때
			
			if (before == meat[i].second)
			{
				sum_price += meat[i].second;
			}
			else
			{
				before = sum_price = meat[i].second;
			}
		}
		else
		{
			//같은 가격 여러개 vs 비싼놈 하나 비교 필요
			if ((before != meat[i].second) && (sum_price >= meat[i].second))
			{
				before = sum_price = meat[i].second;
			}
		}

		sum_weight += meat[i].first;
	}

	if (sum_weight < need)
		cout << -1 << endl;
	else
		cout << sum_price << endl;

	return 0;
}