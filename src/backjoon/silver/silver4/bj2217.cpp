#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int rope[100001];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> rope[i];
    }
    sort(rope, rope + N);

    for(int i = 0; i < N; i++){
        ans = max(ans, rope[i] * (N - i));
    }
    cout << ans;
}