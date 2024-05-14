#include <iostream>
#include <queue>

using namespace std;
using Edge = pair<int, pair<int, int>>;

int parent[200000];
priority_queue<Edge, vector<Edge>, greater<Edge>> Q;

int UnionFind(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent[node]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int house_count, road_count;
    int road1, road2, distance;
    int total_weight, reduced_weight;

    cin >> house_count >> road_count;
    while(house_count != 0 || road_count != 0) {
        total_weight = 0;
        reduced_weight = 0;

        while(road_count--) {
            cin >> road1 >> road2 >> distance;
            Q.push({distance, {road1, road2}});
            total_weight += distance;
        }

        for(int i = 0; i <= house_count; i++)
            parent[i] = i;

        while(!Q.empty()) {
            road1 = Q.top().second.first;
            road2 = Q.top().second.second;
            distance = Q.top().first;
            Q.pop();

            if(UnionFind(road1) == UnionFind(road2))
                continue;
            
            if(parent[road1] > parent[road2])
                parent[parent[road1]] = parent[road2];
            else
                parent[parent[road2]] = parent[road1];
            reduced_weight += distance;
        }

        cout << (total_weight - reduced_weight) << '\n';
        cin >> house_count >> road_count;
    }
    return 0;
}