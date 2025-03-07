#include <iostream>

using namespace std;

int index_map[1000001];
int seg_tree[1 << 20];

int QueryTree(int start, int end, int node, const int &left, const int &right) {
    if(left <= start && end <= right) {
        return seg_tree[node];
    }

    if(right < start || end < left) {
        return 0;
    }

    // (start + end) / 2 대신 사용하면 overflow를 방지할 수 있음
    int mid = start + (end - start) / 2;

    return QueryTree(start, mid, node * 2, left, right) + QueryTree(mid + 1, end, node * 2 + 1, left, right);
}

int UpdateTree(int start, int end, int node, const int &index) {
    if(index < start || end < index) {
        return seg_tree[node];
    }

    if(start == end) {
        return ++seg_tree[node];
    }

    int mid = start + (end - start) / 2;
    
    return seg_tree[node] = UpdateTree(start, mid, node * 2, index) + UpdateTree(mid + 1, end, node * 2 + 1, index);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, number;
    long long pair_count = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> number;
        
        index_map[number] = i;
    }

    for(int i = 1; i <= n; i++) {
        cin >> number;

        pair_count += QueryTree(1, n, 1, index_map[number] + 1, n);
        UpdateTree(1, n, 1, index_map[number]);
    }

    cout << pair_count << endl;
    return 0;
}