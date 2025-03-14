#include <iostream>
#include <stack>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll prefix_sum[100001];
stack<pii> monotone;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, item;
    ll width, height;
    ll max_answer = 0;
    
    cin >> n;
    monotone.push({0, 0});
    for(int i = 1; i <= n; i++) {
        cin >> item;

        prefix_sum[i] = prefix_sum[i - 1] + item;

        while(!monotone.empty() && monotone.top().first > item) {
            height = monotone.top().first;
            width = prefix_sum[i - 1];
            monotone.pop();

            if(!monotone.empty()) {
                width = width - prefix_sum[monotone.top().second];
            }

            max_answer = max(max_answer, width * height);
        }
        
        monotone.push({item, i});
    }

    while(!monotone.empty()) {
        height = monotone.top().first;
        width = prefix_sum[n];
        monotone.pop();

        if(!monotone.empty()) {
            width = width - prefix_sum[monotone.top().second];
        }

        max_answer = max(max_answer, width * height);
    }

    cout << max_answer << endl;
    return 0;
}