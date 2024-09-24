#include <iostream>

using namespace std;

int club_count;
bool club[51][51];
bool link[51][51];
bool link_copy[51][51];
int insider_score[51];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int c1 = 0, c2 = 0;
    bool flag;
    int min_score;
    int candidate_count;

    cin >> club_count;
    cin >> c1 >> c2;
    while(c1 != -1 && c2 != -1) {
        club[c1][c2] = club[c2][c1] = true;
        link[c1][c2] = link[c2][c1] = true;
        cin >> c1 >> c2;
    }

    for(int depth = 1; depth <= club_count; depth++) {
        for(int src = 1; src <= club_count; src++) {
            flag = true;
            for(int dest = 1; dest <= club_count && flag; dest++) {
                if(src == dest)
                    continue;
                
                flag &= link[src][dest];
            }

            if(flag && !insider_score[src])
                insider_score[src] = depth;
        }

        for(int src = 1; src <= club_count; src++) {
            for(int dest = 1; dest <= club_count; dest++) {
                if(src == dest)
                    continue;

                link_copy[src][dest] = link[src][dest];
                for(int inter = 1; inter <= club_count; inter++)
                    link_copy[src][dest] = link_copy[src][dest] | (link[src][inter] & club[inter][dest]);
            }
        }

        for(int i = 1; i <= club_count; i++) {
            for(int j = 1; j <= club_count; j++)
                link[i][j] = link_copy[i][j];
        }
    }

    min_score = club_count + 1;
    for(int i = 1; i <= club_count; i++) {
        if(insider_score[i] == min_score)
            candidate_count++;
        else if(insider_score[i] < min_score) {
            min_score = insider_score[i];
            candidate_count = 1;
        }
    }
    
    cout << min_score << ' ' << candidate_count << '\n';
    for(int i = 1; i <= club_count; i++) {
        if(insider_score[i] == min_score)
            cout << i << ' ';
    }
    cout << endl;
    return 0;
}