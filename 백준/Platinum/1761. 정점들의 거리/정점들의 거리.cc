#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Edge {
    int src, dist;

    Edge(int s, int d) {
        src = s, dist = d;
    }
};

vector<int> depth;
vector<vector<int>> parent;
vector<vector<int>> parent_distance;
vector<vector<Edge>> adj_list;
int square_height;

void DFS(int node, Edge prev, int height) {
    depth[node] = height;
    
    parent[node][0] = prev.src;
    parent_distance[node][0] = prev.dist;
    for(int i = 1; i <= square_height; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
        parent_distance[node][i] = parent_distance[node][i - 1] + parent_distance[parent[node][i - 1]][i - 1];
    }

    for(Edge next: adj_list[node]) {
        if(next.src != prev.src)
            DFS(next.src, Edge(node, next.dist), height + 1);
    }
}

int LCA_distance(int node1, int node2) {
    int distance = 0;

    for(int i = square_height; i >= 0 && depth[node1] > depth[node2]; i--) {
        if(depth[parent[node1][i]] >= depth[node2]) {
            distance += parent_distance[node1][i];
            node1 = parent[node1][i];
        }
    }
    
    for(int i = square_height; i >= 0 && depth[node1] < depth[node2]; i--) {
        if(depth[parent[node2][i]] >= depth[node1]) {
            distance += parent_distance[node2][i];
            node2 = parent[node2][i];
        }
    }
    
    while(node1 != node2) {
        for(int i = 1; i <= square_height; i++) {
            if(parent[node1][i] == parent[node2][i]) {
                distance += parent_distance[node1][i - 1];
                distance += parent_distance[node2][i - 1];

                node1 = parent[node1][i - 1];
                node2 = parent[node2][i - 1];
                break;
            }
        }
    }

    return distance;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count, query_count;
    int node1, node2, dist;

    cin >> node_count;
    
    square_height = log2(node_count + 1);

    depth.resize(node_count + 1);
    parent.resize(node_count + 1, vector<int>(square_height + 1));
    parent_distance.resize(node_count + 1, vector<int>(square_height + 1));
    adj_list.resize(node_count + 1);

    for(int i = 0; i < node_count - 1; i++) {
        cin >> node1 >> node2 >> dist;
        
        adj_list[node1].push_back(Edge(node2, dist));
        adj_list[node2].push_back(Edge(node1, dist));
    }

    depth[0] = 0;
    DFS(1, Edge(0, 0), 1);

    cin >> query_count;
    while(query_count--) {
        cin >> node1 >> node2;

        cout << LCA_distance(node1, node2) << '\n';
    }
    return 0;
}