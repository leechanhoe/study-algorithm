#include<iostream>
#include<vector>
#include<cstdio>
#include<string.h>
using namespace std;

int N;
int parent[100001][18]; // [x][y] x의 2^y째 부모
int depth[100001]; // 깊이
int max_height; // 트리의 최대깊이
vector<int> adjection[100001]; // 인접 그래프

void FindParentDfs(int par, int now, int dep){ // 부모 자식 관계를 설정해주는 함수
    if(adjection[now].size() == 0)
        return;
    
    parent[now][0] = par; // 부모노드
    depth[now] = dep;

    for(int i = 0; i < adjection[now].size(); i++){
        if(adjection[now][i] != par) // 부모노드가 아닌건 다 자식노드로 추가함
            FindParentDfs(now, adjection[now][i], dep + 1);
    }
}

int FindLCA(int a, int b){
    if(depth[a] != depth[b]){ // 두 노드의 깊이를 맞춰줌
        if(depth[a] < depth[b]) // 다르면 항상 a가 더 깊게하기
            swap(a, b);
    }
                                    // 13은 이진수로 1101 - 0, 2, 3자리수에 1이있음
    int dif = depth[a] - depth[b]; // 깊이 맞추기 parent[x][13] = parent[parent[parent[x][0]][2]][3]
    for(int i = 0;dif > 0;++i){ // 차이가 7(111)이면 1 + 2 + 4 올라가고 8(1000) 이면 0 + 0 + 0 + 8 올라감
        if(dif % 2 == 1) // 이때 단순히 dif 번 조상으로 올라가는 경우, 최악의 경우 
            a = parent[a][i]; // 치우처진 트리의 리프 노드에서 루트 노드까지 올라가야 할 수 있다.
        dif = dif >> 1; // 따라서 -1 말고 /2로
    }

    if(a != b){ // 만약 parent[a][k] == parent[b][k] 이지만, parent[a][k-1] != parent[b][k-1] 이라면
        for(int k = max_height;k >= 0;k--){ // LCA는 2^(k-1)번째 조상에서 ~ 2^k 번째 조상의 사이에 존재한다.
            if(parent[a][k] != 0 && parent[a][k] != parent[b][k]){ // (LCA 이후의 조상들도 모두 공통될 수 밖에 없기 때문)
                a = parent[a][k]; // 13번(1101)째 조상이 LCA일 경우 각 자리수(3,2,0) 마다 실행
                b = parent[b][k]; // k = 3일때 + 8, k = 2 일떄 + 4 해서 12번째 조상에서 반복을 멈춘다  
            } // 맨 마지막 자리수인 + 1 까지 하면 공통 조상이 되버리기 때문에 +1은 추가안됨 그래서
        } // 맨마지막에 + 1 해주기
        a = parent[a][0]; //
    }
    return a;
}

int main(){
    scanf("%d", &N);
    memset(adjection, 0, sizeof(adjection));
    memset(parent, 0, sizeof(parent));

    int a, b;
    for(int i = 0;i < N-1;++i){
        scanf("%d %d", &a, &b);
        adjection[a].push_back(b);
        adjection[b].push_back(a);
    }

    FindParentDfs(0, 1, 0);

    int temp = N, cnt = 0; // log(N) 을 알아내기
    while(temp > 1){
        temp = temp >> 1;
        ++cnt;
    }
    max_height = cnt;

    for(int k = 1;k <= max_height;++k) // 2의 제곱수마다 초기 설정
        for(int idx = 2;idx <= N;++idx)
            if(parent[idx][k-1] != 0)
                parent[idx][k] = parent[parent[idx][k-1]][k-1];

    int M; 
    scanf("%d", &M);
    while(M--){ // M 입력받기
        scanf("%d %d", &a, &b);
        printf("%d\n", FindLCA(a, b));
    }
    return 0;
}