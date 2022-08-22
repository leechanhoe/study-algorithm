#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 2000000000
long long N;
long long seg[400001];
long long x, ans;
long long h[100001];

int makeSeg(int node, int s, int e){
    if (s == e)
        return seg[node] = s;
    int mid = (s + e) / 2;
    int left = makeSeg(2 * node, s, mid);
    int right = makeSeg(2 * node + 1, mid + 1, e);

    return seg[node] = h[left] < h[right] ? left : right;
}

int find(int node, int s, int e, int le, int ri){ // 구간에서 제일 낮은 인덱스 반환
    if(e < le || ri < s) // 구간이 아예 안겹칠때
        return INF;
    if(le <= s && e <= ri) // 구간이 아예 포함될떄
        return seg[node]; // 현재의 최솟값이 포함되는 구간의 최솟값이기도 하므로

    // 부분적으로 겹칠때
    int mid = (s + e) / 2; 
    int left = find(node * 2, s, mid, le, ri);
    int right = find(node * 2 + 1, mid + 1, e, le, ri);

    if (left == INF) // 에러방지
        return right;
    else if(right == INF)
        return left;
    else
        return seg[node] = h[left] < h[right] ? left : right;
}

void solve(long long left, long long right){
    if(left > right)
        return;

    long long idx = find(1, 0, N - 1, left, right);
    
    ans = max(ans, h[idx] * (right - left + 1));
    solve(left, idx - 1);
    solve(idx + 1, right);
}

int main(){
    while(1){
        ans = 0;
        cin >> N;
        if(!N)
            break;
        
        for (int i = 0; i < N; i++)
            cin >> h[i];
        
        makeSeg(1, 0, N - 1);
        solve(0, N - 1);

        cout << ans << '\n';
    }
}