#include <iostream>

using namespace std;

int main() {
    int n, left, right;

    cin >> n;

    left = 1;
    right = n;
    
    cout << right-- << ' ';
    while(left < right) {
        cout << left << ' ' << right << ' ';
        left++;
        right--;
    }
    if(left == right)
        cout << left;
    
    cout << endl;
    return 0;
}