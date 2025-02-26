#include <iostream>
#include <queue>

using namespace std;
using Node = pair<int, int>;

vector<vector<int>> adj_list;
vector<int> army;
vector<bool> occupied;
priority_queue<Node, vector<Node>, greater<Node>> pq;

int main() {
    int vertex_count, edge_count;
    int node1, node2;
    int spanning_nation;

    cin >> vertex_count >> edge_count;
    
    adj_list.resize(vertex_count + 1);
    for(int i = 0; i < edge_count; i++) {
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    army.resize(vertex_count + 1);
    for(int i = 1; i <= vertex_count; i++)
        cin >> army[i];

    occupied.resize(vertex_count + 1);

    spanning_nation = army[1];
    occupied[1] = true;

    for(int next: adj_list[1]) {
        if(!occupied[next])
            pq.push({army[next], next});
    }
    
    for(Node node; !pq.empty(); ) {
        node = pq.top();
        pq.pop();

        if(occupied[node.second])
            continue;

        if(node.first >= spanning_nation)
            continue;
        
        spanning_nation += node.first;
        occupied[node.second] = true;

        for(int next: adj_list[node.second]) {
            if(!occupied[next])
                pq.push({army[next], next});
        }
    }

    cout << spanning_nation << endl;
    return 0;
}