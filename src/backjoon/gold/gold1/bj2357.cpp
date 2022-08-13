#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
vector<int> minTree, maxTree;

void init(int node, int start, int end){
    if(start == end){
        minTree[node] = maxTree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

pair<int, int> find(int node, int a, int b, int left, int right){
    if (left > b || right < a)
        return make_pair(1987654321, 0);
    if (a <= left && right <= b)
        return make_pair(minTree[node], maxTree[node]);

    pair<int, int> le, ri;
    int mid = (left + right) / 2;
    le = find(node * 2, a, b, left, mid);
    ri = find(node * 2 + 1, a, b, mid + 1, right);
    return make_pair(min(le.first, ri.first), max(le.second, ri.second));
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int N, M, a, b;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    minTree.resize(N * 4);
    maxTree.resize(N * 4);
    init(1, 0, N - 1);

    for (int i = 0; i < M; i++){
        cin >> a >> b;
        pair<int, int> ans = find(1, a-1, b-1, 0, N - 1);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}