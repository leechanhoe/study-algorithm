#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> num;
bool card[1000001];
int ans[1000001];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0, tmp; i < N; i++){
        cin >> tmp;
        num.push_back(tmp);
        card[tmp] = true;
    }

    for(int i = 0; i < N; i++){
        for(int j = num[i] * 2; j < 1000001; j += num[i]){
            if(card[j]){
                ans[num[i]]++;
                ans[j]--;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[num[i]] << ' ';
    }
    return 0;
}