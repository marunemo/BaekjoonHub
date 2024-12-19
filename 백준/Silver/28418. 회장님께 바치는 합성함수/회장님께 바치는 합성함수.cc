#include <iostream>

using namespace std;

int main() {
    int f[3] = {0};
    int g[3] = {0};
    int p[3] = {0};
    int q[3] = {0};
    int d[3] = {0};
    int det;

    cin >> f[0] >> f[1] >> f[2];
    cin >> g[1] >> g[2];

    p[0] = f[0] * (g[1] * g[1]);
    p[1] = f[0] * (2 * g[1] * g[2]) + f[1] * g[1];
    p[2] = f[0] * (g[2] * g[2]) + f[1] * g[2] + f[2];

    q[0] = g[1] * f[0];
    q[1] = g[1] * f[1];
    q[2] = g[1] * f[2] + g[2];

    for(int i = 0; i < 3; i++)
        d[i] = p[i] - q[i];
    det = d[1] * d[1] - 4 * d[0] * d[2];

    if(!d[0] && !d[1]) {
        if(!d[2])
            cout << "Nice";
        else
            cout << "Head on";
    }
    else if(!d[0])
        cout << "Remember my character";
    else if(det > 0)
        cout << "Go ahead";
    else if(det == 0)
        cout << "Remember my character";
    else
        cout << "Head on";
    cout << endl;
    return 0;
}