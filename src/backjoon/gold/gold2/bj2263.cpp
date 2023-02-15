#include <iostream>
using namespace std;

int idx[100001];
int in[100001];
int post[100001];
int N;

void getPre(int inStart, int inEnd, int poStart, int poEnd){
    if(inStart > inEnd || poStart > poEnd)
        return;

    int rootIdx = idx[post[poEnd]];
    int left = rootIdx - inStart;
    int right = inEnd - rootIdx;
    cout << in[rootIdx] << ' ';

    getPre(inStart, rootIdx - 1, poStart, poStart + left - 1);
    getPre(rootIdx + 1, inEnd, poStart + left, poEnd - 1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(int i = 1; i <= N; i++){
        cin >> post[i];
    }

    getPre(1, N, 1, N);
    return 0;
}