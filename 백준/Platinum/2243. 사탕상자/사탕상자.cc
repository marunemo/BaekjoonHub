#include <iostream>
#include <cmath>

using namespace std;

int seg_tree[1 << 21] = {0};

void Query(int node, int start, int end, int idx) {
    if(start == end) {
        seg_tree[node]--;
        cout << start << '\n';
        return;
    }
    
    if(idx <= seg_tree[node * 2])
        Query(node * 2, start, (start + end) / 2, idx);
    else
        Query(node * 2 + 1, (start + end) / 2 + 1, end, idx - seg_tree[node * 2]);
    seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

void Update(int node, int start, int end, int idx, int value) {
    if(idx < start || end < idx)
        return;

    if(start == end) {
        seg_tree[node] += value;
        return;
    }
    
    Update(node * 2, start, (start + end) / 2, idx, value);
    Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, value);
    seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int query_count, query, idx, value;

    cin >> query_count;
    while(query_count--) {
        cin >> query;
        if(query == 1) {
            cin >> idx;
            Query(1, 1, 1000000, idx);
        }
        else if(query == 2) {
            cin >> idx >> value;
            Update(1, 1, 1000000, idx, value);
        };
    }
    return 0;
}