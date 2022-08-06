#include <iostream>
using namespace std;

int parent[201];
int city[201][201];
int N, M;

int find(int x){
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unio(int a, int b){
    a = find(a);
    b = find(b);
    
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i <= 200; i++)
        parent[i] = i;

    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> city[i][j];
            if (city[i][j])
                unio(i, j);
        }
    }

    int a, b;
    cin >> b;
    b = find(b);
    bool flag = false;
    for (int i = 0; i < M-1; i++){
        cin >> a;
        if(find(a) != b){
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "NO";
    else
        cout << "YES";
}