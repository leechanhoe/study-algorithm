#include <iostream>
#include <algorithm>
using namespace std;

int burger[3];
int drink[2];

int main(){
    cin >> burger[0] >> burger[1] >> burger[2] >> drink[0] >> drink[1];
    
    cout << *min_element(burger, burger + 3) + *min_element(drink, drink + 2) - 50;
    return 0;
}