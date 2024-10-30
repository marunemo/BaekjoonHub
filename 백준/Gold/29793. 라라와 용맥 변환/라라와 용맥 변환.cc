#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    string dragon;

    cin >> n >> m;
    cin >> dragon;

    if(dragon.length() == 1 || m == 1)
        cout << 0 << endl;
    else if(dragon.length() == 2 || m == 2) {
        // 앞 뒤와 동일하지 않은 임의의 원소로 변경(원소가 3개이므로, 항상 1개 이상의 방법이 존재)
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(dragon[i] == dragon[i - 1]) {
                count++;
                dragon[i] = '.';
            }
        }
        cout << count << endl;
    }
    else if(dragon.length() == 3 || m == 3) {
        // 반드시 특정 패턴이 반복되어야 함(경우의 수: 3! = 6)
        const char pattern[6][4] = {"SRW", "SWR", "WSR", "WRS", "RSW", "RWS"};
        int min_count = n;
        for(int p = 0; p < 6; p++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(dragon[i] != pattern[p][i % 3])
                    count++;
            }
            min_count = min(count, min_count);
        }
        cout << min_count << endl;
    }
    else 
        cout << -1 << endl;
    return 0;
}