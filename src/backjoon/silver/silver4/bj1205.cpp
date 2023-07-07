// #include <iostream>
// #include <algorithm>
// using namespace std;

// int N, S, P;
// int score[51];

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

//     cin >> N >> S >> P;
//     if(N == 0){
//         cout << 1;
//         return 0;
//     }

//     int same = 0;
//     int ans = -1;
//     for(int i = 1; i <= N; i++){
//         cin >> score[i];
//         if(N < P){
//             if(score[i] <= S){
//                 cout << i;
//                 return 0;
//             }
//         }
//         else{
//             if(score[i] <= S){
//                 if(score[i] == S)
//                     same++;
//                 else{
//                     ans = i - same;
//                     same = 0;
//                     break;
//                 }
//             }
//         }
//     }
//     if(N < P && ans == -1){
//         cout << N + 1;
//         return 0;
//     }

//     if(same > 0){
//         if(same + N >= P){
//             ans = -1;
//         }
//         else{
//             ans = N - same + 1;
//         }
//     }

//     cout << ans;
// }

#include <iostream>
using namespace std;

int main() {
	int N, score, P;
	int rank[100];

	//입력단
	cin >> N >> score >> P;
	
	for (int i = 0; i < N; i++) {
			cin >> rank[i];
		}

	//계산단
	int cnt = 0;
	int my_rank = 1;
	for (int i = 0; i < N; i++) {
			if (score < rank[i]) my_rank += 1;
			else if (score == rank[i]) my_rank = my_rank;
			else break;
			cnt++;
	}
	
	if (cnt == P) my_rank = -1;
	if (N == 0) my_rank = 1;
	
	cout << my_rank;

	return 0;
}