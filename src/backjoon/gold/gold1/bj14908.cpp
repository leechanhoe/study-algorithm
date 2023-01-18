#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<double, int> work[1001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        double T, S;
        cin >> T >> S;
        work[i] = {T/S, i};
    }
    sort(work + 1, work + N + 1);

    for(int i = 1; i <= N; i++){
        cout << work[i].second << ' ';
    }
    return 0;
}