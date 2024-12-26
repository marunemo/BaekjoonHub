#include <iostream>
#define INF 1e8

using namespace std;

int adj_matrix[301][301];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m, t;
    int u, v, h;
    int s, e;

    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            adj_matrix[i][j] = INF;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> h;
        adj_matrix[u][v] = min(adj_matrix[u][v], h);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                adj_matrix[i][j] = min(adj_matrix[i][j], max(adj_matrix[i][k], adj_matrix[k][j]));
        }
    }

    for(int i = 0; i < t; i++) {
        cin >> s >> e;
        if(adj_matrix[s][e] >= INF)
            cout << -1 << '\n';
        else 
            cout << adj_matrix[s][e] << '\n';
    }
    return 0;
}