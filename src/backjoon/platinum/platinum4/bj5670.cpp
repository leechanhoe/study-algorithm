#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef pair<int, int> p;

int N, ans;
vector<string> dict;

class Trie {
private:
    Trie* childs[26];
    int childCnt;
    bool isRoot, finish;

public:
    Trie(bool root) {
        for (int i = 0; i < 26; i++) 
            childs[i] = NULL;
        finish = false;
        isRoot = root;
        childCnt = 0;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++){ // 동적할당 해제
            if (childs[i] != NULL)
                delete childs[i];
        }
    }

    void insert(const char* cur) {
        if (*cur == '\0'){ // 널문자(끝)이면 
            finish = true;
            return;
        }
        int pos = *cur - 'a'; // 알파벳 구하기

        if(childs[pos] == NULL) { // 자식중에 없는 알파벳이면
            childs[pos] = new Trie(false);
            childCnt++;
        }
        childs[pos]->insert(cur + 1); // 다음 알파벳 삽입
    }

    void find(const char* cur){
        if(*cur == '\0')
            return;
        int pos = *cur - 'a';
        // root거나 자식의 수가 2이상이거나 다른 문자열의 끝을 지나는 경우
        if(isRoot || childCnt > 1 || finish) 
            ans++;

        childs[pos]->find(cur + 1);
    }
};

void init() {
    string input;
    dict.clear();
    for(int i = 0; i < N; i++){
        cin >> input;
        dict.push_back(input);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    while (cin >> N){
        init();
        Trie root = Trie(true);
        for (int i = 0; i < dict.size(); i++)
            root.insert(dict[i].c_str()); // 문자열의 시작주소 전달

        int total = 0;
        for (int i = 0; i < dict.size(); i++) {
            ans = 0;
            root.find(dict[i].c_str());
            total += ans;
        }

        double result = (double)total / N;
        printf("%.2lf\n", result);
    }
}