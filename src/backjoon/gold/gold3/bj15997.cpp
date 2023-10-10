#include <bits/stdc++.h>
using namespace std;

map<string, int> country;
double ans[4];
double game[4][4][3];
pair<int, int> score[4];

void game_result(int result, int a, int b){
    switch(result){
        case 0:
            score[a].first += 3;
            break;
        case 1:
            score[a].first += 1;
            score[b].first += 1;
            break;
        case 2:
            score[b].first += 3;
            break;
    }
}

void revert_game_result(int result, int a, int b)
{
    switch (result)
    {
    case 0:
            score[a].first -= 3;
            break;
    case 1:
            score[a].first -= 1;
            score[b].first -= 1;
            break;
    case 2:
            score[b].first -= 3;
            break;
    }
}

void ranking(double game_result_pro){
    pair<int, int> copyed_score[4];
    for(int i = 0; i < 4; i++){
        copyed_score[i] = score[i];
    }
    sort(copyed_score, copyed_score + 4, greater<pair<int, int>>());

    double duple = 1;
    vector<double> next_pro;
    for(int i = 1; i < 4; i++){
        if (copyed_score[i-1].first == copyed_score[i].first){
            duple++;
        }
        else{
            int pass = next_pro.size();
            for(int j = 0; j < duple; j++){
                if(duple <= 2 - pass)
                    next_pro.push_back(1);
                else
                    next_pro.push_back(1/duple * (2 - pass));
            }
            duple = 1;
            if(2 <= i)
                break;
        }
    }

    int pass = next_pro.size();
    while(next_pro.size() < 4)
        if(duple == 1)
            next_pro.push_back(0);
        else
            next_pro.push_back(1 / duple * (2 - pass));

    for(int i = 0; i < 4; i++){
        ans[copyed_score[i].second] += next_pro[i] * game_result_pro;
    }
}

int main(){
    for(int i = 0; i < 4; i++){
        string name;
        cin >> name;
        country[name] = i;
        score[i] = {0, i};
    }

    for(int i = 0; i < 6; i++){
        string a, b;
        double w, d, l;
        cin >> a >> b >> w >> d >> l;
        game[country[a]][country[b]][0] = w;
        game[country[a]][country[b]][1] = d;
        game[country[a]][country[b]][2] = l;
        game[country[b]][country[a]][0] = l;
        game[country[b]][country[a]][1] = d;
        game[country[b]][country[a]][2] = w;
    }

    for(int g01 = 0; g01 < 3; g01++){
        game_result(g01, 0, 1);
        for(int g02 = 0; g02 < 3; g02++){
            game_result(g02, 0, 2);
            for (int g03 = 0; g03 < 3; g03++){
                game_result(g03, 0, 3);
                for (int g12 = 0; g12 < 3; g12++){
                    game_result(g12, 1, 2);
                    for (int g13 = 0; g13 < 3; g13++){
                        game_result(g13, 1, 3);
                        for (int g23 = 0; g23 < 3; g23++){
                            game_result(g23, 2, 3);
                            double game_result_pro = game[0][1][g01] * game[0][2][g02] * game[0][3][g03] * 
                            game[1][2][g12] * game[1][3][g13] * game[2][3][g23];
                            ranking(game_result_pro);
                            revert_game_result(g23, 2, 3);
                        }
                        revert_game_result(g13, 1, 3);
                    }
                    revert_game_result(g12, 1, 2);
                }
                revert_game_result(g03, 0, 3);
            }
            revert_game_result(g02, 0, 2);
        }
        revert_game_result(g01, 0, 1);
    }
    
    for(int i = 0; i < 4; i++)
        cout << ans[i] << '\n';

    return 0;
}