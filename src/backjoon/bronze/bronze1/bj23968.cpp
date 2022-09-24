#include <iostream>
using namespace std;

int N, K;

void swap(int* a, int* b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int bubbleSort(int* arr){
    int cnt = 0;

    for(int i = N-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                cnt++;
                swap(&arr[j], &arr[j+1]);
            }

            if(cnt == K){
                cout << arr[j] << ' ' << arr[j+1];
                return cnt;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;
    
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    if(bubbleSort(arr) < K)
        cout << -1;
}