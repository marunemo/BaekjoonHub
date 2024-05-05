#include <iostream>
#include <algorithm>
#define INF 9876543210

using namespace std;
using ll = long long;

ll weight[100000];
pair<ll, int> weight_index[100000];
int sorted_index[100000];
bool visited[100000] = {0};

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int weight_count;
    ll global_min;
    int index, cycle_node;
    ll min_weight;
    ll local_min_cycle, global_min_cycle;
    ll total_weight = 0;

    cin >> weight_count;
    for(int i = 0; i < weight_count; i++) {
        cin >> weight[i];
        weight_index[i] = {weight[i], i};
    }
    sort(weight_index, weight_index + weight_count);
    global_min = weight_index[0].first;

    for(int i = 0; i < weight_count; i++)
        sorted_index[weight_index[i].second] = i;
    
    for(int i = 0; i < weight_count; i++) {
        if(sorted_index[i] == i)
            continue;
        
        if(visited[i])
            continue;
        
        index = i;
        cycle_node = 0;
        min_weight = INF;

        local_min_cycle = 0;
        while(!visited[index]) {
            visited[index] = true;
            cycle_node++;
            min_weight = min(min_weight, weight[index]);
            local_min_cycle += weight[index];
            index = sorted_index[index];
        }

        // 가장 작은 무게와 교환 + 가장 작은 무게로 cycle 순회 + 가장 작은 무게로 교환한 횟수
        global_min_cycle = 2 * (global_min + min_weight) + (local_min_cycle - min_weight) + global_min * (cycle_node - 1);
        // local minimum으로 순회 + local minimum으로 교환한 횟수
        local_min_cycle = (local_min_cycle - min_weight) + min_weight * (cycle_node - 1);

        total_weight += min(local_min_cycle, global_min_cycle);
    }
    cout << total_weight << endl;
    return 0;
}