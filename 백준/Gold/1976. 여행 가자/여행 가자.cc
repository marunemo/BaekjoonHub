#include <iostream>

using namespace std;

int adj_matrix[200][200];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int prev, curr;
    bool flag = true;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> adj_matrix[i][j];
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                adj_matrix[i][j] = adj_matrix[i][j] | (adj_matrix[i][k] & adj_matrix[k][j]);
        }
    }

    // 같은 도시를 여러 번 방문하는 것도 가능하다. - 문제 中
    for(int i = 0; i < n; i++)
        adj_matrix[i][i] = true;

    cin >> prev;
    while(--m && flag) {
        cin >> curr;
        flag = adj_matrix[prev - 1][curr - 1];
        prev = curr;
    }

    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}