#include <iostream>
#include <map>
using namespace std;

int N;
string num[1001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    int k = 1;
    while(k <= num[0].size()){
        map<string, int> m;
        for (int i = 0; i < N; i++)
        {
            string s = num[i].substr(num[i].size() - k, k);
            if(m.find(s) != m.end()){
                break;
            }
            m[s] = 1;
        }

        if(m.size() == N){
            cout << k;
            return 0;
        }
        k++;
    }
}