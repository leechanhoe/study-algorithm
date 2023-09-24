#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N1, N2, T;
string a, b;
vector<pair<char, bool>> order;

int main(){
    cin >> N1 >> N2 >> a >> b >> T;

    for(int i = a.size() - 1; i >= 0; i--){
        order.push_back({a[i], true});
    }

    for(int i = 0; i < b.size(); i++){
        order.push_back({b[i], false});
    }

    while(T--){
        for(int i = 0; i < order.size() - 1; i++){
            if(order[i].second && !order[i+1].second){
                swap(order[i], order[i+1]);
                i++;
            }
        }
    }

    for(auto ant : order){
        cout << ant.first;
    }
    return 0;
}