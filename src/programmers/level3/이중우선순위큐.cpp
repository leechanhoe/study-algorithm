#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(auto& op : operations){
        if(op[0] == 'I'){
            int x = stoi(op.substr(2));
            ms.insert(x);
        }
        else if (op == "D 1") {
            if(!ms.empty()){
                ms.erase(--ms.end());
            }
        }
        else if (op == "D -1") {
            if(!ms.empty()){
                ms.erase(ms.begin());
            }
        }
    }
    
    if(ms.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }
    return answer;
}