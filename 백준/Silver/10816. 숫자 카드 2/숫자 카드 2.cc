#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    unordered_map<int, int> count;
    int n, m;
    int card, query;

    cin >> n;
    while(n--) {
        cin >> card;
        count[card]++;
    }

    cin >> m;
    while(m--) {
        cin >> query;
        cout << count[query] << ' ';
    }
    cout << endl;
    return 0;
}