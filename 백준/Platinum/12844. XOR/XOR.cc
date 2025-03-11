#include <iostream>

using namespace std;

int seq[500000];
int xor_tree[1 << 20];
int lazy[1 << 20];

int CreateTree(int start, int end, int node) {
    if(start == end) {
        return xor_tree[node] = seq[start];
    }

    int mid = start + (end - start) / 2;
    int left_node = CreateTree(start, mid, node * 2);
    int right_node = CreateTree(mid + 1, end, node * 2 + 1);
    return xor_tree[node] = left_node ^ right_node;
}

void CheckLazy(int start, int end, int node) {
    if(!lazy[node]) {
        return;
    }

    if((end - start + 1) & 1) {
        xor_tree[node] ^= lazy[node];
    }

    if(start != end) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    
    lazy[node] = 0;
}

int UpdateTree(int start, int end, int node, const int &left, const int &right, const int &k) {
    CheckLazy(start, end, node);
    
    if(left <= start && end <= right) {
        lazy[node] ^= k;
        CheckLazy(start, end, node);
        return xor_tree[node];
    }
    
    if(end < left || right < start) {
        return xor_tree[node];
    }

    int mid = start + (end - start) / 2;
    int left_node = UpdateTree(start, mid, node * 2, left, right, k);
    int right_node = UpdateTree(mid + 1, end, node * 2 + 1, left, right, k);
    return xor_tree[node] = left_node ^ right_node;
}

int QueryTree(int start, int end, int node, const int &left, const int &right) {
    CheckLazy(start, end, node);
    
    if(left <= start && end <= right) {
        return xor_tree[node];
    }

    if(end < left || right < start) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int left_node = QueryTree(start, mid, node * 2, left, right);
    int right_node = QueryTree(mid + 1, end, node * 2 + 1, left, right);
    return left_node ^ right_node;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    int height;
    int query, a, b, c;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> seq[i];
    }
    CreateTree(1, n, 1);

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> query;

        if(query == 1) {
            cin >> a >> b >> c;
            UpdateTree(1, n, 1, a + 1, b + 1, c);
        }
        else if(query == 2) {
            cin >> a >> b;
            cout << QueryTree(1, n, 1, a + 1, b + 1) << '\n';
        }
    }

    return 0;
}