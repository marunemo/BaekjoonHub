#include <iostream>
#include <cmath>

using namespace std;
using Pos = pair<int, int>;

int city_count;
Pos city[16];
double memo[16][1 << 16];

double norm2d(Pos a, Pos b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double TSP(int curr, int mask) {
    if(mask == (1 << city_count) - 1)
        return norm2d(city[curr], city[0]);
    
    if(memo[curr][mask])
        return memo[curr][mask];

    double &min_cost = memo[curr][mask] = 1000000;
    for(int next = 0; next < city_count; next++) {
        if(mask & (1 << next))
            continue;
        
        min_cost = min(min_cost, TSP(next, mask | (1 << next)) + norm2d(city[curr], city[next]));
    }
    return min_cost;
}

int main() {
    cin >> city_count;
    for(int i = 0; i < city_count; i++)
        cin >> city[i].first >> city[i].second;

    cout.precision(13);
    cout << fixed << TSP(0, 1) << endl;
    return 0;
}