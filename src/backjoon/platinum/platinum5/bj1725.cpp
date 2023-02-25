#include <iostream>
#include <algorithm>
using namespace std;

int N, h[100001];

int dnc(int s, int e){
    if(s + 1 == e)
        return h[s];
    if(s + 2 == e)
        return max({min(h[s], h[s+1]) * 2, h[s], h[s+1]});
    
    int mi = (s + e) / 2;
    int le = mi - 2;
    int ri = mi + 1;
    int minHei = min(h[mi-1], h[mi]);
    int maxArea = minHei * 2;

    while(s <= le && ri < e){
        minHei = min(h[le] < h[ri] ? h[ri++] : h[le--], minHei); // 왼쪽과 오른쪽 중 더 높은거 선택
        maxArea = max(minHei * (ri - le - 1), maxArea);
    }

    while(s <= le){
        minHei = min(h[le--], minHei);
        maxArea = max(minHei * (ri - le - 1), maxArea);
    }

    while(ri < e){
        minHei = min(h[ri++], minHei);
        maxArea = max(minHei * (ri - le - 1), maxArea);
    }

    return max(maxArea, max(dnc(s, mi), dnc(mi, e)));
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }

    cout << dnc(0, N);
    return 0;
}