#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        if(6 <= str.size() && str.size() <= 9){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}