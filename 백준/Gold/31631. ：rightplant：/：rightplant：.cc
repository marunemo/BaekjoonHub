#include <iostream>

using namespace std;

int building_count;
int building[5001];

void BuildUp(int count) {
    for(int i = 1; i <= count; i++)
        building[i]++;
}

void RightShift(int from, int to) {
    int value;
    for(int i = from; i <= to; i++) {
        value = building[i + 1];
        building[i + 1] = building[from];
        building[from] = value;
    }
}

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    int index;

    cin >> n;
    for(int i = 0; i < n; i++) {
        index = i % 4;
        
        BuildUp(i);
        switch(index) {
            case 1:
                RightShift((i - 1) / 2 + 1, i);
                building[(i - 1) / 2 + 1] = 1;
                break;
            case 0:
            case 2:
                RightShift(i / 2 + 1, i);
                building[i / 2 + 1] = 1;
                break;
            case 3:
                RightShift((i - 1) / 2 + 2, i);
                building[(i - 1) / 2 + 2] = 1;
                break;
        }
    }

    for(int i = 1; i <= n; i++)
        cout << building[i] << ' ';
    cout << '\n';
    return 0;
}