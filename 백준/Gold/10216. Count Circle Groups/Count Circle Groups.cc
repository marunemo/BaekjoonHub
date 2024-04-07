#include <iostream>
#define SQUARE(x) (x)*(x)

using namespace std;
using Pos = pair<int, int>;

int SquareDistance(Pos a, Pos b) {
    return SQUARE(b.second - a.second) + SQUARE(b.first - a.first);
}

int UnionFind(int* parent, int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent, parent[node]);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int enemy_count;
    Pos enemy[3000];
    int range[3000];
    int group[3000];
    int group_count;

    cin >> tc;
    while(tc--) {
        cin >> enemy_count;
        for(int i = 0; i < enemy_count; i++) {
            cin >> enemy[i].first >> enemy[i].second >> range[i];
            group[i] = i;
        }

        group_count = enemy_count;
        for(int i = 0; i < enemy_count; i++) {
            for(int j = 0; j < i; j++) {
                if(SquareDistance(enemy[i], enemy[j]) > SQUARE(range[i] + range[j]))
                    continue;
                
                if(UnionFind(group, i) == UnionFind(group, j))
                    continue;
                
                if(group[i] > group[j])
                    group[group[i]] = group[j];
                else
                    group[group[j]] = group[i];
                group_count--;
            }
        }
        cout << group_count << '\n';
    }
    return 0;
}