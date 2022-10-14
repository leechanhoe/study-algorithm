#include <iostream>
using namespace std;
typedef long long ll;
 
ll dp[31][31];
 
int main() {
    for (int h = 0; h <= 30; h++) {
        for (int w = 0; w <= 30; w++) {
            if (h > w) 
                continue;
            if (h == 0) 
                dp[w][h] = 1;
            else 
                dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
        }
    }

    int N;
    while (1) {
        cin >> N;
        if (N == 0)
            break;
        cout << dp[N][N] << "\n";
    }
}
