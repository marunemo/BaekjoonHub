#include <iostream>
#include <stack>

using namespace std;
using ll = long long;
using Bin = pair<int, ll>;

// Bin = {index, height}
stack<Bin> bins;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int bin_count;
    ll bin_height;
    ll max_area;
    ll width, height;

    cin >> bin_count;
    while(bin_count) {
        max_area = 0;

        for(int idx = 0; idx < bin_count; idx++) {
            cin >> bin_height;
            
            while(!bins.empty() && bins.top().second > bin_height) {
                width = idx;
                height = bins.top().second;
                bins.pop();

                // 만약 bins가 empty라면, 이전까지의 bins는 모두 현재 bin보다 height가 큼이 guarantee됨
                if(!bins.empty()) {
                    width = idx - bins.top().first - 1;
                }

                max_area = max(max_area, width * height);
            }
            
            bins.push({idx, bin_height});
        }
        
        while(!bins.empty()) {
            width = bin_count;
            height = bins.top().second;
            bins.pop();

            if(!bins.empty()) {
                width = width - bins.top().first - 1;
            }

            max_area = max(max_area, width * height);
        }

        cout << max_area << '\n';

        cin >> bin_count;
    }
    return 0;
}