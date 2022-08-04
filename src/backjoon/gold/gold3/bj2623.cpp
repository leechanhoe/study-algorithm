#include <iostream>
#include <vector>
using namespace std;

int N, M;
int inDeg[1002];
vector<int> v[1002];
vector<int> ans;

int main() {
    cin >> N >> M;

    while(M--){
        int len;
        int s1, s2;
        cin >> len;
        if (!len)
            continue;
        cin >> s1;
        if (len == 1)
            continue;
        
        for (int i = 0; i < len-1; i++){
            cin >> s2;
            v[s1].push_back(s2);
            inDeg[s2]++;
            s1 = s2;
        }
    }

    vector<int> inDeg0;

    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) {
            inDeg0.push_back(i);
        }
    }

    while (!inDeg0.empty()){
        int s = inDeg0.back();
        inDeg0.pop_back();
        ans.push_back(s);

        for (int i = 0; i < v[s].size(); i++) {
            int next = v[s][i];
            inDeg[next]--;
            if (inDeg[next] == 0) {
                inDeg0.push_back(next);
            }
        }
    }
    if (ans.size() != N) 
        cout << 0 << endl;
    else {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << endl;
        }
    }
}