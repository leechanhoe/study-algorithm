#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int move = n - 1;
    for(int i = 0; i < n; i++){
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        int next = i + 1;
        while(next < n && name[next] == 'A')
            next++;

        move = min(move, min(i, n - next) + i + n - next);
    }

    answer += move;
    return answer;
}