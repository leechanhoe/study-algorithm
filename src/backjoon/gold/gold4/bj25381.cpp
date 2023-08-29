#include <iostream>
#include <queue>
using namespace std;

bool del[300001];
int ans;
string abc;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> abc;

    queue<int> q;
    for(int i = 0; i < abc.size(); i++){
        if(abc[i] == 'B')
            q.push(i);
        else if(!q.empty() && abc[i] == 'C'){
            del[q.front()] = true;
            q.pop();
            ans++;
        }
    }

    int a = 0;
    for(int i = 0; i < abc.size(); i++){
        if(abc[i] == 'A')
            a++;
        else if(abc[i] == 'B' && a && !del[i]){
            a--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}