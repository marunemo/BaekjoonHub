#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int count;
    string category;
    int mask;
    unordered_map<int, bool> map;

    while(cin >> tc) {
        map.clear();
        count = 0;
        while(tc--) {
            cin >> category;

            mask = 0;
            for(char type: category)
                mask |= (1 << (type - '0'));
            
            if(!map[mask]) {
                map[mask] = true;
                count++;
            }
        }

        cout << count << '\n';
    }
    return 0;
}