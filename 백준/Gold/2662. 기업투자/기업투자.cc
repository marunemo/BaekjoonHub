#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<vector<int>> com_benefit;
    int invest, benefit;
    vector<int> max_benefit;
    vector<vector<int>> invest_list;

    cin >> n >> m;

    com_benefit = vector<vector<int>>(n + 1, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        cin >> invest;
        for(int com = 0; com < m; com++)
            cin >> com_benefit[invest][com];
    }

    max_benefit = vector<int>(n + 1, 0);
    invest_list = vector<vector<int>>(n + 1, vector<int>());
    for(int com = 0; com < m; com++) {
        for(int max_invest = n; max_invest >= 1; max_invest--) {
            invest_list[max_invest].push_back(0);
            for(int amount = max_invest; amount >= 0; amount--) {
                if(max_benefit[max_invest] < max_benefit[max_invest - amount] + com_benefit[amount][com]) {
                    max_benefit[max_invest] = max_benefit[max_invest - amount] + com_benefit[amount][com];
                    invest_list[max_invest] = invest_list[max_invest - amount];
                    invest_list[max_invest].push_back(amount);
                }
            }
        }
        invest_list[0].push_back(0);
    }

    cout << max_benefit[n] << '\n';
    for(int i = 0; i < m; i++)
        cout << invest_list[n][i] << ' ';
    cout << endl;
    return 0;
}