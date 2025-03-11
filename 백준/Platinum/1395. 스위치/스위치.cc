#include <iostream>

using namespace std;

int seg_tree[1 << 18];
bool lazy[1 << 18];

void CheckLazy(int start, int end, int node) {
    if(!lazy[node]) {
        return;
    }

    seg_tree[node] = (end - start + 1) - seg_tree[node];

    if(start != end) {
        lazy[node * 2] = lazy[node * 2] ^ lazy[node];
        lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ lazy[node];
    }

    lazy[node] = false;
}

int UpdateTree(int start, int end, int node, const int &left, const int &right) {
    CheckLazy(start, end, node);
    
    if(left <= start && end <= right) {
        lazy[node] = !lazy[node];
        CheckLazy(start, end, node);
    }
    else if(left <= end && start <= right) {
        int mid = start + (end - start) / 2;
        int left_node = UpdateTree(start, mid, node * 2, left, right);
        int right_node = UpdateTree(mid + 1, end, node * 2 + 1, left, right);
        seg_tree[node] = left_node + right_node;
    }

    return seg_tree[node];
}

int QueryTree(int start, int end, int node, const int &left, const int &right) {
    CheckLazy(start, end, node);

    if(left <= start && end <= right) {
        return seg_tree[node];
    }

    if(end < left || right < start) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int left_node = QueryTree(start, mid, node * 2, left, right);
    int right_node = QueryTree(mid + 1, end, node * 2 + 1, left, right);
    return left_node + right_node;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int height;
    int query, s, t;

    cin >> n >> m;
    while(m--) {
        cin >> query >> s >> t;

        if(query == 0) {
            UpdateTree(1, n, 1, s, t);
        }
        else {
            cout << QueryTree(1, n, 1, s, t) << '\n';
        }
    }
}