#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000001];
vector<int> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(); cout.tie();

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < N; i++){
        if(v.empty() || v[v.size()-1] < arr[i])
            v.push_back(arr[i]);
        else{
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
        }
    }

    cout << v.size();
    return 0;
}