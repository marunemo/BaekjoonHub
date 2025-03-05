#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    int height, height_count;
    stack<pii> monoton;
    long long pair_count = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> height;
        height_count = 1;
        
        while(!monoton.empty() && monoton.top().first <= height) {
            pair_count += monoton.top().second;
            if(monoton.top().first == height) {
                height_count += monoton.top().second;
            }
            monoton.pop();
        }

        pair_count += !monoton.empty();

        monoton.push({height, height_count});
    }

    cout << pair_count << endl;
    return 0;
}