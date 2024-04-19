#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> group;
vector<int> candy;
vector<int> group_kids;

unordered_map<int, bool> group_check;
vector<vector<int>> knapsack;

int UnionFind(int node) {
    if(group[node] == node)
        return node;
    return group[node] = UnionFind(group[node]);
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int kid_count, group_count, max_kid;
    int friend_a, friend_b;
    int curr, next;

    cin >> kid_count >> group_count >> max_kid;
    group = vector<int>(kid_count + 1);
    candy = vector<int>(kid_count + 1);
    group_kids = vector<int>(kid_count + 1);
    for(int i = 1; i <= kid_count; i++) {
        group[i] = i;
        cin >> candy[i];
        group_kids[i] = 1;
    }

    while(group_count--) {
        cin >> friend_a >> friend_b;

        if(UnionFind(friend_a) == UnionFind(friend_b))
            continue;
        
        if(group[friend_a] < group[friend_b]) {
            candy[group[friend_a]] += candy[group[friend_b]];
            group_kids[group[friend_a]] += group_kids[group[friend_b]];
            group[group[friend_b]] = group[friend_a];
        }
        else {
            candy[group[friend_b]] += candy[group[friend_a]];
            group_kids[group[friend_b]] += group_kids[group[friend_a]];
            group[group[friend_a]] = group[friend_b];
        }
    }

    knapsack = vector<vector<int>>(max_kid, vector<int>(2, 0));
    curr = 0;
    for(int i = 1; i <= kid_count; i++) {
        if(!group_check[UnionFind(i)]) {
            group_check[group[i]] = true;
            next = 1 - curr;
            
            for(int kid = 0; kid < max_kid; kid++) {
                if(kid < group_kids[group[i]])
                    knapsack[kid][next] = knapsack[kid][curr];
                else
                    knapsack[kid][next] = max(knapsack[kid][curr], knapsack[kid - group_kids[group[i]]][curr] + candy[group[i]]);
            }
            curr = next;
        }
    }

    cout << knapsack[max_kid - 1][curr] << endl;
    return 0;
}