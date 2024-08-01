#include <iostream>

using namespace std;
using Pos = pair<int, int>;

int cow_count, group_count;
Pos group[100001][2];
int parent[100001];
int group_index;

int UnionFind(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent[node]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a, b;
    int min_area = 500000000;

    cin >> cow_count >> group_count;
    for(int i = 1; i <= cow_count; i++) {
        cin >> group[i][0].first >> group[i][0].second;
        group[i][1] = group[i][0];
        parent[i] = i;
    }

    for(int i = 0; i < group_count; i++) {
        cin >> a >> b;

        if(UnionFind(a) == UnionFind(b))
            continue;
        
        if(parent[a] < parent[b]) {
            group[parent[a]][0].first = min(group[parent[a]][0].first, group[parent[b]][0].first);
            group[parent[a]][0].second = min(group[parent[a]][0].second, group[parent[b]][0].second);
            group[parent[a]][1].first = max(group[parent[a]][1].first, group[parent[b]][1].first);
            group[parent[a]][1].second = max(group[parent[a]][1].second, group[parent[b]][1].second);

            parent[parent[b]] = parent[a];
        }
        else {
            group[parent[b]][0].first = min(group[parent[b]][0].first, group[parent[a]][0].first);
            group[parent[b]][0].second = min(group[parent[b]][0].second, group[parent[a]][0].second);
            group[parent[b]][1].first = max(group[parent[b]][1].first, group[parent[a]][1].first);
            group[parent[b]][1].second = max(group[parent[b]][1].second, group[parent[a]][1].second);

            parent[parent[a]] = parent[b];
        }
    }

    parent[0] = 0;
    for(int i = 1; i <= cow_count; i++) {
        if(UnionFind(i) != 0) {
            parent[parent[i]] = 0;
            min_area = min(min_area, 2 * ((group[i][1].first - group[i][0].first) + (group[i][1].second - group[i][0].second)));
        }
    }
    cout << min_area << endl;
    return 0;
}