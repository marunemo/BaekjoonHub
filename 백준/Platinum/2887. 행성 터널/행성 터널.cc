#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
using TunnelSet = pair<int, int>;
using Edge = pair<ll, TunnelSet>;

struct Coord {
    int index;
    ll x, y, z;
};

vector<Coord> pos;
vector<int> parent;
priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

bool CompareX(Coord a, Coord b) {
    return a.x < b.x;
}

bool CompareY(Coord a, Coord b) {
    return a.y < b.y;
}

bool CompareZ(Coord a, Coord b) {
    return a.z < b.z;
}

int UnionFind(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent[node]);
}

ll GetWeight(int i, int j) {
    ll weight = min(abs(pos[i].x - pos[j].x), abs(pos[i].y - pos[j].y));
    weight = min(weight, abs(pos[i].z - pos[j].z));
    return weight;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tunnel_count;
    TunnelSet tunnel;
    ll weight;
    ll total_weight = 0;

    cin >> tunnel_count;
    pos = vector<Coord>(tunnel_count);
    parent = vector<int>(tunnel_count);
    for(int i = 0; i < tunnel_count; i++) {
        cin >> pos[i].x >> pos[i].y >> pos[i].z;
        pos[i].index = i;
        parent[i] = i;
    }

    sort(pos.begin(), pos.end(), CompareX);
    for(int i = 1; i < tunnel_count; i++)
        edges.push({GetWeight(i, i - 1), {pos[i - 1].index, pos[i].index}});

    sort(pos.begin(), pos.end(), CompareY);
    for(int i = 1; i < tunnel_count; i++)
        edges.push({GetWeight(i, i - 1), {pos[i - 1].index, pos[i].index}});
    
    sort(pos.begin(), pos.end(), CompareZ);
    for(int i = 1; i < tunnel_count; i++)
        edges.push({GetWeight(i, i - 1), {pos[i - 1].index, pos[i].index}});

    while(!edges.empty()) {
        weight = edges.top().first;
        tunnel = edges.top().second;
        edges.pop();

        if(UnionFind(tunnel.first) == UnionFind(tunnel.second))
            continue;
        
        if(parent[tunnel.first] > parent[tunnel.second])
            parent[parent[tunnel.first]] = parent[tunnel.second];
        else
            parent[parent[tunnel.second]] = parent[tunnel.first];
        total_weight += weight;
    }

    cout << total_weight << endl;
    return 0;
}