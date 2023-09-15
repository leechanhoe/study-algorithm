#include <iostream>
using namespace std;

int N;

int main(){
    cin >> N;

    while(N--){
        string num;
        cin >> num;

        if((num[num.size()-1] - '0') % 2)
            cout << "odd\n";
        else
            cout << "even\n";
    }
    return 0;
}