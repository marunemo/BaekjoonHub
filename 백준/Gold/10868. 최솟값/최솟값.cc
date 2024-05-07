#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sequence;
vector<int> seg_tree;

int CreateTree(int node, int start, int end) {
    if(start == end)
        return seg_tree[node] = sequence[start];
    return seg_tree[node] = min(CreateTree(node * 2, start, (start + end) / 2), CreateTree(node * 2 + 1, (start + end) / 2 + 1, end));
}

int QueryTree(int node, int start, int end, int left, int right) {
    if(end < left || right < start)
        return 1000000000;
    if(left <= start && end <= right)
        return seg_tree[node];
    return min(QueryTree(node * 2, start, (start + end) / 2, left, right), QueryTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int size, query;
    int height;
    int a, b;
    
    cin >> size >> query;
    sequence = vector<int>(size + 1);
    height = (int)ceil(log2(size)) + 1;
    seg_tree = vector<int>((1 << height) + 1);

    for(int i = 1; i <= size; i++)
        cin >> sequence[i];
    CreateTree(1, 1, size);
    
    while(query--) {
        cin >> a >> b;
        cout << QueryTree(1, 1, size, a, b) << '\n';
    }
    return 0;
}