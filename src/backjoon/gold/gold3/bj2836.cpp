#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> pass;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < N; i++){
        cin >> a >> b;
        if (a > b)
            pass.push_back(make_pair(b, a));
    }

    long long reverse = 0;
    if (!pass.empty()){
        sort(pass.begin(), pass.end());
        
        int start = pass[0].first;
        int end = pass[0].second;
        for (int i = 1; i < pass.size(); i++){
            if(pass[i].first <= end)
                end = max(end, pass[i].second);
            else{
                reverse += end - start;
                start = pass[i].first;
                end = pass[i].second;
            }
        }
        reverse += end - start;
    }
    long long ans = M + reverse * 2;
    cout << ans;
}