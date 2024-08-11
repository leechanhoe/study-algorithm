#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> m = {
        {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}
    };
    
    for(int i = 0; i < survey.size(); i++){
        char disagree = survey[i][0];
        char agree = survey[i][1];
        int score = choices[i] - 4;  // -3 ~ +3 사이의 값으로 변환
        
        if (score < 0) {  // 비동의
            m[disagree] += -score;
        } else if (score > 0) {  // 동의
            m[agree] += score;
        }
    }
    
    string answer = "";
    answer += (m['R'] >= m['T']) ? 'R' : 'T';
    answer += (m['C'] >= m['F']) ? 'C' : 'F';
    answer += (m['J'] >= m['M']) ? 'J' : 'M';
    answer += (m['A'] >= m['N']) ? 'A' : 'N';
    
    return answer;
}
