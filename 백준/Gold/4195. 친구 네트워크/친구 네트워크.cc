#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string UnionFind(unordered_map<string, string> &parent, string node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent, parent[node]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int tc;
    int relation;
    string f1, f2;
    unordered_map<string, string> parent;
    unordered_map<string, int> f_count;

    cin >> tc;
    while(tc--) {
        cin >> relation;

        parent.clear();
        f_count.clear();
        while(relation--) {
            cin >> f1 >> f2;

            if(parent[f1].empty()) {
                parent[f1] = f1;
                f_count[f1] = 1;
            }
            if(parent[f2].empty()) {
                parent[f2] = f2;
                f_count[f2] = 1;
            }

            if(UnionFind(parent, f1) != UnionFind(parent, f2)) {
                f_count[parent[f1]] += f_count[parent[f2]];
                parent[parent[f2]] = parent[f1];
            }
            cout << f_count[parent[f1]] << '\n';
        }
    }
    return 0;
}