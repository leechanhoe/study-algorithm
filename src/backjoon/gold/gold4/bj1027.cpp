#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int b[51];
int see[51];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }

    for(int i = 0; i < N; i++){
        double maxGra = -1987654321;
        for(int j = i + 1; j < N; j++){
            int h = b[j] - b[i];
            int w = j - i;
            double gra = h / (double)w;

            if(maxGra < gra){
                maxGra = gra;
                see[i]++;
                see[j]++;
            }
        }
    }

    cout << *max_element(see, see + N);
    return 0;

}