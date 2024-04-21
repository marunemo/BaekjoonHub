#include <iostream>
#include <vector>

using namespace std;

vector<int> gate;

int UnionFind(int plane) {
    if(gate[plane] == plane)
        return plane;
    return gate[plane] = UnionFind(gate[plane]);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int gate_count, plane_count, plane;
    int docking = 0;

    cin >> gate_count >> plane_count;
    gate = vector<int>(gate_count + 1);
    for(int i = 0; i <= gate_count; i++)
        gate[i] = i;
    
    while(plane_count--) {
        cin >> plane;
        
        if(!UnionFind(plane))
            break;
        
        gate[gate[plane]]--;
        docking++;
    }

    cout << docking << endl;
    return 0;
}