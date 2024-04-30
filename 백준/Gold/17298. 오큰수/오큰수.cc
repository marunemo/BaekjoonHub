#include <iostream>

using namespace std;

int arr_size;
int arr[1000000];
int next_max[1000000];
int nge[1000000];

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> arr_size;
    for(int i = 0; i < arr_size; i++)
        cin >> arr[i];
    
    next_max[arr_size - 1] = -1;
    nge[arr_size - 1] = -1;
    for(int i = arr_size - 2; i >= 0; i--) {
        int index = i + 1;
        while(index != -1 && arr[i] >= arr[index])
            index = next_max[index];
        next_max[i] = index;
        if(index == -1)
            nge[i] = index;
        else
            nge[i] = arr[index];
    }

    for(int i = 0; i < arr_size; i++)
        cout << nge[i] << ' ';
    cout << endl;
    return 0;
}