#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, build_count, build_order;
    vector<int> build_time;
    int pre, next;
    vector<int> pre_build;
    vector<vector<int>> next_build;
    vector<int> total_build_time;
    queue<int> order;
    int top;
    int target_buliding;

    cin >> tc;
    while(tc--) {
        cin >> build_count >> build_order;
        
        build_time = vector<int>(build_count + 1);
        for(int i = 1; i <= build_count; i++)
            cin >> build_time[i];
        
        pre_build = vector<int>(build_count + 1);
        next_build = vector<vector<int>>(build_count + 1, vector<int>());
        for(int i = 0; i < build_order; i++) {
            cin >> pre >> next;
            pre_build[next]++;
            next_build[pre].push_back(next);
        }

        total_build_time = vector<int>(build_count + 1, 0);
        order = queue<int>();
        for(int i = 1; i <= build_count; i++) {
            if(!pre_build[i]) {
                total_build_time[i] = build_time[i];
                order.push(i);
            }
        }

        while(!order.empty()) {
            top = order.front();
            order.pop();

            for(auto next: next_build[top]) {
                total_build_time[next] = max(total_build_time[next], total_build_time[top] + build_time[next]);

                pre_build[next]--;
                if(!pre_build[next])
                    order.push(next);
            }
        }

        cin >> target_buliding;
        cout << total_build_time[target_buliding] << '\n';
    }
    return 0;
}