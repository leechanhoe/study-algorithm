#include <iostream>
using namespace std;

int N, M, T;
int* disk[52];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void rotate(int x, int d, int k){
    if(d == 1)
        k = M - k;

    for(int i = x; i <= N; i += x){
        int* ndisk = new int[M+2] {0};
        for(int j = 1; j <= M; j++){
            ndisk[(j+k) % M] = disk[i][j];
        }
        ndisk[M] = ndisk[0];
        ndisk[M+1] = ndisk[1];
        disk[i] = ndisk;
    }
}

int dfs(int i, int j, int num){
    int change = 0;
    for(int d = 0; d < 4; d++){
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];
        if(disk[ni][nj] == num){
            disk[i][j] = 0;
            disk[ni][nj] = 0;
            change++;
            change += dfs(ni, nj, num);
        }
    }
    return change;
}

int check(){
    int sum = 0;
    int cnt = 0;
    int change = 0; // 숫자가 1 이상이면 바뀌었다는 뜻

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(disk[i][j] > 0){
                change += dfs(i, j, disk[i][j]);
            }

            if(disk[i][j] > 0){
                sum += disk[i][j];
                cnt++;
            }
        }
    }
    
    if(change > 0)
        return sum;
    
    double mean = (double)sum / cnt;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(disk[i][j] < 1)
                continue;

            if(disk[i][j] > mean){
                disk[i][j]--;
                sum--;
            }
            else if(disk[i][j] < mean){
                disk[i][j]++;
                sum++;
            }
        }
        disk[i][0] = disk[i][M];
        disk[i][M+1] = disk[i][1];
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> T;
    
    disk[0] = new int[M+2] {0};
    for(int i = 1; i <= N; i++){
        disk[i] = new int[M+2];
        for(int j = 1; j <= M; j++){
            cin >> disk[i][j];
        }
        disk[i][0] = disk[i][M];
        disk[i][M+1] = disk[i][1];
    }
    disk[N+1] = new int[M+2] {0};

    int ans;
    while(T--){
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        ans = check();
    }

    cout << ans;
    return 0;
}