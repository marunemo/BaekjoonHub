#include <iostream>
#include <vector>

using namespace std;

int depth[500001];
int parent[500001];
vector<vector<int>> adj_list;

void DFS(int node, int prev, int height) {
    depth[node] = height;
    parent[node] = prev;

    for(int next: adj_list[node]) {
        if(next != prev)
            DFS(next, node, height + 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count, query_count;
    int node1, node2;

    cin >> node_count;
    
    adj_list.resize(node_count + 1);
    for(int i = 0; i < node_count - 1; i++) {
        cin >> node1 >> node2;
        
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    DFS(1, 0, 0);

    cin >> query_count;
    while(query_count--) {
        cin >> node1 >> node2;

        while(depth[node1] > depth[node2])
            node1 = parent[node1];
        while(depth[node1] < depth[node2])
            node2 = parent[node2];
            
        while(node1 != node2) {
            node1 = parent[node1];
            node2 = parent[node2];
        }

        cout << node1 << '\n';
    }
    return 0;
}