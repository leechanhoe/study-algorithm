#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
int N;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        string fruit;
        int x;
        cin >> fruit >> x;
        if(m.find(fruit) == m.end()){
            m[fruit] = x;
        }
        else{
            m[fruit] += x;
        }
    }

    for(auto fruit : m){
        if(fruit.second == 5){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}