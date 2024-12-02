#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int tc;
    string name;
    int count, len, min_dist;

    cin >> tc;
    while(tc--) {
        cin >> name;

        count = 0;
        len = name.length();
        for(int i = 0; i < len; i++)
            count += min(name[i] - 'A', ('Z' - name[i]) + 1);
        
        min_dist = len - 1;
        for(int i, left, right, dist, start = 0; start < len; start++) {
            for(i = start + 1; i < len && name[i] == 'A'; i++);
            
            // 오른쪽으로 갔다가 왼쪽 (오른쪽 왕복 이후 왼쪽 A 없는 끝까지)
            right = start * 2 + (len - i);

            // 왼쪽으로 갔다가 오른쪽
            left = (len - i) * 2 + start;

            dist = min(left, right);
            min_dist = min(min_dist, dist);
        }
        
        cout << (count + min_dist) << '\n';
    }
    return 0;
}