#include <iostream>

using namespace std;

int step_count;
int step[100000];
int memo[100000][5][5];

int GetForce(int from, int to) {
    if(from == 0)
        return 2;
    if(from == to)
        return 1;
    if(abs(from - to) == 2)
        return 4;
    return 3;
}

int DFS(int depth, int left, int right) {
    if(depth == step_count)
        return 0;
    
    if(memo[depth][left][right] != -1)
        return memo[depth][left][right];

    int left_changed = DFS(depth + 1, step[depth], right) + GetForce(left, step[depth]);
    int right_changed = DFS(depth + 1, left, step[depth]) + GetForce(right, step[depth]);
    return memo[depth][left][right] = min(left_changed, right_changed);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int ddr;

    cin >> ddr;
    for(step_count = 0; ddr; step_count++) {
        step[step_count] = ddr;
        cin >> ddr;
    }

    for(int i = 0; i < step_count; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++)
                memo[i][j][k] = -1;
        }
    }

    cout << DFS(0, 0, 0) << endl;
    return 0;
}