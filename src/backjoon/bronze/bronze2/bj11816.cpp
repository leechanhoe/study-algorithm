#include <iostream>
using namespace std;

string num;
int ans;

int main(){
    cin >> num;

    if(num[0] == '0'){
        if(1 < num.size() && num[1] == 'x'){
            int tmp = 1;
            for(int i = num.size() - 1; i >= 2; i--){
                if (num[i] <= '9')
                    ans += (num[i] - '0') * tmp;
                else
                    ans += (num[i] - 'a' + 10) * tmp;
                tmp *= 16;
            }
        }
        else{
            int tmp = 1;
            for(int i = num.size() - 1; i >= 1; i--){
                ans += (num[i] - '0') * tmp;
                tmp *= 8;
            }
        }
        cout << ans;
    }
    else{
        cout << num;
    }
    return 0;
}