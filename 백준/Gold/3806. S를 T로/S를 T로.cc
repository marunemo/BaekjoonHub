#include <iostream>
#include <string>
#include <queue>

using namespace std;

int CalcCount(string s, string t) {
    int s_one_count = 0;
    int t_one_count = 0;
    int q_mark_count = 0;
    int wrong_one = 0;
    int wrong_zero = 0;
    int count = 0;
    int len = s.length();

    for(char c: s) {
        s_one_count += (c == '1');
        q_mark_count += (c == '?');
    }
    for(char c: t)
        t_one_count += (c == '1');
    
    // 1 → 0에 대한 연산은 없으므로, s가 t보다 1이 더 많으면 불가능
    if(s_one_count > t_one_count)
        return -1;
    
    // ?는 모두 0이나 1로 치환되어야만 함
    count += q_mark_count;

    // s가 각각 0과 1일 때, t가 각각 1과 0인 경우 확인
    for(int i = 0; i < len; i++) {
        if(s[i] != t[i]) {
            wrong_one += s[i] == '1';
            wrong_zero += s[i] == '0';
        }
    }

    // 잘못된 위치끼리 교체
    count += min(wrong_one, wrong_zero);
    // 남은 경우는 ?와 교체하거나 0에서 1로 변경
    count += abs(wrong_one - wrong_zero);

    return count;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    string s, t;

    cin >> tc;
    for(int i = 1; i <= tc; i++) {
        cin >> s >> t;
        cout << "Case " << i << ": " << CalcCount(s, t) << '\n';
    }
}