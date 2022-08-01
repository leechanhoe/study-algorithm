#include <iostream>
#include <string>
using namespace std;

string map[10];
int row[10][10], col[10][10], matrix[10][10];

void dfs(int pos){
    if (pos == 81){
        for (int i = 0; i < 9; i++)
            cout << map[i] << '\n';
        exit(0);
    }

    int y = pos / 9, x = pos % 9;

    if(map[y][x] == '0'){
        for (int i = 1; i <= 9; i++){
            if(!row[y][i] && !col[x][i] && !matrix[(y / 3) * 3 + x / 3][i]){
                row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = true;
                map[y][x] = '0' + i;
                dfs(pos + 1);
                row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = false;
                map[y][x] = '0';
            }
        }
    }
    else
        dfs(pos + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> map[i];
		for(int j = 0; j < 9; ++j){
			if (map[i][j] != '0') {
				row[i][map[i][j] - '0'] = col[j][map[i][j] - '0'] = matrix[(i / 3) * 3 + j / 3][map[i][j] - '0'] = true;
			}
        }
	}
	dfs(0);
	return 0;
}