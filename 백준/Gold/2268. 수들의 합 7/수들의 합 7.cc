#include <iostream>

using namespace std;
using ll = long long;

ll seg_tree[1 << 21] = {0};

ll QueryTree(int start, int end, int node, const int &left, const int &right) {
    if(left <= start && end <= right) {
        return seg_tree[node];
    }

    if(end < left || right < start) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    return QueryTree(start, mid, node * 2, left, right) + QueryTree(mid + 1, end, node * 2 + 1, left, right);
}

ll UpdateTree(int start, int end, int node, const int &index, const int &value) {
    if(end < index || index < start) {
        return seg_tree[node];
    }
    
    if(start == end) {
        return seg_tree[node] = value;
    }

    int mid = start + (end - start) / 2;
    return seg_tree[node] = UpdateTree(start, mid, node * 2, index, value) + UpdateTree(mid + 1, end, node * 2 + 1, index, value);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    int query, i, j;

    cin >> n >> m;
    while(m--) {
        cin >> query >> i >> j;

        if(query) {
            UpdateTree(1, n, 1, i, j);
        }
        else {
            if(i > j) {
                i ^= j ^= i ^= j;
            }
            cout << QueryTree(1, n, 1, i, j) << '\n';
        }
    }
    return 0;
}