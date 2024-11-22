#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int UnionFind(vector<int> &parent, int node) {
    if(node == parent[node])
        return node;
    return parent[node] = UnionFind(parent, parent[node]);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int crain_count, box_count;
    vector<int> crain, box, next_box, pick;
    int move_count = 0, time = 0;

    cin >> crain_count;
    crain.resize(crain_count + 1);
    for(int i = 1; i <= crain_count; i++)
        cin >> crain[i];
    sort(crain.begin() + 1, crain.end(), greater<int>());
    
    cin >> box_count;
    box.resize(box_count + 1);
    for(int i = 1; i <= box_count; i++)
        cin >> box[i];
    sort(box.begin(), box.end(), less<int>());
    
    next_box.resize(box_count + 1);
    for(int i = 1; i <= box_count; i++)
        next_box[i] = i;
    
    pick.resize(crain_count + 1);
    for(int i = 1, j = box_count; i <= crain_count; i++) {
        while(j > 0 && box[j] > crain[i])
            j--;
        pick[i] = j;
    }

    if(crain[1] < box.back()) {
        cout << -1 << endl;
        return 0;
    }

    for(; pick[1] = UnionFind(next_box, pick[1]); time++) {
        for(int i = 1; i <= crain_count; i++) {
            pick[i] = UnionFind(next_box, pick[i]);
            if(pick[i]) {
                move_count++;
                next_box[pick[i]]--;
            }
        }
    }

    cout << time << endl;
    return 0;
}