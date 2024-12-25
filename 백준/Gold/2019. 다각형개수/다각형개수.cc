#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using Pos = pair<int, int>;

unordered_map<int, unordered_map<int, vector<Pos>>> adj_list;
vector<Pos> pos;
unordered_map<int, unordered_map<int, bool>> pick;
unordered_map<int, unordered_map<int, bool>> visit;

bool MakeHull(Pos curr, Pos init, int depth = 0) {
    if(adj_list[curr.first][curr.second].size() != 2)
        return false;

    visit[curr.first][curr.second] = true;
    for(Pos vertex: adj_list[curr.first][curr.second]) {
        if(depth >= 2 && vertex == init)
            return pick[curr.first][curr.second] = true;
        
        if(visit[vertex.first][vertex.second])
            continue;

        if(MakeHull(vertex, init, depth + 1))
            return pick[curr.first][curr.second] = true;
    }
    return false;
}

int main() {
    int n, a, b, c, d;
    int count = 0;

    cin >> n;
    while(n--) {
        cin >> a >> b >> c >> d;
        
        if(adj_list[a][b].empty())
            pos.push_back({a, b});
        if(adj_list[c][d].empty())
            pos.push_back({c, d});
        
        adj_list[a][b].push_back({c, d});
        adj_list[c][d].push_back({a, b});
    }

    for(Pos vertex: pos) {
        if(!pick[vertex.first][vertex.second]) {
            visit.clear();
            count += MakeHull(vertex, vertex);
        }
    }

    cout << count << endl;
    return 0;
}