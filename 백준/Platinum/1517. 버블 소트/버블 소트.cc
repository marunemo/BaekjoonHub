#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> seq[500000];
int seg_tree[1 << 20];

int UpdateTree(int start, int end, int node, const int &index, const int &value) {
    if(index < start || end < index) {
        return seg_tree[node];
    }
    
    if(start == end) {
        seg_tree[node] += value;
        return seg_tree[node];
    }

    int mid = start + (end - start) / 2;
    return seg_tree[node] = UpdateTree(start, mid, node * 2, index, value) + UpdateTree(mid + 1, end, node * 2 + 1, index, value);
}

int QueryTree(int start, int end, int node, const int &left, const int &right) {
    if(left <= start && end <= right) {
        return seg_tree[node];
    }

    if(end < left || right < start) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    return QueryTree(start, mid, node * 2, left, right) + QueryTree(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    long long answer = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> seq[i].first;
        seq[i].second = i;
    }
    sort(seq, seq + n);
    
    // i와 seq_index[i]를 이은 선분의 교차 횟수가 곧 교환 횟수
    for(int i = 0; i < n; i++) {
        answer += QueryTree(1, n, 1, seq[i].second, n);
        UpdateTree(1, n, 1, seq[i].second, 1);
    }

    cout << answer << endl;
    return 0;
}