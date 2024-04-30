#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int inorder[100000];
int postorder[100000];
int in_root[100001];

void PreOrder(int in_start, int in_end, int post_start, int post_end) {
    if(in_start > in_end || post_start > post_end)
        return;

    int root = postorder[post_end];
    int range = in_root[root] - in_start;

    cout << root << ' ';
    PreOrder(in_start, in_start + range - 1, post_start, post_start + range - 1);
    PreOrder(in_start + range + 1, in_end, post_start + range, post_end - 1);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int node_count;
    cin >> node_count;

    for(int i = 0; i < node_count; i++) {
        cin >> inorder[i];
        in_root[inorder[i]] = i;
    }

    for(int i = 0; i < node_count; i++)
        cin >> postorder[i];
    
    PreOrder(0, node_count - 1 , 0, node_count - 1);
    return 0;
}