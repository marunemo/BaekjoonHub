#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

priority_queue<pii, vector<pii>, greater<pii>> heap;
unordered_map<int, bool> check;

int main() {
    int src, dest;
    int time, pos;
    bool flag = false;

    cin >> src >> dest;

    heap.push({0, src});
    while(!heap.empty() && !flag) {
        time = heap.top().first;
        pos = heap.top().second;
        heap.pop();

        if(check[pos])
            continue;
        check[pos] = true;

        flag = pos == dest;

        if(pos > 0 && !check[pos - 1])
            heap.push({time + 1, pos - 1});
        if(pos < dest && !check[pos + 1])
            heap.push({time + 1, pos + 1});
        if(pos < dest && !check[pos * 2])
            heap.push({time, pos * 2});
    }

    cout << time << endl;
    return 0;
}