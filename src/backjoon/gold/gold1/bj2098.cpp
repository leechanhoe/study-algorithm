#include <iostream>
#include <cstring>
#include <bitset>
#define MAX 16
#define INF 987654321
using namespace std;

int N, ansBit;
int map[MAX][MAX];
int cost[MAX][1 << MAX];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    }
    ansBit = (1 << N) - 1;
}

int dfs(int curNode, int curBit){
    if(curBit == ansBit){
        if(map[curNode][0] == 0)
            return INF;
        else
            return map[curNode][0];
    }

    if(cost[curNode][curBit] != -1)
        return cost[curNode][curBit];
        
    cost[curNode][curBit] = INF;
    for(int i = 0; i < N; i++){    // 바로 아래 코드는 이미 간 노드는 패스한다는 의미
        if(map[curNode][i] == 0 || (curBit & (1 << i)) == (1 << i))
            continue;
        cout << curNode << " " << i << " " << bitset<4>(curBit) << '\n'; // 
        cost[curNode][curBit] = min(cost[curNode][curBit], map[curNode][i] + dfs(i, curBit | 1 << i));
    } // cost[i][j] = 현재 노드가 i고, 방문하지 않은 노드를 이진수 0으로 표현한게 j인데,
    return cost[curNode][curBit]; // 이제부터 방문해야할 0인 노드들(출발점 포함)을 방문거리의 최소비용
} // dfs로 정답부터 거꾸로 dp를 채워간다.. 이해하느라 시간이 좀 걸렸다.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    memset(cost, -1, sizeof(cost));
    cout << dfs(0, 1);
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 16; j++){
            cout << i << " - " << bitset<4>(j) << " = "<< cost[i][j] << " ";
        }
        cout << '\n';
    }
}