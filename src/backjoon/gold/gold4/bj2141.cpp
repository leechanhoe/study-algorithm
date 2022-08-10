#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> town[100001];
long long populPs[100001];
long long sum[100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> town[i].first >> town[i].second;
    sort(town, town + N);
    populPs[0] = town[0].second;

    for (int i = 1; i < N; i++) // 사람 수의 누적합
        populPs[i] = town[i].second + populPs[i-1];

    long long sumPeople = populPs[N-1];
    for (int i = 0; i < N; i++) // 좌측과 우측의 사람 수가 처음 반전될떄가 정답
        sum[i] -= sumPeople - populPs[i] * 2;

    cout << town[lower_bound(sum, sum + N, 0) - sum].first;
}