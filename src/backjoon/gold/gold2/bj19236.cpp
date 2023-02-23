// #include <iostream>
// using namespace std;

// struct Fish{
//     int id;
//     int r;
//     int c;
//     int d;
//     bool alive;
// };

// Fish* board[4][4];
// int dir[9][2] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
// Fish* fish[17];
// Fish* shark;

// bool canMove(Fish* f){
//     int r = f->r;
//     int c = f->c;
//     int nr = r + dir[f->d][0];
//     int nc = c + dir[f->d][1];
//     if(0 <= nr && nr < 4 && 0 <= nc && nc < 4 && board[nr][nc] != shark){
//         Fish* tmp = board[r][c]; // swap
//         board[r][c] = board[nr][nc];
//         board[nr][nc] = tmp;

//         board[r][c]->r = r;
//         board[r][c]->c = c;
//         board[nr][nc]->r = nr;
//         board[nr][nc]->c = nc;
//         return true;
//     }
//     return false;
// }

// void fishMove(){
//     for(int i = 1; i <= 16; i++){
//         if(fish[i]->alive){
//             for(int j = 0; j <= 8; j++){
//                 if(canMove(fish[i]))
//                     break;
//                 fish[i]->d = fish[i]->d == 8 ? 1 : fish[i]->d + 1;
//             }
//         }
//     }
// }

// void copyState(){

//     for(int i = 1; i <= 16; i++){
//         nFish[i] = fish[i];
//     }
// }

// int sharkMoveDfs(){

//     int maxRes = 0;
//     int r = shark->r;
//     int c = shark->c;
    
//     for(int i = 1; i <= 3; i++){
//         int nr = r + dir[shark->d][0] * i;
//         int nc = c + dir[shark->d][1] * i;

//         if(0 <= nr && nr < 4 && 0 <= nc && nc < 4)
//             break;

//         if(board[nr][nc]->alive){
//             Fish* hunted = board[nr][nc];
//             hunted->alive = false;
//             hunted->r = r;
//             hunted->c = c;

//             board[nr][nc] = shark;
//             shark->r = nr;
//             shark->c = nc;

//             maxRes = max(maxRes, board[nr][nc]->id + sharkMoveDfs());

//             hunted->alive = true;
//             hunted->r = nr;
//             hunted->c = nc;

//             board[nr][nc] = shark;
//             shark->r = r;
//             shark->c = c;
//         }
//     }
//     return maxRes;
// }

// int main(){
//     for(int i = 0; i < 4; i++){
//         for(int j = 0; j < 4; j++){
//             int a, b;
//             cin >> a >> b;

//             fish[a] = new Fish;
//             board[i][j] = fish[a];
//             fish[a]->id = a;
//             fish[a]->r = i;
//             fish[a]->c = j;
//             fish[a]->d = b;
//             fish[a]->alive = true;
//         }
//     }

//     shark = new Fish;
//     shark->r = 0;
//     shark->c = 0;
//     shark->id = 17;
//     shark->d = board[0][0]->d;
//     shark->alive = false; // 물고기 이동시 같이 이동하지 않게

//     board[0][0]->alive = false;
//     board[0][0] = shark;

//     fishMove();

//     for(int i = 0; i < 4; i++){
//         for(int j = 0; j < 4; j++){
//             cout << board[i][j]->id << ' ' << board[i][j]->d << " | ";
//         }
//         cout << '\n';
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <queue>
 
#define endl "\n"
#define MAX 4
using namespace std;
 
struct FISH
{
    int x;
    int y;
    int Dir;
    bool Live;
};
 
int Answer;
int MAP[MAX][MAX];
FISH Fish[20];
 
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b; cin >> a >> b;
            MAP[i][j] = a;
            Fish[a] = { i, j, b, true };
        }
    }
} 
 
