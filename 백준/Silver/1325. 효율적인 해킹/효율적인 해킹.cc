#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> children;
vector<int> hacked;
vector<bool> visit;

int DFS(int parent) {
    if(visit[parent])
        return 0;

    visit[parent] = true;

    int count = 1;
    if(children[parent].size() == 0)
        return count;
    
    for(auto child: children[parent])
        count += DFS(child);
    return count;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int child, parent;
    int max_count = 0;

    cin >> n >> m;
    children = vector<vector<int>>(n + 1, vector<int>());
    while(m--) {
        cin >> child >> parent;
        children[parent].push_back(child);
    }

    hacked = vector<int>(n + 1, -1);
    for(int com = 1; com <= n; com++) {
        visit = vector<bool>(n + 1, false);
        hacked[com] = DFS(com);
        max_count = max(max_count, hacked[com]);
    }

    for(int com = 1; com <= n; com++) {
        if(hacked[com] == max_count)
            cout << com << ' ';
    }
    cout << endl;
    return 0;
}