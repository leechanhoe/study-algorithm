#include <iostream>
#include <algorithm>
using namespace std;

int cards[500000];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> cards[i];
    
    sort(cards, cards + N);
    cin >> M;
    int m;
    while(M--){
        cin >> m;
        if (binary_search(cards, cards + N, m))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}