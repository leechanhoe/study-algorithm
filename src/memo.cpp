#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct Grid{
	int x;
	int y;
};

int N;
Grid grid[51];
map<int, int> m;

int getDist(int x1,int y1,int x2,int y2){
	return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}

int main()
{   //프로그램의 시작부 
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> grid[i].x >> grid[i].y;
	}
	
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int dist = getDist(grid[i].x, grid[i].y, grid[j].x, grid[j].y);
			if(m.find(dist) == m.end()){
				m[dist] = 1;
			}
			else{
				m[dist]++;
			}
		}
	}
	
	int ans = 0;
	for(auto a : m){
		if(a.second >= 4){
			ans = max(ans, a.first);
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << (double)ans;
    return 0;
}