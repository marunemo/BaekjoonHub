#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int line_count;
vector<pii> line;
vector<int> lis;
vector<int> order;
int curr_order;
vector<int> remove_line;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int start, end;
    int left, right, mid;

    cin >> line_count;
    for(int i = 0; i < line_count; i++) {
        cin >> start >> end;
        line.push_back({start, end});
    }
    sort(line.begin(), line.end());

    order = vector<int>(line_count);
    lis.push_back(line[0].second);
    order[0] = 0;
    for(int i = 1; i < line_count; i++) {
        end = line[i].second;

        if(lis.back() < end) {
            order[i] = lis.size();
            lis.push_back(end);
        }
        else {
            left = 0;
            right = lis.size() - 1;
            while(left < right) {
                mid = (left + right) / 2;
                if(lis[mid] <= end)
                    left = mid + 1;
                else
                    right = mid;
            }
            lis[right] = end;
            order[i] = right;
        }
    }

    curr_order = lis.size() - 1;
    for(int i = line_count - 1; i >= 0; i--) {
        if(order[i] == curr_order)
            curr_order--;
        else
            remove_line.push_back(line[i].first);
    }
    sort(remove_line.begin(), remove_line.end());

    cout << (line_count - lis.size()) << '\n';
    for(auto rm: remove_line)
        cout << rm << '\n';
    return 0;
}