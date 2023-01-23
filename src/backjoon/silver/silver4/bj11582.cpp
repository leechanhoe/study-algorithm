#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, k;
vector<int> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> k;

    int size = 2;
    int num = N / 2;
    while(size <= N){
        for(int i = 0; i < N; i += size){
            sort(v.begin() + i, v.begin() + i + size);
        }

        if(num == k){
            for(int a : v){
                cout << a << ' ';
            }
            return 0;
        }
        size *= 2;
        num /= 2;
    }
}