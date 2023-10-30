#include <iostream>
#include <deque>
using namespace std;

int N;
int arr[1000001];
deque<int> dq;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i = N; i > 0; i--){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        int tmp;
        switch(arr[i]){
            case 1:
                dq.push_front(i);
                break;
            case 2:
                tmp = dq.front();
                dq.pop_front();
                dq.push_front(i);
                dq.push_front(tmp);
                break;
            case 3:
                dq.push_back(i);
                break;
        }
    }
    for(int i = 0; i < N; i++){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    return 0;
}