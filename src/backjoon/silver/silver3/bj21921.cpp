#include <iostream>
#include <numeric>
using namespace std;

int X, N;
int visit[250001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> X;
    for(int i = 0; i < N; i++)
        cin >> visit[i];
    
    int cnt = 1;
    int sum = accumulate(visit, visit + X, 0);
    int ma = sum;
    for(int i = 0; i < N - X; i++){
        sum -= visit[i];
        sum += visit[i+X];
        if(ma == sum)
            cnt++;
        else if(ma < sum){
            ma = sum;
            cnt = 1;
        }
    }
    if(ma == 0)
        cout << "SAD";
    else
        cout << ma << '\n' << cnt;
    return 0;
}