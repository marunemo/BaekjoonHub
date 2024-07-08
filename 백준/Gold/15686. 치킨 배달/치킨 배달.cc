#include <iostream>
#include <queue>
#define INF 2500

using namespace std;
using Pos = pair<int, int>;

int n, m;
vector<Pos> house;
vector<Pos> chicken;

int MinDistance(int mask, int index, int count) {
    int min_dist = INF;
    int dist = 0;

    if(count == m) {
        min_dist = 0;
        for(Pos h_pos: house) {
            dist = INF;
            for(int i = 0; i < chicken.size(); i++) {
                if(mask & (1 << i))
                    dist = min(dist, abs(h_pos.first - chicken[i].first) + abs(h_pos.second - chicken[i].second));
            }
            min_dist += dist;
        }
        return min_dist;
    }

    if(index == chicken.size())
        return INF;

    return min(MinDistance(mask, index + 1, count), MinDistance(mask | (1 << index), index + 1, count + 1));
}

int main() {
    int info;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> info;

            if(info == 1)
                house.push_back({i, j});
            else if(info == 2)
                chicken.push_back({i, j});
        }
    }

    cout << MinDistance(0, 0, 0) << endl;
    return 0;
}