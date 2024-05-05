#include <iostream>

using namespace std;
using ll = long long;

ll GCD(ll a, ll b) {
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int card;
    int edge[20001];
    bool visited[20001];
    int index;
    ll cycle_node;
    ll divisor;
    ll trajectory = 1;

    cin >> card;
    for(int i = 1; i <= card; i++) {
        cin >> edge[i];
        visited[i] = false;
    }
    
    for(int i = 1; i <= card; i++) {
        if(edge[i] == i)
            continue;
        
        if(visited[i])
            continue;
        
        cycle_node = 0;
        index = i;
        while(!visited[index]) {
            visited[index] = true;
            cycle_node++;
            index = edge[index];
        }

        divisor = GCD(trajectory, cycle_node);
        trajectory = (cycle_node / divisor * trajectory);
    }

    cout << trajectory << endl;
    return 0;
}