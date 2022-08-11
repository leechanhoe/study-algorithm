#include<iostream>
#include<algorithm>
using namespace std;
 
int n, m, pos[51], answer;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;++i)
        cin >> pos[i];
        
    sort(pos, pos+n+1);
    int pivot = lower_bound(pos, pos + n + 1, 0) - pos;
 
    for(int i=0; i < pivot; i += m)
        answer += abs(pos[i] * 2);
    
    for(int i=n; i > pivot; i -= m)
        answer += pos[i] * 2;
    
    answer -= max(abs(pos[0]), abs(pos[n]));
    
    cout << answer;
}