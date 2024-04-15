#include <iostream>

using namespace std;

int parent[500000];

int UnionFind(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent[node]);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int dot1, dot2;
    int cycle = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        parent[i] = i;

    for(int phase = 1; phase <= m; phase++) {
        cin >> dot1 >> dot2;

        if(UnionFind(dot1) == UnionFind(dot2)) {
            cycle = phase;
            break;
        }

        if(parent[dot1] > parent[dot2])
            parent[parent[dot1]] = parent[dot2];
        else
            parent[parent[dot2]] = parent[dot1];
    }

    cout << cycle << endl;
    return 0;
}