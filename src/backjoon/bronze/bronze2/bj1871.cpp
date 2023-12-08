#include <iostream>
#include <string>
using namespace std;

string num;
int N;

int main(){
    cin >> N;
    while(N--){
        cin >> num;

        int sum = 0;
        int tmp = 26 * 26;
        for(int i = 0; i < 3; i++){
            sum += (num[i] - 'A') * tmp;
            tmp /= 26;  
        }

        if (abs(sum - stoi(num.substr(4, 4))) <= 100)
            cout << "nice\n";
        else
            cout << "not nice\n";
    }
    return 0;
}