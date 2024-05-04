#include <iostream>

using namespace std;

int edge[1001];
bool visit[1001];

void DFS(int node) {
    if(visit[node])
        return;
        
    visit[node] = true;
    DFS(edge[node]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int size;
    int dest;
    int cycle;

    cin >> tc;
    while(tc--) {
        cin >> size;
        for(int i = 1; i <= size; i++) {
            cin >> edge[i];
            visit[i] = false;
        }
        
        cycle = 0;
        for(int i = 1; i <= size; i++) {
            if(!visit[i]) {
                cycle++;
                DFS(i);
            }
        }

        cout << cycle << '\n';
    }
    return 0;
}