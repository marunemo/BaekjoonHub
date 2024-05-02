#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> visit;
queue<int> dist_node;
priority_queue<int, vector<int>, greater<int>> result;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count, edge_count, distance, start;
    int src, dest;
    int curr_dist, size;

    cin >> node_count >> edge_count >> distance >> start;
    
    adj_list = vector<vector<int>>(node_count + 1, vector<int>());
    while(edge_count--) {
        cin >> src >> dest;
        adj_list[src].push_back(dest);
    }

    visit = vector<bool>(node_count + 1, false);
    visit[start] = true;

    curr_dist = 0;
    dist_node.push(start);
    while(!dist_node.empty() && curr_dist < distance) {
        size = dist_node.size();
        while(size--) {
            src = dist_node.front();
            dist_node.pop();

            for(auto dest: adj_list[src]) {
                if(!visit[dest]) {
                    visit[dest] = true;
                    dist_node.push(dest);
                }
            }
        }
        curr_dist++;
    }

    if(dist_node.empty())
        cout << -1 << endl;
    else {
        while(!dist_node.empty()) {
            result.push(dist_node.front());
            dist_node.pop();
        }

        while(!result.empty()) {
            cout << result.top() << '\n';
            result.pop();
        }
    }
    return 0;
}