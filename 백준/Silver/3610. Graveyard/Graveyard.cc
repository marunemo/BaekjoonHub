#include <iostream>

using namespace std;
using pii = pair<int, int>;

int GCD(int a, int b) {
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

double GetDist(pii pos, pii bucket) {
    return abs((double)pos.first / pos.second - (double)bucket.first / bucket.second);
}

int main() {
    const double feet = 10000;

    int n, m;
    pii pos[2000];
    pii bucket[2000];
    bool selected[2000] = {false};
    int gcd;
    int min_index;
    double dist, min_dist;
    double min_move = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        gcd = GCD(i, n);
        pos[i] = {i / gcd, n / gcd};
    }

    m += n;
    for(int i = 0; i < m; i++) {
        gcd = GCD(i, m);
        bucket[i] = {i / gcd, m / gcd};
    }

    for(int i = 0; i < n; i++) {
        min_dist = 2;
        for(int j = 0; j < m; j++) {
            if(selected[j])
                continue;

            dist = GetDist(pos[i], bucket[j]);
            if(min_dist > dist) {
                min_dist = dist;
                min_index = j;
            }
        }

        selected[min_index] = true;
        min_move += min_dist;
    }

    cout.precision(6);
    cout << fixed << feet * min_move << endl;
    return 0;
}