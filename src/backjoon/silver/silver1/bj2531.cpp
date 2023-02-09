#include <iostream>
#include <vector>
using namespace std;

int N, d, k, c, ans, now;
int type[3001];
vector<int> belt;

int main(){
    cin >> N >> d >> k >> c;

    for(int i = 0; i < N; i++){
        int s;
        cin >> s;
        belt.push_back(s);
    }

    for(int i = 0; i < k; i++){
        if(type[belt[i]] == 0)
            now++;
        type[belt[i]]++;
        belt.push_back(belt[i]);
    }

    ans = max(ans, (belt[c] == 0 ? now + 1 : now));
    for(int i = 0; i < N - 1; i++){
        type[belt[i]]--;
        if(type[belt[i]] == 0)
            now--;

        if(type[belt[i+k]] == 0)
            now++;
        type[belt[i+k]]++;

        ans = max(ans, (type[c] == 0 ? now + 1 : now));
    }
    cout << ans;
    return 0;
}