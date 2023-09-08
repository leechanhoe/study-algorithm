#include <iostream>
using namespace std;

string a, b;
int ans[10010];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;

    bool end = false;
    if(a.size() < b.size())
        swap(a, b);

    int j = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        if(j < b.size()){
            ans[i] += (a[i] - '0') + (b[b.size()-j-1] - '0');
        }
        else{
            ans[i] += (a[i] - '0');
        }

        if(10 <= ans[i]){
            ans[i] %= 10;
            if(i == 0){
                end = true;
                break;
            }
            ans[i-1] += 1;
        }
        j++;
    }
    
    if(end)
        cout << 1;
    for(int i = 0; i < a.size(); i++){
        cout << ans[i];
    }
    return 0;
}