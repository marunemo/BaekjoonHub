#include <iostream>

using namespace std;

int adj_matrix[200][200];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    bool flag;

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> adj_matrix[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            flag = true;
            for(int k = 0; k < n && flag; k++) {
                if(k == i || k == j)
                    continue;
                
                if(adj_matrix[i][j] >= adj_matrix[i][k] + adj_matrix[k][j])
                    flag = false;
            }

            if(flag)
                cout << (i + 1) << ' ' << (j + 1) << '\n';
        }
    }

    return 0;
}