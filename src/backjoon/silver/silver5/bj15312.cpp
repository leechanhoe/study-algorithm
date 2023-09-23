#include <iostream>
using namespace std;

string a, b;
int alpha[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int memory[4001];

int main(){
    cin >> a >> b;

    for (int i = 0; i < a.size(); i++)
    {
        memory[i*2] = alpha[a[i] - 'A'];
        memory[i*2+1] = alpha[b[i] - 'A'];
    }

    for(int i = a.size() * 2 - 1; i >= 2; i--){
        for (int j = 0; j < i; j++)
        {
            memory[j] = (memory[j] + memory[j+1]) % 10;
        }
    }

    cout << memory[0] << memory[1];
    return 0;
}