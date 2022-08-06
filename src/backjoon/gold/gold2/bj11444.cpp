#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<long long>> matrix;
const long long MOD = 1000000007;
long long N;

matrix operator* (matrix& a, matrix& b){
    matrix c(2, vector<long long>(2));
    for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			c[i][j] %= MOD;
        }
    return c;
}

int main() {
    cin >> N;

    matrix ans = {{1, 0}, {0, 1}}; // 단위행렬(I)
    matrix a = {{1, 1}, {1, 0}};
    
    while(N > 0){ // 만약 n이 11이면 이진수로 1011이고 ans엔 1 -> 3 -> 11순으로 담김
        if(N % 2 == 1)
            ans = ans * a;
        a = a * a;
        N /= 2;
    }
    cout << ans[0][1];
}