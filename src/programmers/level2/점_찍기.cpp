#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long limit = (long)d * (long)d;
    for(long long i = 0; i <= d; i += k){
        answer += floor(sqrt(limit - i * i) / k) + 1;
    }
    return answer;
}