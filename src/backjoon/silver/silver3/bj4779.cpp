#include <iostream>
#include <cmath>
using namespace std;

int N;
char str[531442];

void solve(int start, int n){
    if(n == 1)
        return;

    int n3 = n / 3;
    for(int i = start + n3; i < start + n3 * 2; i++){
        str[i] = ' ';
    }

    solve(start, n3);
    solve(start + n3 * 2, n3);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(cin >> N){
        int len = pow(3, N);
        for(int i = 0; i < len; i++){
            str[i] = '-';
        }

        solve(0, len);

        for(int i = 0; i < len; i++){
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}

// using namespace std;

// void sol(int n){
//     if(n==0){
//         printf("-");
//         return ;
//     }
    
//     sol(n-1);
    
//     for(int i=0; i<pow(3, n-1); i++)
//         printf(" ");
    
//     sol(n-1);
    
// }

// int main (void){
//     int n;
//     while (scanf("%d", &n) != EOF){
//         sol(n);
//         printf("\n");
//     }
// }