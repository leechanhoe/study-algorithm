#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ps[200001];
int color_sum[200001];
int ans[200001];
int overlap[200001];
int coverlap[200001];
int N;

bool cmp(vector<int> a, vector<int> b) {
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    vector<vector<int>> ball(N, vector<int>(3));
    for (int i = 0; i < N; i++){
        cin >> ball[i][0] >> ball[i][1];
        ball[i][2] = i;
    }

    sort(ball.begin(), ball.end(), cmp);
    
    ps[0] = color_sum[ball[0][0]] = ball[0][1];

    for (int i = 1; i < N; i++){
        if(ball[i][1] == ball[i-1][1]){ // 크기가 같을때
            overlap[i] = ball[i][1] + overlap[i-1];
            if(ball[i][0] == ball[i-1][0]) // 색도 같을때
                coverlap[i] = ball[i][1] + coverlap[i-1];
        }

        ans[ball[i][2]] = ps[i-1] - color_sum[ball[i][0]] - overlap[i] + coverlap[i];
        ps[i] = ps[i-1] + ball[i][1];
        color_sum[ball[i][0]] += ball[i][1];
    }
    
    for (int i = 0; i < N; i++)
        cout << ans[i] << '\n';
}