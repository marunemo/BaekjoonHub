#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[100000];
pair<int, int> num_index[100000];
int sorted_index[100000];
bool swapped[100000] = {false};

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int size;
    int curr_index;
    int cycle_node;
    int count = 0;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        num_index[i] = {arr[i], i};
    }
    sort(num_index, num_index + size);
    
    for(int i = 0; i < size; i++)
        sorted_index[num_index[i].second] = i;
    
    for(int i = 0; i < size; i++) {
        if(sorted_index[i] == i)
            continue;
        
        if(swapped[i])
            continue;
        
        curr_index = i;
        cycle_node = 0;
        while(!swapped[curr_index]) {
            swapped[curr_index] = true;
            cycle_node++;
            curr_index = sorted_index[curr_index];
        }

        // (cycle의 노드 개수 - 1)회만 swap하면 됨
        count += cycle_node - 1;
    }

    cout << count << endl;
    return 0;
}