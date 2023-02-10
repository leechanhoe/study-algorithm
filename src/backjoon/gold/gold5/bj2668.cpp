#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[101];
vector<int> ans;

bool isCycle(int start){
    bool* visit = new bool[N+1]{false};
    int next = arr[start];
    while(!visit[next]){
        if(next == start){
            return true;
        }
        visit[next] = true;
        next = arr[next];
    }
    return false;
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        if(isCycle(i))
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(int i : ans){
        cout << i << '\n';
    }

    return 0;
}