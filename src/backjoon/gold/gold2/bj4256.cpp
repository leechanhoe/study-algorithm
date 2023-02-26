#include <iostream>
using namespace std;

int pre[1001];
int in[1001];

void dnq(int s, int e, int root){ // root는 pre에서의 root idx
    for(int i = s; i < e; i++){
        if(in[i] == pre[root]){
            dnq(s, i, root + 1);
            dnq(i + 1, e, root + i + 1 - s);
            cout << pre[root] << ' ';
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> pre[i];
        }
        for(int i = 0; i < n; i++){
            cin >> in[i];
        }
        dnq(0, n, 0);
        cout << '\n';
    }    
    return 0;
}