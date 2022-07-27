#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, C, weight[31], ans;
vector<long long> group1;
vector<long long> group2;

// 2^n의 가능한 합의 모든 경우의 수를 따지기
void bruteForce(int start, int end, vector<long long>& v, long long sum){
    if(start > end){
        v.push_back(sum);
        return;
    }
    else{
        bruteForce(start + 1, end, v, sum);
        bruteForce(start + 1, end, v, sum + weight[start]);
    }
}

int main(){
    cin >> N >> C;

    for(int i = 0; i < N; i++)
        cin >> weight[i];

    bruteForce(0, N/2, group1, 0);
    bruteForce(N/2 + 1, N-1, group2, 0);
    sort(group2.begin(), group2.end());

    for(int i = 0; i < group1.size(); i++)
        ans += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();
    cout << ans;  
}