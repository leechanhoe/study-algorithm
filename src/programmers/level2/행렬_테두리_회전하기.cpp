#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns));
    vector<vector<int>> tmp(rows, vector<int>(columns));
    int id = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            board[i][j] = id++;
            tmp[i][j] = board[i][j];
        }
    }
    for(auto& q : queries){
        int x1 = q[0] - 1; int y1 = q[1] - 1;
        int x2 = q[2] - 1; int y2 = q[3] - 1;
        int mi = board[x1][y1];
        
        for(int y = y1; y < y2; y++){
            tmp[x1][y+1] = board[x1][y];
        }
        
        for(int x = x1; x < x2; x++){
            tmp[x+1][y2] = board[x][y2];
        }
        
        for(int y = y2; y > y1; y--){
            tmp[x2][y-1] = board[x2][y];
        }
        
        for(int x = x2; x > x1; x--){
            tmp[x-1][y1] = board[x][y1];
        }
        
        for(int y = y1; y < y2; y++){
            board[x1][y] = tmp[x1][y];
            mi = min(mi, board[x1][y]);
        }
        
        for(int x = x1; x < x2; x++){
            board[x][y2] = tmp[x][y2];
             mi = min(mi, board[x][y2]);
        }
        
        for(int y = y2; y > y1; y--){
            board[x2][y] = tmp[x2][y];
             mi = min(mi, board[x2][y]);
        }
        
        for(int x = x2; x > x1; x--){
            board[x][y1] = tmp[x][y1];
             mi = min(mi, board[x][y1]);
        }
        
        answer.push_back(mi);
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < columns; j++){
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    
    return answer;
}