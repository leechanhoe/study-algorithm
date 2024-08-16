#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while(left <= right){
        int share = left / n + 1;
        int remind = left % n + 1;
        if(remind <= share){
            answer.push_back(share);
        }
        else{
            answer.push_back(remind);
        }
        left++;
    }
    return answer;
}
