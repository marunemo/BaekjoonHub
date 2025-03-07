#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, int> index_map;
vector<int> seg_tree;

int QueryTree(int start, int end, const int &left, const int &right, int node = 1) {
    if(left <= start && end <= right) {
        return seg_tree[node];
    }

    if(right < start || end < left) {
        return 0;
    }

    int left_node = QueryTree(start, (start + end) / 2, left, right, node * 2);
    int right_node = QueryTree((start + end) / 2 + 1, end, left, right, node * 2 + 1);
    return left_node + right_node;
}

int UpdateTree(int start, int end, const int &index, int node = 1) {
    if(index < start || end < index) {
        return seg_tree[node];
    }

    if(start == end) {
        return ++seg_tree[node];
    }

    int left_node = UpdateTree(start, (start + end) / 2, index, node * 2);
    int right_node = UpdateTree((start + end) / 2 + 1, end, index, node * 2 + 1);
    return seg_tree[node] = left_node + right_node;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, key;
    int height;
    long long pair_count = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> key;
        
        index_map[key] = i;
    }
    
    height = ceil(log2(n));
    seg_tree.resize(1 << (1 + height), 0);

    for(int i = 1; i <= n; i++) {
        cin >> key;

        pair_count += QueryTree(1, n, index_map[key], n);
        UpdateTree(1, n, index_map[key]);
    }

    cout << pair_count << endl;
    return 0;
}