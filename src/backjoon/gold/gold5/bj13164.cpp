#include <iostream>
#include <algorithm>
using namespace std;

int N, K, kids[300000], ans;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> kids[i];
    ans = kids[N-1] - kids[0];

    for(int i = N - 1; i >= 1; i--)
        kids[i] -= kids[i-1];

    kids[0] = 0;
    sort(kids, kids + N, greater<int>());
    
    for (int i = 0; i < K - 1; i++)
        ans -= kids[i];
    cout << ans;
}