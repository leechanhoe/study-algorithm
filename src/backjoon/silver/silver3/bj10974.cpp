#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[10];

void dfs(vector<int> v){
    if(v.size() == N){
        for(auto i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            dfs(v);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N;

    vector<int> v;
    dfs(v);
    return 0;
}