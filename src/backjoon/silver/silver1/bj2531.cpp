#include <iostream>
#include <vector>
using namespace std;

int N, d, k, c, ans, type;
int cnt[3001];
vector<int> dish;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> d >> k >> c;

    for(int i = 0; i < N; i++){
        int inpu;
        cin >> inpu;
        dish.push_back(inpu);
    }

    for(int i = 0; i < k; i++){
        dish.push_back(dish[i]);
        if(cnt[dish[i]]++ == 0)
            type++;
    }
    ans = type;
    if(cnt[c] == 0)
        ans++;

    for(int ri = k, le = 0; le < N; ri++, le++){
        if(--cnt[dish[le]] == 0)
            type--;       
        if(cnt[dish[ri]]++ == 0)
            type++;

        if(cnt[c] == 0)
            ans = max(ans, type + 1);
        else
            ans = max(ans, type);
    }
    cout << ans;
    return 0;
}