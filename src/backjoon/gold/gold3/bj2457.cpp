#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

typedef struct {
    int s, e;
}flower;

int getDay(int m, int d){
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return accumulate(day, day + m, 0) + d;
}

bool cmp1(flower f1, flower f2){
    if(f1.s == f2.s)
        return f1.e < f2.e;   
    return f1.s < f2.s; 
}

bool cmp2(flower f1, flower f2){
    return f1.e > f2.e;
}

flower flowers[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        flowers[i] = {getDay(s1, s2), getDay(e1, e2)};
    }

    sort(flowers, flowers + N, cmp2);
    if(getDay(12, 1) > flowers[0].e) {
        cout << 0 << "\n"; 
        return 0;
    }

    sort(flowers, flowers + N, cmp1);
    if(getDay(3, 1) < flowers[0].s) {
        cout << 0 << "\n"; 
        return 0;
    }

    int idx = 0;
    for (int i = 0; i < N; i++){
        if (flowers[i].s <= getDay(3, 1)){
            if(flowers[i].e > flowers[idx].e)
                idx = i;
        }
        else
            break;
    }

    flower cur = flowers[idx];
    flower next = flowers[idx];
    int ans = 1;
    if (cur.e >= getDay(12, 1)){
        cout << ans;
        return 0;
    }

    for (int i = idx + 1; i < N; i++){
        if (flowers[i].s <= cur.e){
            if(flowers[i].e > next.e){
                next = flowers[i];
                if(next.e >= getDay(12, 1)){
                    ans++;
                    break;
                }
            }
        }
        else{
            if(next.e < flowers[i].s){
                cout << 0 << "\n"; 
                return 0;
            }
            i--;
            cur = next;
            ans++;
        }
    }
    cout << ans;
}