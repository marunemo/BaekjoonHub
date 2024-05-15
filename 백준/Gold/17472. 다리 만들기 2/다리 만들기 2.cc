#include <iostream>
#include <queue>
#define INF 100

using namespace std;
using Edge = pair<int, pair<int, int>>;

int height, width;
vector<vector<int>> map;
vector<vector<int>> conn_comp;
int connect_index = 0;
vector<vector<int>> adj_matrix;
vector<int> parent;
priority_queue<Edge, vector<Edge>, greater<Edge>> heap;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void Connect(int row, int col) {
    queue<pair<int, int>> Q;
    Q.push({row, col});
    conn_comp[row][col] = ++connect_index;

    while(!Q.empty()) {
        auto [row, col] = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            if(row + dy[i] < 0 || row + dy[i] >= height || col + dx[i] < 0 || col + dx[i] >= width)
                continue;

            if(map[row + dy[i]][col + dx[i]] == 1 && !conn_comp[row + dy[i]][col + dx[i]]) {
                conn_comp[row + dy[i]][col + dx[i]] = connect_index;
                Q.push({row + dy[i], col + dx[i]});
            }
        }
    }
}

void FindSafeEdge(int row, int col) {
    int dis_x, dis_y;
    int dist;

    for(int i = 0; i < 4; i++) {
        dis_x = dx[i];
        dis_y = dy[i];

        while(!(row + dis_y < 0 || row + dis_y >= height || col + dis_x < 0 || col + dis_x >= width)) {
            if(conn_comp[row + dis_y][col + dis_x]) {
                dist = abs(dis_x + dis_y) - 1;
                if(conn_comp[row + dis_y][col + dis_x] != conn_comp[row][col] && dist >= 2) {
                    if(adj_matrix[conn_comp[row][col]][conn_comp[row + dis_y][col + dis_x]] > dist)
                        adj_matrix[conn_comp[row][col]][conn_comp[row + dis_y][col + dis_x]] = dist;
                    if(adj_matrix[conn_comp[row + dis_y][col + dis_x]][conn_comp[row][col]] > dist)
                        adj_matrix[conn_comp[row + dis_y][col + dis_x]][conn_comp[row][col]] = dist;
                }
                break;
            }
            dis_y += dy[i];
            dis_x += dx[i];
        }
    }
}

int UnionFind(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent[node]);
}

int main() {
    int min_weight = 0;
    int edge_count = 0;

    cin >> height >> width;
    map = vector<vector<int>>(height, vector<int>(width));
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> map[row][col];
    }
    
    conn_comp = vector<vector<int>>(height, vector<int>(width, 0));
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(map[row][col] == 1 && !conn_comp[row][col])
                Connect(row, col);
        }
    }

    adj_matrix = vector<vector<int>>(connect_index + 1, vector<int>(connect_index + 1, INF));
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(conn_comp[row][col])
                FindSafeEdge(row, col);
        }
    }

    parent = vector<int>(connect_index + 1);
    for(int i = 1; i <= connect_index; i++)
        parent[i] = i;
    
    for(int src = 1; src <= connect_index; src++) {
        for(int dest = 1; dest <= connect_index; dest++) {
            if(adj_matrix[src][dest] != INF)
                heap.push({adj_matrix[src][dest], {src, dest}});
        }
    }

    while(!heap.empty()) {
        auto [dist, node] = heap.top();
        heap.pop();

        if(UnionFind(node.first) == UnionFind(node.second))
            continue;
        
        if(parent[node.first] > parent[node.second])
            parent[parent[node.first]] = parent[node.second];
        else
            parent[parent[node.second]] = parent[node.first];
        min_weight += dist;
        edge_count++;
    }

    if(edge_count != connect_index - 1)
        min_weight = -1;

    cout << min_weight << endl;
    return 0;
}