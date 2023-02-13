#include <iostream>
#include <vector>
#include <set>
using namespace std;

int board[33] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
                20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
                40, 13, 16, 19, 22, 24, 28, 27, 26, 25,
                30, 35, 0};
int piece[4];
int dice[10];

bool mv(int pi, int di){

    int next = piece[pi];
    for(int i = 0; i < di && next < 32; i++){
        switch (next)
        {
            case 5:
                if(i == 0)
                    next = 21;
                else
                    next++;
                break;
            case 10:
                if(i == 0)
                    next = 24;
                else
                    next++;
                break;    
            case 15:
                if(i == 0)
                    next = 26;
                else
                    next++;
                break;
        case 20:
            piece[pi] = 32;
            return true;
        case 23:
        case 25:
        case 28:
            next = 29;
            break;
        case 31:
            next = 20;
            break;
        default:
            next++;
            break;
        }
    }
    for(int i = 0; i < 4; i++){
        if(piece[i] == next)
            return false;
    }
    piece[pi] = next;
    return true;
}

int dfs(int idx){
    if(idx == 10)
        return 0;

    set<int> init;
    init.insert(32);
    int maxScore = 0;

    for(int i = 0; i < 4; i++){
        int start = piece[i];
        if(init.find(start) == init.end()){
            init.insert(start);

            if(!mv(i, dice[idx]))
                continue;
            
            maxScore = max(maxScore, board[piece[i]] + dfs(idx + 1));
            piece[i] = start;
        }
    }
    return maxScore;
}

int main(){
    for(int i = 0; i < 10; i++){
        cin >> dice[i];
    }
    cout << dfs(0);
    return 0;
}