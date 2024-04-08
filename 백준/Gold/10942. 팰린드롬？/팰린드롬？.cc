#include <iostream>

using namespace std;

bool memo[2001][2001] = {false};
int seq[2001];

int main() {
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, query, start, end;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> seq[i];
        memo[i][i] = true;
        if(i > 1 && seq[i - 1] == seq[i])
            memo[i - 1][i] = true;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= 1; j--) {
            if(j + 1 <= i - 1)
                memo[j][i] = memo[j + 1][i - 1] && (seq[j] == seq[i]);
        }
    }

    cin >> query;
    while(query--) {
        cin >> start >> end;
        cout << memo[start][end] << '\n';
    }
    return 0;
}