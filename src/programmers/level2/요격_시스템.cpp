#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  // 2번째 열을 기준으로 오름차순 정렬
    });
         
    int answer = 0;
    int end = -1;
    for(auto& a : targets){
        if(end <= a[0]){
            end = a[1];
            answer++;
        }
    }
    return answer;
}