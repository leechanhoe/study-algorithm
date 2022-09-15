#include <iostream>
#include <vector>
using namespace std;

int dp[100001][5][5];
vector<int> v;

int move(int from, int to){
    if(from == to) 
        return 1;

    switch(from){
        case 0: 
            return 2;
        case 1:
            return to == 3 ? 4 : 3;
        case 2: 
            return to == 4 ? 4 : 3;
        case 3: 
            return to == 1 ? 4 : 3;
        case 4: 
            return to == 2 ? 4 : 3;
    }
}

int sol(int le, int ri, int n){
    if(n == v.size())
        return 0;
    if(dp[n][le][ri])
        return dp[n][le][ri];
    return dp[n][le][ri] = min(move(le, v[n]) + sol(v[n], ri, n + 1), move(ri, v[n]) + sol(le, v[n], n + 1));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int input;
    while(1){
        cin >> input;
        if(!input)
            break;
        v.push_back(input);
    }

    cout << sol(0, 0, 0);
}