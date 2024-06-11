#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#define INF 1000000

using namespace std;
using Node = pair<int, string>;

struct Edge {
    int s, e, w;
};

string ToString(vector<int> const &arr) {
    string result = "";
    for(int num: arr)
        result += to_string(num);
    return result;
}

string Swap(string const &str, int i, int j) {
    string result = str;
    result[i] = str[j];
    result[j] = str[i];
    return result;
}

int main() {
    int size;
    vector<int> arr;
    vector<int> sorted_arr;
    int control_count;
    vector<Edge> control;
    unordered_map<string, int> key;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    string init, result, tmp;
    int min_weight = -1;

    cin >> size;
    arr.resize(size);
    sorted_arr.resize(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        arr[i]--;
        sorted_arr[i] = arr[i];
    }
    sort(sorted_arr.begin(), sorted_arr.end());

    cin >> control_count;
    control.resize(control_count);
    for(int i = 0; i < control_count; i++)
        cin >> control[i].s >> control[i].e >> control[i].w;

    init = ToString(arr);
    result = ToString(sorted_arr);

    pq.push({0, ToString(arr)});
    while(!pq.empty()) {
        auto [weight, order] = pq.top();
        pq.pop();

        if(key[order] < weight)
            continue;

        if(order == result) {
            min_weight = weight;
            break;
        }

        for(int i = 0; i < control_count; i++) {
            tmp = Swap(order, control[i].s - 1, control[i].e - 1);
            if(tmp != init && key[tmp] == 0) {
                key[tmp] = weight + control[i].w;
                pq.push({key[tmp], tmp});
            }
            else if(key[tmp] > weight + control[i].w) {
                key[tmp] = weight + control[i].w;
                pq.push({key[tmp], tmp});
            }
        }
    }

    cout << min_weight << endl;
    return 0;
}