#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int tc;
    ll game;
    ll mission[100][3];
    ll kda[3];
    ll result;

    cin >> tc;
    while(tc--) {
        cin >> game;

        for(int i = 0; i < game; i++) {
            for(int j = 0; j < 3; j++)
                cin >> mission[i][j];
        }

        for(int i = 0; i < 3; i++)
            cin >> kda[i];
        
        result = 0;
        for(int i = 0; i < game; i++) {
            if(mission[i][0] * kda[0] - mission[i][1] * kda[1] + mission[i][2] * kda[2] > 0)
                result += mission[i][0] * kda[0] - mission[i][1] * kda[1] + mission[i][2] * kda[2];
        }

        cout << result << '\n';
    }
    return 0;
}