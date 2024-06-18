#include <iostream>

using namespace std;

int card[20];

void Flip(int a, int b) {
    int tmp;

    a--;
    b--;
    for(int i = 0; i <= (b - a) / 2; i++) {
        tmp = card[a + i];
        card[a + i] = card[b - i];
        card[b - i] = tmp;
    }
}

int main() {
    int a, b;

    for(int i = 0; i < 20; i++)
        card[i] = (i + 1);

    for(int i = 0; i < 10; i++) {
        cin >> a >> b;
        Flip(a, b);
    }

    for(int i = 0; i < 20; i++)
        cout << card[i] << ' ';
    cout << endl;
    return 0;
}