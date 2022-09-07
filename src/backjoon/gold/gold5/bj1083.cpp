#include <iostream>
using namespace std;

int arr[1000001];
int N, S;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> S;

    for(int i = 0; i < N && S > 0; i++){
        int max_ = arr[i];
        int maxIdx = i;
        for(int j = i + 1; j < N && j <= i + S; j++){
            if(max_ < arr[j]){
                max_ = arr[j];
                maxIdx = j;
            }
        }
        for(int j = maxIdx; j > i; j--){
            arr[j] = arr[j-1];
            // cout << arr[j] << arr[j-1] << '\n';
        }
        arr[i] = max_;
        S -= maxIdx - i;
        if(S == 0)
            break;
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
}