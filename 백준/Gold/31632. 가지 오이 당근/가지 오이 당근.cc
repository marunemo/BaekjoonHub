#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    // Fast I/O
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc, length;
    string god;
    string wdl;
    unordered_map<char, int> god_count;
    unordered_map<char, int> wdl_count;
    unordered_map<char, char> wdl_god;
    bool flag;

    cin >> tc;
    while(tc--) {
        cin >> length >> god >> wdl;

        god_count.clear();
        wdl_count.clear();
        wdl_god.clear();

        // 각 채소에 대한 승패자 수 확인
        for(int i = 0; i < length; i++) {
            god_count[god[i]]++;
            wdl_count[wdl[i]]++;
            if(god[i] != '?' && wdl[i] == 'W')
                wdl_god['W'] = god[i];
            else if(god[i] != '?' && wdl[i] == 'L')
                wdl_god['L'] = god[i];
        }

        // 모든 키위새가 비기지 않는 경우
        if(wdl_count['D'] != 0 && wdl_count['D'] != length) {
            cout << "NO\n";
            continue;
        }

        // 모든 키위새가 이긴 경우
        if(wdl_count['W'] == length) {
            cout << "NO\n";
            continue;
        }

        // 모든 키위새가 진 경우
        if(wdl_count['L'] == length) {
            cout << "NO\n";
            continue;
        }
        
        // 모든 키위새가 비긴 경우
        if(wdl_count['D'] == length) {
            // 모든 채소가 드러난 경우
            if(god_count['G'] && god_count['O'] && god_count['D'])
                wdl_god['D'] = 'G';
            // 채소 중 2가지만 드러난 경우
            else if(god_count['G'] && god_count['O'])
                wdl_god['D'] = 'D';
            else if(god_count['O'] && god_count['D'])
                wdl_god['D'] = 'G';
            else if(god_count['G'] && god_count['D'])
                wdl_god['D'] = 'O';
            // 채소 중 1가지만 드러난 경우
            else if(god_count['G'])
                wdl_god['D'] = 'G';
            else if(god_count['O'])
                wdl_god['D'] = 'O';
            else if(god_count['D'])
                wdl_god['D'] = 'D';
            // 채소 모두가 ? 인 경우
            else
                wdl_god['D'] = 'G';
        }
        // 키위새 중 승자와 패자가 나뉜 경우
        else {
            if(wdl_god['W'] && wdl_god['L']) {
                if(wdl_god['W'] == 'G' && wdl_god['L'] == 'O');
                else if(wdl_god['W'] == 'O' && wdl_god['L'] == 'D');
                else if(wdl_god['W'] == 'D' && wdl_god['L'] == 'G');
                else {
                    cout << "NO\n";
                    continue;
                }
            }
            else if(wdl_god['W']) {
                if(wdl_god['W'] == 'G')
                    wdl_god['L'] = 'O';
                else if(wdl_god['W'] == 'O')
                    wdl_god['L'] = 'D';
                else if(wdl_god['W'] == 'D')
                    wdl_god['L'] = 'G';
            }
            else if(wdl_god['L']) {
                if(wdl_god['L'] == 'G')
                    wdl_god['W'] = 'D';
                else if(wdl_god['L'] == 'O')
                    wdl_god['W'] = 'G';
                else if(wdl_god['L'] == 'D')
                    wdl_god['W'] = 'O';
            }
            else {
                wdl_god['W'] = 'G';
                wdl_god['L'] = 'O';
            }

            // 모든 승패가 맞아 떨어지는 지 확인
            flag = true;
            for(int i = 0; i < length && flag; i++) {
                if(god[i] != '?' && wdl_god[wdl[i]] != god[i])
                    flag = false;
            }

            // 만약 승패가 일관되지 않다면 NO 출력
            if(!flag) {
                cout << "NO\n";
                continue;
            }
        }

        // 모든 조건 만족 시 결과 출력
        cout << "YES\n";
        for(int i = 0; i < length; i++) {
            if(god[i] != '?')
                cout << god[i];
            else
                cout << wdl_god[wdl[i]];
        }
        cout << '\n';
    }
    return 0;
}