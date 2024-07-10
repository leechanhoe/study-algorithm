// #include <iostream>
// #include <algorithm>
// using namespace std;

// int N, M;
// long long arr[100001];
// long long max_;

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     cin >> N >> M;
//     for(int i = 0; i < N; i++){
//         cin >> arr[i];
//         max_ = max(max_, arr[i]);
//     }

//     long long le = 0, ans = 0;
//     long long ri = max_ * M;
//     while(le <= ri){
//         long long mid = (le + ri) / 2;
//         long long time = 0;
//         for(int i = 0; i < N; i++){
//             time += mid / arr[i];
//         }

//         if(time < M){
//             le = mid + 1;
//             ans = le;
//         }
//         else{
//             ri = mid - 1;
//         }
//     }
//     cout << ans;
// }

#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long T[100001];

bool is_ok(long long t){
    long long sum = 0;
    for(int i = 0; i < N; i++){
        sum += t / T[i];
    }
    return M <= sum;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }

    sort(T, T + N);

    long long le = 1;
    long long ri = M * T[0];
    long long mi, ans;
    while(le <= ri){
        mi = (le + ri) / 2;
        if(is_ok(mi)){
            ri = mi - 1;
            ans = mi;
        }
        else{
            le = mi + 1;
        }
    }

    cout << ans;
    return 0;
}