void Copy_State(int A[][4], int B[][4], FISH C[], FISH D[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            A[i][j] = B[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) C[i] = D[i];
}
 
void Swap_Fish(int Idx, int IIdx)
{
    /* 물고기들 끼리 자리를 바꾸는 경우 물고기들의 좌표를 바꿔주는 함수. */
    FISH Temp = Fish[Idx];
    Fish[Idx].x = Fish[IIdx].x;
    Fish[Idx].y = Fish[IIdx].y;
    Fish[IIdx].x = Temp.x;
    Fish[IIdx].y = Temp.y;
}
 
void Move_Fish()
{
    /* 물고기의 움직임을 나타내는 함수. */
    for (int i = 1; i <= 16; i++)
    {
        if (Fish[i].Live == false) continue;
 
        int x = Fish[i].x;
        int y = Fish[i].y;
        int Dir = Fish[i].Dir;
        
        int nx = x + dx[Dir];
        int ny = y + dy[Dir];
        bool Flag = false;
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
        {
            if (MAP[nx][ny] == 0)
            {
                Flag = true;
                Fish[i].x = nx;
                Fish[i].y = ny;
                MAP[nx][ny] = i;
                MAP[x][y] = 0;
            }
            else if(MAP[nx][ny] != -1)
            {
                Flag = true;
                Swap_Fish(i, MAP[nx][ny]);
                swap(MAP[x][y], MAP[nx][ny]);
            }
        }
 
        /* 여기까지 왔는데 Flag = false 라는 것은,
         * 물고기가 현재 진행방향으로는 움직일 수 없다는 것을 의미. */
        /* 다른 7방향을 탐색해본다. */
        if (Flag == false)
        {
            int nDir = Dir + 1;
            if (nDir == 9) nDir = 1;
            int nx = x + dx[nDir];
            int ny = y + dy[nDir];
 
            while (nDir != Dir)
            {
                if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
                {
                    if (MAP[nx][ny] == 0)
                    {
                        Fish[i].x = nx;
                        Fish[i].y = ny;
                        MAP[nx][ny] = i;
                        MAP[x][y] = 0;
                        Fish[i].Dir = nDir;
                        break;
                    }
                    else if (MAP[nx][ny] != -1)
                    {
                        Swap_Fish(i, MAP[nx][ny]);
                        swap(MAP[x][y], MAP[nx][ny]);
                        Fish[i].Dir = nDir;
                        break;
                    }
                }
                nDir++;
                if (nDir == 9) nDir = 1;
                nx = x + dx[nDir];
                ny = y + dy[nDir];
            }
        }
    }
}
 
void Make_State(int x, int y, int nx, int ny, int Fish_Num, bool T)
{
    /* 상태를 바꾸거나 되돌리는 과정을 표현한 함수. */
    if (T == true)
    {
        MAP[x][y] = 0;
        MAP[nx][ny] = -1;
        Fish[Fish_Num].Live = false;
    }
    else
    {
        MAP[x][y] = -1;
        MAP[nx][ny] = Fish_Num;
        Fish[Fish_Num].Live = true;
    }
}
 
void DFS(int x, int y, int Dir, int Sum)
{
    /* 물고기의 움직임 + 상어의 움직임을 나타내는 DFS 함수. */
 
    Answer = Max(Answer, Sum);
    /* 현재 상태를 임시 변수를 선언해서 저장해 주기. */
    int C_MAP[4][4];
    FISH C_Fish[20];
    Copy_State(C_MAP, MAP, C_Fish, Fish);
    /*=========================================*/
    /* 물고기를 움직여주기 + 상어를 움직여주기 */
    Move_Fish();
 
    for (int i = 1; i <= 3; i++)
    {
        int nx = x + dx[Dir] * i;
        int ny = y + dy[Dir] * i;
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
        {
            if (MAP[nx][ny] == 0) continue;
            
            int Fish_Num = MAP[nx][ny];
            int nDir = Fish[Fish_Num].Dir;
 
            Make_State(x, y, nx, ny, Fish_Num, true);
            DFS(nx, ny, nDir, Sum + Fish_Num);
            Make_State(x, y, nx, ny, Fish_Num, false);
        }
        else break;
    }
    /*==========================================*/
    Copy_State(MAP, C_MAP, Fish, C_Fish);
    /* 최종적으로 다시 원래의 상태로 되돌려 놓기. */
}
 
void Solution()
{
    /* 초기 세팅. 상어가 (0, 0)에 있는 물고기를 잡아먹는다. */
    int F_Num = MAP[0][0];
    int Dir = Fish[F_Num].Dir;
    Fish[F_Num].Live = false;
    MAP[0][0] = -1;
    /*================================================*/
    DFS(0, 0, Dir, F_Num);
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Solve();
 
    return 0;
}