#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
// depth & weight
using TreeNode = pair<int, ll>;

int node_count;
int node[262144];
int flatten_idx = 1;
TreeNode flatten[262144];

void InOrder(int node_idx, int depth) {
    if(node_idx > node_count)
        return;
    
    InOrder(node_idx * 2, depth + 1);
    flatten[flatten_idx++] = {depth, node[node_idx]};
    InOrder(node_idx * 2 + 1, depth + 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int height;
    ll sum, max_sum = -1e9;

    cin >> node_count;
    height = log2(node_count + 1);

    for(int i = 1; i <= node_count; i++) {
        cin >> node[i];
        max_sum = max(max_sum, (ll)node[i]);
    }
    InOrder(1, 0);

    if(max_sum < 0) {
        cout << max_sum << endl;
        return 0;
    }

    max_sum = 0;
    for(int top = 0; top < height; top++) {
        for(int bottom = top; bottom < height; bottom++) {
            sum = 0;
            for(int i = 1; i <= node_count; i++) {
                if(flatten[i].first < top || flatten[i].first > bottom)
                    continue;
                
                sum += flatten[i].second;
                if(sum < 0)
                    sum = 0;
                else
                    max_sum = max(sum, max_sum);
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}