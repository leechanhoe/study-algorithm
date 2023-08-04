// #include <iostream>
// #include <numeric>
// using namespace std;

// int N, S, R;
// bool broken[12];
// bool spare[12];

// int main(){
//     cin >> N >> S >> R;
//     for(int i = 0; i < S; i++){
//         int s;
//         cin >> s;
//         broken[s] = true;
//     }
//     for(int i = 0; i < R; i++){
//         int r;
//         cin >> r;
//         spare[r] = true;
//     }

//     for(int i = 1; i <= N; i++){
//         if(!spare[i])
//             continue;

//         if(broken[i])
//             broken[i] = false;
//         else{
//             if(broken[i-1])
//                 broken[i-1] = false;
//             else if(broken[i+1])
//                 broken[i+1] = false;
//         }
//     }
//     cout << accumulate(broken, broken + N + 1, 0);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n, s, r, kayak[12], ans;

int main(){
  cin >> n >> s >> r;

  for(int i = 1; i <= n; i++) {
    kayak[i] = 1;
  }

  for(int i = 0, teamNum; i < s; i++) {
    cin >> teamNum;
    kayak[teamNum]--;
  }

  for(int i = 0, teamNum; i < r; i++) {
    cin >> teamNum;
    kayak[teamNum]++;
  }

  for(int i = 1; i <= n; i++) {
    if(kayak[i] == 2){
      if(!kayak[i-1]) {
        kayak[i] = kayak[i-1] = 1;
        continue;
      }
    }
    if(kayak[i] == 2){
      if(!kayak[i+1]) {
        kayak[i] = kayak[i+1] = 1;
        continue;
      }
    }
  }

  for(int i = 1; i <= n; i++)
    if(!kayak[i])
      ans++;

  cout << ans;
}