#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int team_count;
    vector<int> team;
    vector<int> count;
    vector<vector<int>> list;
    int min_score, score, victory;
    
    cin >> tc;
    for(int score = 0; tc--; ) {
        cin >> team_count;

        team.resize(team_count);
        count = vector<int>(201, 0);
        list = vector<vector<int>>(201, vector<int>());

        for(int i = 0; i < team_count; i++) {
            cin >> team[i];
            count[team[i]]++;
        }

        for(int i = 0; i < team_count; i++) {
            if(count[team[i]] >= 6)
                list[team[i]].push_back(++score);
        }

        min_score = victory = 0;
        for(int i = 1; i <= 200; i++) {
            if(count[i] >= 6) {
                score = list[i][0] + list[i][1] + list[i][2] + list[i][3];
                if(!min_score || min_score > score) {
                    min_score = score;
                    victory = i;
                }
                else if(min_score == score) {
                    if(list[victory][4] > list[i][4])
                        victory = i;
                }
            }
        }

        cout << victory << '\n';
    }
    return 0;
}