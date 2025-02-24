#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> depth;
vector<vector<int>> parent;
vector<vector<int>> adj_list;
int square_height;

void DFS(int node, int prev, int height) {
    depth[node] = height;
    
    parent[node][0] = prev;
    for(int i = 1; i <= square_height; i++)
        parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for(int next: adj_list[node]) {
        if(next != prev)
            DFS(next, node, height + 1);
    }
}

int LCA(int node1, int node2) {
    while(depth[node1] > depth[node2]) {
        for(int i = square_height; i >= 0; i--) {
            if(depth[parent[node1][i]] >= depth[node2])
                node1 = parent[node1][i];
        }
    }

    while(depth[node1] < depth[node2]) {
        for(int i = square_height; i >= 0; i--) {
            if(depth[parent[node2][i]] >= depth[node1])
                node2 = parent[node2][i];
        }
    }

    while(node1 != node2) {
        for(int i = 1; i <= square_height; i++) {
            if(parent[node1][i] == parent[node2][i]) {
                node1 = parent[node1][i - 1];
                node2 = parent[node2][i - 1];
                break;
            }
        }
    }

    return node1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count, query_count;
    int node1, node2;

    cin >> node_count;
    
    square_height = log2(node_count + 1);

    depth.resize(node_count + 1);
    parent.resize(node_count + 1, vector<int>(square_height + 1));
    adj_list.resize(node_count + 1);

    for(int i = 0; i < node_count - 1; i++) {
        cin >> node1 >> node2;
        
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    depth[0] = 0;
    DFS(1, 0, 1);

    cin >> query_count;
    while(query_count--) {
        cin >> node1 >> node2;

        cout << LCA(node1, node2) << '\n';
    }
    return 0;
}