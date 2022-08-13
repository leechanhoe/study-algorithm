#include <iostream>
#include <vector>
#include <string>
#define MAX 360000
using namespace std;

vector<int> getPi(vector<bool> p) {
    vector<int> pi(p.size(), 0);
    int j = 0;
    for (int i = 1; i < p.size(); i++){
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

void kmp(vector<bool> t, vector<bool> p){
    vector<int> pi = getPi(p);
    int j = 0;
    for(int i = 0; i < t.size(); i++){
        while (j > 0 && t[i] != p[j])
            j = pi[j-1];
        if(t[i] == p[j]){
            if(j == p.size() - 1){
                cout << "possible";
                return;
            }
            else
                j++;
        }
    }
    cout << "impossible";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, input;
    vector<bool> tclock(MAX * 2, 0);
    vector<bool> pclock(MAX, 0);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> input;
        tclock[input] = tclock[MAX + input] = 1;
    }
    for (int i = 0; i < N; i++){
        cin >> input;
        pclock[input] = 1;
    }
    kmp(tclock, pclock);
}