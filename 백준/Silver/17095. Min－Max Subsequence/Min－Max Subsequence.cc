#include <iostream>

using namespace std;

int arr_size;
int arr[100000];

int main() {
    int min_index;
    int max_index;
    int len;

    cin >> arr_size;
    for(int i = 0; i < arr_size; i++)
        cin >> arr[i];
    
    min_index = 0;
    max_index = 0;
    len = arr_size;
    for(int i = 1; i < arr_size; i++) {
        if(arr[i] == arr[min_index])
            min_index = i;
        else if(arr[i] < arr[min_index]) {
            min_index = i;
            len = arr_size;
        }

        if(arr[i] == arr[max_index])
            max_index = i;
        if(arr[i] > arr[max_index]) {
            max_index = i;
            len = arr_size;
        }

        len = min(len, abs(max_index - min_index) + 1);
    }
    cout << len << endl;
    return 0;
}