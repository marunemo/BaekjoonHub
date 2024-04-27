#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sequence;
vector<int> seg_tree;
vector<int> start_index;

int CreateSeg(int node, int start, int end) {
    if(start == end)
        return seg_tree[node] = sequence[start];
    return seg_tree[node] = max(CreateSeg(node * 2, start, (start + end) / 2), CreateSeg(node * 2 + 1, (start + end) / 2 + 1, end));
}

int QuerySeg(int node, int start, int end, int left, int right) {
    if(end < left || right < start)
        return 0;
    if(left <= start && end <= right)
        return seg_tree[node];
    return max(QuerySeg(node * 2, start, (start + end) / 2, left, right), QuerySeg(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
    
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int seq_size;
    int height;
    bool flag;

    cin >> tc;
    while(tc--) {
        cin >> seq_size;
        sequence = vector<int>(seq_size + 1);
        for(int i = 1; i <= seq_size; i++)
            cin >> sequence[i];

        height = (int)ceil(log2(seq_size));
        seg_tree = vector<int>((1 << (height + 1)));
        CreateSeg(1, 1, seq_size);

        start_index = vector<int>(seq_size + 1, -1);
        flag = true;
        for(int i = 1; i <= seq_size && flag; i++) {
            if(start_index[sequence[i]] == -1)
                start_index[sequence[i]] = i;
            else if(QuerySeg(1, 1, seq_size, start_index[sequence[i]], i) > sequence[i])
                flag = false;
        }

        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}