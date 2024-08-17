#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    vector<int> cnt_le(10001, 0);
    vector<int> cnt_ri(10001, 0);
    int le = 0, ri = 0;
    for(int t : topping){
        if(cnt_ri[t] == 0)
            ri++;
        
        cnt_ri[t]++;
    }
    
    for(int t : topping){
        if(cnt_le[t] == 0)
            le++;
        cnt_le[t]++;
        
        cnt_ri[t]--;
        if(cnt_ri[t] == 0)
            ri--;
        
        if(le == ri)
            answer++;
    }
    return answer;
}