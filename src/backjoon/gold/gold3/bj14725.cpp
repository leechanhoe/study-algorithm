#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node{
    map<string, Node*> child;
    map<string, Node*>::iterator iter;
    void insert(vector<string> v, int idx) {
        if (idx == v.size())
            return;

        string ss = v[idx];
        iter = child.find(ss);

        if(iter != child.end()) // 이미 자식으로 있을 때
            iter->second->insert(v, idx + 1);
        else{
            Node* n = new Node;
            child.insert({ss, n});
            n->insert(v, idx + 1);
        }
    }

    void print(int idx) {
        if (child.empty())
            return;
        
        for (auto i = child.begin(); i != child.end(); i++){
            for (int j = 0; j < idx; j++)
                cout << "--";
            cout << i->first << '\n';
            i->second->print(idx + 1);
        }
    }
};

Node tmp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, val;
    Node* root = new Node;
    string ss;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> val;
        vector<string> v;
        for (int j = 0; j < val; j++) {
			cin >> ss;
			v.push_back(ss);
		}
		root->insert(v, 0);
    }
    root->print(0);
}