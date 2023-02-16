#include <iostream>
#include <vector>
#define INF 1987654321
using namespace std;

int N, M;
int arr[100001];
vector<int> tree;

int makeSegTree(int node, int start, int end){
    if(start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;
    int left = makeSegTree(node * 2, start, mid);
    int right = makeSegTree(node * 2 + 1, mid + 1, end);
    return tree[node] = min(left, right);
}

int query(int node, int start, int end, int left, int right){
    if(right < start || left > end)
        return INF;
    if(left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int le = query(node * 2, start, mid, left, right);
    int ri = query(node * 2 + 1, mid + 1, end, left, right);
    return min(le, ri);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    tree.resize(N * 4);
    makeSegTree(1, 0, N - 1);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << query(1, 0, N - 1, a - 1, b - 1) << '\n';
    }
    return 0;
}