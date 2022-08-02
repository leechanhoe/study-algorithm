#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int N, M;
        cin >> N >> M;
        pair<int, int> student[1000];
        bool chosen[1000] = {false};

        for (int i = 0; i < M; i++){
            int a, b;
            cin >> a >> b;
            student[i] = make_pair(a, b);
        }

        sort(student, student + M, cmp);
        int max_cnt = 0;

        for (int i = 0; i < M; i++){
            for (int j = student[i].first; j <= student[i].second; j++){
                if(!chosen[j]){
                    chosen[j] = true;
                    max_cnt++;
                    break;
                }
            }
        }
        cout << max_cnt << '\n';
    }
}