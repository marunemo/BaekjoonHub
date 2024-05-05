#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[100000];
pair<int, int> num_index[100000];
unordered_map<int, int> unordered_index;

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int size;
    int curr_index;
    int count = 0;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        num_index[i] = {arr[i], i};
    }
    sort(num_index, num_index + size);
    for(int i = 0; i < size; i++)
        unordered_index[num_index[i].second] = i;

    for(int i = 0; i < size; i++) {
        if(arr[i] == num_index[i].first)
            continue;
        
        count++;

        curr_index = num_index[i].second;
        Swap(arr[i], arr[curr_index]);
        num_index[unordered_index[i]].second = curr_index;
        num_index[i].second = i;

        unordered_index[curr_index] = unordered_index[i];
        unordered_index[i] = i;
    }

    cout << count << endl;
    return 0;
}