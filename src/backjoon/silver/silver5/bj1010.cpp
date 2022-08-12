#include <iostream>
using namespace std;
 
int main() {
    int N, M, tc;
    cin >> tc;
    while (tc--){
        cin >> N >> M;
        long long result = 1;
        int r = 1;
        for (int i = M; i > M - N; i--){
            result *= i;
            result /= r++;
        } 
        cout << result << '\n';
    }
}