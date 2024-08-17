#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int n = weights.size();
    vector<int> cnt(1001, 0);
    unordered_map<int, int> m;
    for(auto& w : weights){
        cnt[w]++;
        for(int i = 2; i <= 4; i++){
            int x = w * i;
            if(!m.count(x)){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }
    }
    
    for(auto& w : weights){
        for(int i = 2; i <= 4; i++){
            int x = w * i;
            m[x]--;
            answer += m[x];
        }
        cnt[w]--;
        answer -= cnt[w] * 2;
    }
    return answer;
}