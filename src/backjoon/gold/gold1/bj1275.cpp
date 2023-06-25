#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
ll arr[100001];
ll segTree[400004];

ll makeTree(int start, int end, int node){
    if(start == end)
        return segTree[node] = arr[start];
    
    int mid = (start + end) / 2;
    return segTree[node] = makeTree(start, mid, node * 2) + makeTree(mid + 1, end, node * 2 + 1);
}

ll getSum(int start, int end, int left, int right, int node){
    if(right < start || end < left)
        return 0;
    if(left <= start && end <= right)
        return segTree[node];
    
    int mid = (start + end) / 2;
    return getSum(start, mid, left, right, node * 2) + getSum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int node, int idx, ll diff){
    if(idx < start || end < idx)
        return;
    segTree[node] += diff;
    if(start == end)
        return;
    
    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    makeTree(1, N, 1);

    while(Q--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y)
            swap(x, y);
        cout << getSum(1, N, x, y, 1) << '\n';

        ll diff = b - arr[a];
        arr[a] = b;
        update(1, N, 1, a, diff);
    }
    return 0;
}