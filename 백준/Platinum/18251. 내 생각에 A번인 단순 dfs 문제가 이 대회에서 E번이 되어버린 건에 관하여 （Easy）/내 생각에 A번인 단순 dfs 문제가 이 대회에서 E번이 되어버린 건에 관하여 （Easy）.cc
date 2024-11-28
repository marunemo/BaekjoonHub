#include <iostream>
#include <cmath>

using namespace std;

int node_count = 0;
int node[262144] = {0};
int inorder_idx = 1;
int level[262144] = {0};
long long weight[262144] = {0};

void InOrder(int node_idx, int depth) {
    if(node_idx > node_count)
        return;
    
    InOrder(node_idx * 2, depth + 1);

    level[inorder_idx] = depth;
    weight[inorder_idx] = node[node_idx];
    inorder_idx++;

    InOrder(node_idx * 2 + 1, depth + 1);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int height;
    long long sum, max_sum = -1e9;

    cin >> node_count;
    height = log2(node_count + 1);

    for(int i = 1; i <= node_count; i++)
        cin >> node[i];
    InOrder(1, 0);

    for(int top = 0; top < height; top++) {
        for(int bottom = top; bottom < height; bottom++) {
            sum = 0;
            for(int i = 1; i <= node_count; i++) {
                if(level[i] < top || level[i] > bottom)
                    continue;
                
                sum += weight[i];
                max_sum = max(sum, max_sum);
                if(sum < 0)
                    sum = 0;
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}