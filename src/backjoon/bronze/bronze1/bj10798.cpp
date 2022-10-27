#include <iostream>
using namespace std;

char ch[5][16];

int main(){
    for(int i = 0; i < 5; i++)
        cin >> ch[i];
  
    for(int k = 0; k < 15; k++)
    {
        for(int i = 0; i < 5; i++)
        {
            if(ch[i][k] != '\0')
                cout << ch[i][k];
        }
    }
}