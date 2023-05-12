#include <iostream>
#include <set>
using namespace std;

set<int> s;
int nA, nB, a, b, ans;

int main(){
    cin >> nA >> nB;

    for(int i = 0; i < nA; i++){
        cin >> a;
        s.insert(a);
    }

    for(int i = 0; i < nB; i++){
        cin >> b;

        if(s.find(b) != s.end()){
            s.erase(b);
        } 
    }

    cout << s.size() << '\n';
    for(int i : s)
        cout << i << ' ';
    return 0;
}