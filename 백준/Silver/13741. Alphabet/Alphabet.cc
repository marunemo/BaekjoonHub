#include <iostream>

using namespace std;

int main() {
    char str[51];
    int lis[50];
    int lis_index = 0;
    int left, right, mid;

    cin >> str;
    for(int i = 0; str[i]; i++) {
        if(!lis_index)
            lis[lis_index++] = str[i];
        else if(lis[lis_index - 1] < str[i])
            lis[lis_index++] = str[i];
        else {
            left = 0;
            right = lis_index - 1;
            while(left < right) {
                mid = (left + right) / 2;

                if(lis[mid] < str[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            lis[right] = str[i];
        }
    }

    cout << 26 - lis_index << endl;
    return 0;
}