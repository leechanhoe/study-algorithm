#include <iostream>
using namespace std;

int N, M;
int bead[300];

bool check(int mid){
    int sum = 0;
    int group = 1;

    for(int i = 0; i < N; i++) {
        sum += bead[i];
        if(sum > mid){
            sum = bead[i];
            group++;
        }
    }
    return group <= M;
}

void print(int mid){
    cout << mid << '\n';
    int sum = 0;
    int beadCnt = 0;
    for (int i = 0; i < N; i++){
        sum += bead[i];
        if(sum > mid) {
            sum = bead[i];
            M--;
            cout << beadCnt << ' ';
            beadCnt = 0;
        }
        beadCnt++;

        if (N - i == M)
            break;
    }

    while(M--){
        cout << beadCnt << ' ';
        beadCnt = 1;
    }
}

int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int le = 0, ri = 0, mid;
    for(int i = 0; i < N; i++){
        cin >> bead[i];
        le = le < bead[i] ? bead[i] : le;
        ri += bead[i];
    }

    while (le <= ri){
        mid = (le + ri) / 2;
        if(check(mid)){
            ri = mid - 1;
        }
        else{
            le = mid + 1;
        }
    }
    print(le);
}