#include <iostream>
#include <queue>

using namespace std;
using Pos = pair<int, int>;

int cow_count, group_count;
vector<Pos> cow;
vector<vector<int>> adj_list;
vector<int> check;

int GetArea(int init) {
    int left, right, top, bottom;
    queue<int> q;
    int front;

    left = right = cow[init].first;
    top = bottom = cow[init].second;

    check[init] = true;
    q.push(init);
    while(!q.empty()) {
        front = q.front();
        q.pop();

        left = min(left, cow[front].first);
        right = max(right, cow[front].first);
        top = max(top, cow[front].second);
        bottom = min(bottom, cow[front].second);

        for(int next: adj_list[front]) {
            if(!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }

    return 2 * ((right - left) + (top - bottom));
}

int main() {
    int a, b;
    int min_area = 500000000;

    cin >> cow_count >> group_count;
    cow.resize(cow_count + 1);
    adj_list.resize(cow_count + 1);
    for(int i = 1; i <= cow_count; i++)
        cin >> cow[i].first >> cow[i].second;
    for(int i = 0; i < group_count; i++) {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    check.resize(cow_count + 1, false);
    for(int i = 1; i <= cow_count; i++) {
        if(!check[i])
            min_area = min(min_area, GetArea(i));
    }

    cout << min_area << endl;
    return 0;
}