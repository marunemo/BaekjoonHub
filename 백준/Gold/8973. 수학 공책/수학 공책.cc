#include <iostream>

using namespace std;

int len;
int arr[2000], rev[2000];
int hazy[2000][2000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int b, e, max_hazy = -2000000000;

    cin >> len;
    for(int i = 0; i < len; i++)
        cin >> arr[i];
    for(int i = 0; i < len; i++)
        cin >> rev[i];
    
    for(int i = 0; i < len; i++) {
        hazy[i][i] = arr[i] * rev[i];
        if(i > 0)
            hazy[i - 1][i] = arr[i - 1] * rev[i] + arr[i] * rev[i - 1];
    }

    for(int l = 2; l < len; l++) {
        for(int start = 0; start < len - l; start++)
            hazy[start][start + l] = hazy[start + 1][start + l - 1] + arr[start + l] * rev[start] + arr[start] * rev[start + l];
    }

    for(int start = 0; start < len; start++) {
        for(int end = start; end < len; end++) {
            if(hazy[start][end] > max_hazy) {
                max_hazy = hazy[start][end];
                b = start;
                e = len - 1 - end;
            }
        }
    }

    cout << b << ' ' << e << '\n' << max_hazy << '\n';
    return 0;
}