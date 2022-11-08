#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[50][4];

int main(void) {

	string result = "";
    int N, M;
	int ans = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string dna;
		cin >> dna;
		for (int j = 0; j < M; j++) {
			switch (dna[j]) {
                case 'A' :
                    cnt[j][0]++;
                    break;
                case 'C' :
                    cnt[j][1]++;
                    break;
                case 'G' :
                    cnt[j][2]++;
                    break;
                case 'T':
                    cnt[j][3]++;
                    break;
		
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int max = 0;
		int idx = 0;
		for (int j = 0; j < 4; j++) {
			if (cnt[i][j] > max) {
				max = cnt[i][j];
				idx = j;
			}
		}
		ans += N - max;
		switch (idx){
            case 0:
                result += 'A';
                break;
            case 1:
                result += 'C';
                break;
            case 2:
                result += 'G';
                break;
            case 3:
                result += 'T';
                break;
		}
	}
	cout << result << "\n" << ans << "\n";
	return 0;
}