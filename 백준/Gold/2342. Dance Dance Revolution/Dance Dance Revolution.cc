#include <iostream>
#define INF 1000000

using namespace std;

int step[100001][5][5];

int GetForce(int from, int to) {
    if(from == 0)
        return 2;
    if(from == to)
        return 1;
    if(abs(from - to) == 2)
        return 4;
    return 3;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int dir, phase;
    int min_force = INF;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            step[0][i][j] = INF;
    }
    step[0][0][0] = 0;

    cin >> dir;
    for(phase = 1; dir; phase++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++)
                step[phase][i][j] = INF;
        }

        for(int stop = 0; stop < 5; stop++) {
            for(int pre_dir = 0; pre_dir < 5; pre_dir++)
                step[phase][dir][stop] = min(step[phase][dir][stop], step[phase - 1][pre_dir][stop] + GetForce(pre_dir, dir));
        }

        for(int stop = 0; stop < 5; stop++) {
            for(int pre_dir = 0; pre_dir < 5; pre_dir++)
                step[phase][stop][dir] = min(step[phase][stop][dir], step[phase - 1][stop][pre_dir] + GetForce(pre_dir, dir));
        }

        cin >> dir;
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            min_force = min(min_force, step[phase - 1][i][j]);
    }

    cout << min_force << endl;
    return 0;
}