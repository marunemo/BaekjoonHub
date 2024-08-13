#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<int> preq;
vector<bool> visit;

bool HasForward(int node) {
    if(visit[node])
        return true;
    
    visit[node] = true;
    for(int next: adj_list[node]) {
        if(HasForward(next))
            return true;
    }

    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, n, m;
    int vertice;
    bool inherit;

    cin >> tc;
    for(int cs = 1; cs <= tc; cs++) {
        cin >> n;
        
        adj_list = vector<vector<int>>(n + 1);
        preq = vector<int>(n + 1);
        
        for(int i = 1; i <= n; i++) {
            cin >> m;
            while(m--) {
                cin >> vertice;

                adj_list[i].push_back(vertice);
                preq[vertice]++;
            }
        }

        inherit = false;
        for(int node = 1; node <= n && !inherit; node++) {
            if(!preq[node]) {
                visit = vector<bool>(n + 1);
                inherit = HasForward(node);
            }
        }

        cout << "Case #" << cs << ": ";
        if(inherit)
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
    }
    return 0;
}