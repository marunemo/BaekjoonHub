#include <iostream>
#include <queue>

using namespace std;

vector<int> sequence;
vector<int> dependency;
vector<vector<int>> adj_list;

struct Compare {
    bool operator()(int a, int b) {
        return sequence[a] > sequence[b];
    }
};

priority_queue<int, vector<int>, Compare> order;

int GCD(int a, int b) {
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int main() {
    int seq_size;
    int top;

    cin >> seq_size;

    sequence = vector<int>(seq_size);
    dependency = vector<int>(seq_size);
    adj_list = vector<vector<int>>(seq_size, vector<int>());

    for(int i = 0; i < seq_size; i++) {
        cin >> sequence[i];
        for(int j = 0; j < i; j++) {
            if(GCD(sequence[j], sequence[i]) != 1) {
                dependency[i]++;
                adj_list[j].push_back(i);
            }
        }
    }

    for(int i = 0; i < seq_size; i++) {
        if(dependency[i] == 0)
            order.push(i);
    }

    while(!order.empty()) {
        top = order.top();
        order.pop();

        cout << sequence[top] << ' ';
        for(auto next: adj_list[top]) {
            dependency[next]--;
            if(dependency[next] == 0)
                order.push(next);
        }
    }

    cout << endl;
    return 0;
}