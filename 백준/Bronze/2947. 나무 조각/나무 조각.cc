#include <iostream>

using namespace std;

// a != b임이 보장
void Swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int arr[5];
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    while(arr[0] != 1 && arr[1] != 2 || arr[2] != 3 || arr[3] != 4) {
        for(int i = 0; i < 4; i++) {
            if(arr[i] > arr[i + 1]) {
                Swap(arr[i], arr[i + 1]);
                for(int j = 0; j < 5; j++) {
                    cout << arr[j] << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}