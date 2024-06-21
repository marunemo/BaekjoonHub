#include <iostream>

using namespace std;

int fruit[200000];

int main() {
    int n;
    pair<int, int> type[2] = {{0, 0}, {0, 0}};
    int len = 0;
    int max_len = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> fruit[i];

        if(type[0].first == fruit[i])
            type[0] = {fruit[i], i};
        else if(type[1].first == fruit[i])
            type[1] = {fruit[i], i};
        else {
            if(type[0].first == 0)
                type[0] = {fruit[i], i};
            else if(type[1].first == 0)
                type[1] = {fruit[i], i};
            else {
                if(type[0].second < type[1].second) {
                    len = (i - type[0].second - 1);
                    type[0] = {fruit[i], i};
                }
                else {
                    len = (i - type[1].second - 1);
                    type[1] = {fruit[i], i};
                }
            }
        }
        max_len = max(++len, max_len);
    }

    cout << max_len << endl;
    return 0;
}