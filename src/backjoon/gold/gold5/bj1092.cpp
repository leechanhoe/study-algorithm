#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> crane;
vector<int> boxes;
int N, M, ans, c, b;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c;
        crane.push_back(c);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> b;
        boxes.push_back(b);
    }
    sort(boxes.begin(), boxes.end(), greater<int>());
    if(boxes[0] > *max_element(crane.begin(), crane.end())){
        cout << -1;
        return 0;
    }
    while(!boxes.empty()){
        ans++;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < boxes.size(); j++){
                if(crane[i] >= boxes[j]){
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
    }
    cout << ans;
}