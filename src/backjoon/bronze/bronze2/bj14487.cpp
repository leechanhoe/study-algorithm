#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;

    int sum = 0;
    for(int i = 0, c; i < N; i++){
        cin >> c;
        sum += c;
        v.push_back(c);
    }

    cout << sum - *max_element(v.begin(), v.end());
}