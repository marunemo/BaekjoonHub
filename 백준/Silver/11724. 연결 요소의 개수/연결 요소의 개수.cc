#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> const &adj_list, vector<bool> &visit, int node) {
    for(auto vertex: adj_list[node]) {
        if(!visit[vertex]) {
            visit[vertex] = true;
            DFS(adj_list, visit, vertex);
        }
    }
}

int main() {
    int node, edge;
    vector<vector<int>> adj_list;
    int start, end;
    vector<bool> visit;
    int count = 0;

    cin >> node >> edge;
    adj_list = vector<vector<int>>(node + 1, vector<int>());
    while(edge--) {
        cin >> start >> end;
        adj_list[start].push_back(end);
        adj_list[end].push_back(start);
    }

    visit = vector<bool>(node + 1, false);
    for(int vertex = 1; vertex <= node; vertex++) {
        if(!visit[vertex]) {
            visit[vertex] = true;
            DFS(adj_list, visit, vertex);
            count++;
        }
    }

    cout << count << endl;
    return 0;
}