#include <iostream>
using namespace std;

int ans;

void merge(int* arr, int start, int mid, int end, int K){
    int tmp[end+2];
    int i = start, j = mid + 1, t = 1;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            tmp[t++] = arr[i++];
        }
        else{
            tmp[t++] = arr[j++];
        }
    }

    while(i <= mid){
        tmp[t++] = arr[i++];
    }
    while(j <= end){
        tmp[t++] = arr[j++];
    }

    i = start, t = 1;
    while(i <= end){
        arr[i++] = tmp[t++];
        if(++ans == K){
            cout << tmp[t-1];
        }
    }
}

void merge_sort(int* arr, int start, int end, int K){
    if(start >= end)
        return;

    int mid = (start + end) / 2;
    merge_sort(arr, start, mid, K);
    merge_sort(arr, mid + 1, end, K);
    merge(arr, start, mid, end, K);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    int* arr = new int[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    merge_sort(arr, 0, N-1, K);
    if(ans < K){
        cout << -1;
    }
}