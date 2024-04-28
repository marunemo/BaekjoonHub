#include <iostream>
#include <queue>

using namespace std;

int people_count;
vector<vector<int>> adj_list;
vector<int> near_believer;
vector<int> believe_time;
queue<int> propagation;
queue<int> next_phase;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int near;
    int init_count, init;
    int top;
    int time = 1;

    cin >> people_count;

    adj_list = vector<vector<int>>(people_count + 1, vector<int>());
    for(int i = 1; i <= people_count; i++) {
        cin >> near;
        while(near) {
            adj_list[i].push_back(near);
            cin >> near;
        }
    }

    cin >> init_count;
    near_believer = vector<int>(people_count + 1, 0);
    believe_time = vector<int>(people_count + 1, -1);
    while(init_count--) {
        cin >> init;
        believe_time[init] = 0;
        propagation.push(init);
    }

    while(!propagation.empty()) {
        top = propagation.front();
        propagation.pop();

        for(auto near: adj_list[top]) {
            if(believe_time[near] == -1) {
                near_believer[near]++;
                if(near_believer[near] * 2 >= adj_list[near].size()) {
                    believe_time[near] = time;
                    next_phase.push(near);
                }
            }
        }

        if(propagation.empty()) {
            propagation = next_phase;
            next_phase = queue<int>();
            time++;
        }
    }

    for(int i = 1; i <= people_count; i++)
        cout << believe_time[i] << ' ';
    cout << endl;
    return 0;
}