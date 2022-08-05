#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;

int N, M, K;
vector<long long> arr;

//세그먼트 트리 생성 - 구간이 단 하나만 될 때까지 구간을 반으로 나누어 가며 재귀적으로 접근할 수 있다.
long long segment_tree(vector<long long> &tree, int start, int end, int node){
    if (start == end) // 구간이 하나일때
        return tree[node] = arr[start];

    int mid = (start + end) / 2; // 구간을 둘로 나눈뒤 재귀호출
    return tree[node] = segment_tree(tree, start, mid, node*2) * segment_tree(tree, mid+1, end, node*2+1) % MOD;
}

//부분곱 구하기
long long get_mul (vector<long long> &tree, int start, int end, int left, int right, int node){
    if (left > end || right < start) // 구하려는 구간이 현재 구간에 아예 없으면
        return 1;

    if (left <= start && end <= right) // 현재 구간이 구하려는 구간범위 내에 있으면
        return tree[node];

    int mid = (start + end) / 2; // 구하려는 구간이 현재 구간에 걸쳐있으면(하나라도 속해있으면)
    return get_mul(tree, start, mid, left, right, node*2) * get_mul(tree, mid+1, end, left, right, node*2+1) % MOD;
}

//값 수정하기
long long edit_value(vector<long long> &tree, int start, int end, int node, int index, long long value){
    if (index < start || index > end) // 구하려는 인덱스가 현재 구간에 없으면
        return tree[node]; // 똑같은 값을 곱하기 위해 자기자신 그대로 리턴

    if (start == end) // 인덱스를 정확히 찾으면
        return tree[node] = value;

    int mid = (start + end) / 2; // 인덱스를 포함하는 구간 재귀탐색
    return tree[node] = edit_value(tree, start, mid, node*2, index, value) * edit_value(tree, mid+1, end, node*2+1, index, value) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    arr.push_back(-1); // 인덱스는 1부터 시작하므로
    for (int i = 0; i < N; i++){
        long long tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    vector<long long> tree(N * 4);
    segment_tree(tree, 1, N, 1); // 트리 생성

    for(int i = 0; i < M+K; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1) { // 값 변경
            edit_value(tree, 1, N, 1, b, c);
            arr[b] = c;
        }
        else if (a == 2){
            // 구간 b, c의 합 출력
            cout << get_mul(tree, 1, N, b, c, 1) << '\n';
        }
    }
}