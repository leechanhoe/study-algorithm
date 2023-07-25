#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int cnt[4];
int type[3] = {1, 2, 3};

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    int ans = 987654321;
    do{
        int tmp[4][4] = {0};
        int sp = 0; // arr의 현재 idx - 순열이 123이면 11122333 으로 탐색
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < cnt[type[i]]; j++){
                tmp[type[i]][arr[sp+j]]++;
            }
            sp += cnt[type[i]]; // 123일경우 1을 다 탐색하면 2가 나와야함
        }

// 23, 32중 큰걸로 바꿔야 하는 이유
// 1 2 2 3 1 1 1 2
// 1 1 1 1 2 2 2 3
// 1 1 1 1 2 2 3 2
// 다르면 무조건 바꿔야 하기 때문에 둘중 큰거선택
        ans = min(ans, tmp[1][2] + tmp[1][3] + max(tmp[2][3], tmp[3][2]));
    }while(next_permutation(type, type + 3));

    cout << ans;
    return 0;
}