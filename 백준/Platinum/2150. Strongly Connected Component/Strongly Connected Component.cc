#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

vector<bool> visit;
vector<vector<int>> adj_list;
vector<vector<int>> r_adj_list;
vector<pii> finish_time;
vector<vector<int>> SCC;
int SCC_count = 0;
int curr_time = 0;

void DFS(int node) {
    if(visit[node])
        return;
    
    visit[node] = true;
    curr_time++;
    for(int next: adj_list[node])
        DFS(next);
    finish_time[node] = {++curr_time, node};
}

void r_DFS(int node, int i) {
    if(visit[node])
        return;
    
    visit[node] = true;
    for(int next: r_adj_list[node]) {
        if(!visit[next]) {
            SCC[i].push_back(next);
            r_DFS(next, i);
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int vertex, edge;
    int s, e;

    cin >> vertex >> edge;
    adj_list.resize(vertex + 1);
    r_adj_list.resize(vertex + 1);
    for(int i = 0; i < edge; i++) {
        cin >> s >> e;
        adj_list[s].push_back(e);
        r_adj_list[e].push_back(s);
    }

    visit = vector<bool>(vertex + 1);
    finish_time.resize(vertex + 1);
    for(int node = 1; node <= vertex; node++)
        DFS(node);

    sort(finish_time.begin() + 1, finish_time.end(), greater<pii>());
    visit = vector<bool>(vertex + 1);
    for(int node, i = 1; i <= vertex; i++) {
        node = finish_time[i].second;
        if(!visit[node]) {
            SCC.push_back(vector<int>({node}));
            r_DFS(node, SCC_count);
            sort(SCC[SCC_count].begin(), SCC[SCC_count].end());
            SCC_count++;
        }
    }

    cout << SCC.size() << '\n';
    sort(SCC.begin(), SCC.end());
    for(int i = 0; i < SCC.size(); i++) {
        for(int node: SCC[i])
            cout << node << ' ';
        cout << "-1\n";
    }
    return 0;
}