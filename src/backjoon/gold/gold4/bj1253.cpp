#include <iostream>
#include <map>
using namespace std;

int N;
int arr[2001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<int, pair<int, bool>> visit;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        visit[arr[i]] = {i, false};
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = i+1; j < N; j++){

            int sum = arr[i] + arr[j];
            if(visit.count(sum)){
                if(visit[sum].first == i || visit[sum].first == j){
                    continue;
                }
                visit[sum].second = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(visit[arr[i]].second){
            ans++;
        }
    }
    cout << ans;
}