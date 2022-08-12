#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N;
pair<int, int> lines[MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> lines[i].first >> lines[i].second;

    sort(lines, lines + N);

    int start = lines[0].first;
    int end = lines[0].second;
    int ans = 0;
    for(int i = 1; i < N; i++){
        if(lines[i].first <= end)
            end = max(lines[i].second, end);
        else{
            ans += end - start;
            start = lines[i].first;
            end = lines[i].second;
        }
    }
    ans += end - start;
    cout << ans;
}