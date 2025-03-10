#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sequence;
vector<int> xor_tree;
vector<int> lazy;

int CreateTree(int start, int end, int node) {
    if(start == end) {
        return xor_tree[node] = sequence[start];
    }

    int mid = start + (end - start) / 2;
    int left_node = CreateTree(start, mid, node * 2);
    int right_node = CreateTree(mid + 1, end, node * 2 + 1);
    return xor_tree[node] = left_node ^ right_node;
}

bool LazyCheck(int start, int end, int node) {
    if(!lazy[node]) {
        return false;
    }

    if(end - start + 1) {
        xor_tree[node] ^= lazy[node];
    }

    if(start != end) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }

    lazy[node] = 0;
    return true;
}

int QueryTree(int start, int end, int node, int left, int right) {
    LazyCheck(start, end, node);

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

void UpdateTree(int start, int end, int node, int left, int right, int c) {
    LazyCheck(start, end, node);
    
    if(left <= start && end <= right) {
        lazy[node] ^= c;
        return;
    }

    if(end < left || right < start) {
        return;
    }

    int mid = start + (end - start) / 2;
    UpdateTree(start, mid, node * 2, left, right, c);
    UpdateTree(mid + 1, end, node * 2 + 1, left, right, c);
    xor_tree[node] = xor_tree[node * 2] ^ xor_tree[node * 2 + 1];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int seq_length, query_count;
    int height;
    int query, a, b, c;

    cin >> seq_length;
    sequence.resize(seq_length + 1);
    for(int i = 1; i <= seq_length; i++) {
        cin >> sequence[i];
    }

    height = ceil(log2(seq_length));
    xor_tree.resize(1 << (1 + height));
    lazy.resize(1 << (1 + height));

    CreateTree(1, seq_length, 1);

    cin >> query_count;
    while(query_count--) {
        cin >> query;

        if(query == 1) {
            cin >> a >> b >> c;
            UpdateTree(1, seq_length, 1, a + 1, b + 1, c);
        }
        else if(query == 2) {
            cin >> a;
            cout << QueryTree(1, seq_length, 1, a + 1, a + 1) << '\n';
        }
    }
    return 0;
}