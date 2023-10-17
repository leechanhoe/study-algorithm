#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int port[40001];
vector<int> v;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> port[i];
    
    for(int i = 0; i < N; i++){
        if(v.size() == 0 || v[v.size()-1] < port[i])
            v.push_back(port[i]);
        else{
            int idx = lower_bound(v.begin(), v.end(), port[i]) - v.begin();
            v[idx] = port[i];
        }
    }

    cout << v.size();
    return 0;
}