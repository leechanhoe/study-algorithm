#include <iostream>
using namespace std;

string A, B, op;

int main(){
    cin >> A >> op >> B;

    int lenA = A.size();
    int lenB = B.size();
    if(op == "+"){
        if(lenA == lenB){
            A[0] = '2';
            cout << A;
        }
        else if(lenA > lenB){
            A[lenA-lenB] = '1';
            cout << A;
        }
        else{
            B[lenB-lenA] = '1';
            cout << B;
        }
    }
    else{
        cout << '1';
        for(int i = 1; i < lenA + lenB - 1; i++)
            cout << '0';
    }
    return 0;
}