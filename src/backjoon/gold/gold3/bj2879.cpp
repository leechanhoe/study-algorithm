#include <iostream>
using namespace std;

int N;
int line[1001];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> line[i];
    }

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        line[i] -= a;
    }

    bool flag = false;
    int ans = 0;
    while(!flag){
        flag = true;
        for(int i = 0; i < N; i++){
            if(line[i] == 0)
                continue;
            int sign = line[i];
            flag = false;
            for(int j = i + 1; j <= N; j++){
                if(line[i] * line[j] > 0){
                    if(abs(line[j]) < abs(sign))
                        sign = line[j];
                }
                else{
                    ans += abs(sign);
                    for(int k = i; k < j; k++)
                        line[k] -= sign;
                    i = j - 1;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}