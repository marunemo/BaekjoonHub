#include <iostream>
#define OFFSET 1000000

using namespace std;

int next_pos[OFFSET * 2 + 1];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int triple_count;
    int i, k;
    char j;
    int pos;

    cin >> triple_count;
    for(int triple = 0; triple < triple_count; triple++) {
        cin >> i >> j >> k;

        if(j == 'L')
            next_pos[i + OFFSET] = (i - k) + OFFSET;
        else
            next_pos[i + OFFSET] = (i + k) + OFFSET;
    }

    cin >> pos;
    pos += OFFSET;
    while(triple_count--)
        pos = next_pos[pos];

    cout << (pos - OFFSET) << endl;
    return 0;
}