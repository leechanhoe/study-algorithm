#include <iostream>
using namespace std;

int N, K, zero, ans;
pair<int, bool> belt[202]; // 내구도, 로봇유무

void rotate(){
    for(int i = 2*N; i > 0; i--){
        belt[i+1] = belt[i];
    }
    belt[1] = belt[2*N+1];

    belt[N].second = false;
}

void robot_move(){
    for(int i = N-1; i > 0; i--){
        if(belt[i].second){
            if(!belt[i+1].second && belt[i+1].first > 0){
                belt[i+1].first--;
                if(belt[i+1].first == 0)
                    zero++;

                belt[i+1].second = true;
                belt[i].second = false;
            }
        }
    }
    belt[N].second = false;
}

void put_robot(){
    if(belt[1].first > 0){
        belt[1].first--;
        if(belt[1].first == 0)
            zero++;

        belt[1].second = true;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= 2*N; i++){
        cin >> belt[i].first;
    }

    while(1){
        ans++;
        rotate();
        robot_move();
        put_robot();

        if(zero >= K){
            break;
        }
    }

    cout << ans;
    return 0;
}