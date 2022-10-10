#include <iostream>
#include <vector>
using namespace std;

int tree[10001];

void postOrder(int start, int end) {
    if(start >= end){
        return;
    }
    if(start == end - 1){
        cout << tree[start] << '\n';
        return;
    }

    int now = start + 1;
    while(now < end){
        if(tree[start] < tree[now]){
            break;
        }
        now++;
    }

    postOrder(start + 1, now);
    postOrder(now, end);
    cout << tree[start] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int input, size = 0;
    while(cin >> input){
        tree[size++] = input;
    }
    postOrder(0, size);
}