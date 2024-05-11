#include <iostream>
#include <vector>

using namespace std;

int main() {
    int line_count;
    int line;
    vector<int> lis;
    int left, right, mid;

    cin >> line_count;
    while(line_count--) {
        cin >> line;

        if(lis.empty())
            lis.push_back(line);
        else if(lis.back() < line)
            lis.push_back(line);
        else {
            left = 0;
            right = lis.size() - 1;
            while(left < right) {
                mid = (left + right) / 2;
                if(lis[mid] < line)
                    left = mid + 1;
                else
                    right = mid;
            }
            lis[right] = line;
        }
    }

    cout << lis.size() << endl;
    return 0;
}