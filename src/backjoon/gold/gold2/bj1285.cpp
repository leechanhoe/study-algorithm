#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> board;
int result = 1987654321;

int solve(int row){
    int ret = 0;
    for (int j = 0; j < N; j++){
        int h = 0; // 해당 행의 앞면개수
        int t = 0; // 해당 행의 뒷면개수
     //행과 열중 하나만 다 뒤집어봐도 됨.
        for(int i = 0; i < N; i++){
            //해당 행이 뒤집혀(1)있으면
            if(((row >> i) & 1) == 1){
                if(board[i][j] == 'H')
                    t++;
                else
                    h++;
            }
            else{
                if(board[i][j] == 'H')
                    h++;
                else
                    t++;
            }
        } 
// 뒷면이 더 많으면 해당열을 뒤집고 아니면 냅둠 - 앞뒤상관없이 최솟값만 따지면됨
        ret += min(h, t);
    }
    return ret;
}
int main()
{
	cin.tie(NULL);ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++){
		string str;
		cin >> str;
		board.push_back(str);
	}

	//각 행들의 뒤집힌 경우를 모두 확인
	for (int row = 0; row < (1 << N) - 1; row++)
		result = min(result, solve(row));

	cout << result;
}