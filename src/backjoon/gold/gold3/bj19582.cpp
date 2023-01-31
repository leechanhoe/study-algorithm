#include <iostream>
using namespace std;

// long long dp[100001][2];
// long long inpu[100001][2];
// int N;
// int zzz;

// int main(){
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     cin >> N;
//     for(int i = 0; i < N; i++){
//         cin >> inpu[i][0] >> inpu[i][1];
//     }

//     dp[0][0] = inpu[0][1];
//     for(int i = 1; i < N; i++){
//         if(zzz > 0 && dp[i-1][1] > inpu[i][0]){
//             cout << "Zzz";
//             return 0;
//         }
//         if(dp[i-1][0] > inpu[i][0]){
//             zzz++;
//         }
    
//         dp[i][0] = dp[i-1][0] + inpu[i][1];
//         dp[i][1] = min(dp[i-1][0], dp[i-1][1] + inpu[i][1]);
//         // cout << dp[i][1] << '\n';
//     }

//     cout << "Kkeo-eok";
//     return 0;
// }

int N, x, p, maxp, jump;
long long sum;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> p;
        if(sum <= x){
            sum += p;
            maxp = max(p, maxp);
        }
        else if(sum - maxp > x || maxp < p){
            jump++;
        }
        else{
            jump++;
            sum -= maxp;
            sum += p;
        }
        if(jump > 1){
            cout << "Zzz";
            return 0;
        }
    }
    cout << "Kkeo-eok";
    return 0;
}