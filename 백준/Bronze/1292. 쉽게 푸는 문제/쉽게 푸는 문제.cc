#include <iostream>

using namespace std;

int prefix_sum[1001];

int main() {
    int index = 1;
    int start, end;

    prefix_sum[0] = 0;
    for(int i = 1; index <= 1000; i++) {
        for(int j = 0; j < i && index <= 1000; j++) {
            prefix_sum[index] = prefix_sum[index - 1] + i;
            index++;
        }
    }

    cin >> start >> end;
    cout << prefix_sum[end] - prefix_sum[start - 1] << endl;
    return 0;
}