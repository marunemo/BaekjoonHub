#include <iostream>

using namespace std;
using pii = pair<int, int>;

int parent[100001];
int p_count = 1;
pii range[100001];
int prefix_sum[100001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    int left, right;
    int curr, next;
    long long len = 0;

    cin >> n >> k;
    
    cin >> left >> right;
    parent[1] = p_count;
    range[p_count] = {left, right};
    for(int i = 2; i <= n; i++) {
        cin >> left >> right;

        if(range[p_count].second < left)
            range[++p_count] = {left, right};
        else {
            range[p_count].first = min(range[p_count].first, left);
            range[p_count].second = max(range[p_count].second, right);
        }
        parent[i] = p_count;
    }

    for(int i = 2; i <= p_count; i++)
        prefix_sum[i] = prefix_sum[i - 1] + (range[i].first - range[i - 1].second);
    
    curr = 1;
    for(int i = 0; i < k; i++) {
        cin >> next;
        next = parent[next];

        len += (long long)abs(prefix_sum[next] - prefix_sum[curr]);
        curr = next;
    }
    cout << len << endl;
    return 0;
}