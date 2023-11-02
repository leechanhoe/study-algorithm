#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
vector<int> lis;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    lis.push_back(arr[0]);
    for(int i = 1; i < N; i++){
        if(lis[lis.size()-1] < arr[i])
            lis.push_back(arr[i]);
        else{
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }
    cout << N - lis.size();
    return 0;
}