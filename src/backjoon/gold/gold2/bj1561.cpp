#include <iostream>
#define ll long long
using namespace std;

int N, M;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int input;
    for(int i = 0; i < M; i++){
        cin >> arr[i];
    }

    ll le = 0;
    ll ri = 60000000000;
    ll time = 0;
    if(N <= M){
        cout << N;
        return 0;
    }

    while(le <= ri){
        ll mid = (le + ri) / 2;
        ll ridden = M;
        for(int i = 0; i < M; i++){
            ridden += mid / arr[i];
        }
        if(ridden >= N){
            time = mid;
            ri = mid - 1;
        }
        else{
            le = mid + 1;
        }
    }

    ll ridden = M;
    for(int i = 0; i < M; i++){
            ridden += (time - 1) / arr[i];
    }

    for(int i = 0; i < M; i++){
        if(time % arr[i] == 0){
            ridden++;
        }
        if(ridden == N){
            cout << i + 1;
            return 0;
        }
    }
}