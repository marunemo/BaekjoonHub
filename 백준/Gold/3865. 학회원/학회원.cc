#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> hierarchy;
unordered_map<string, bool> check;

int MemberCount(string member) {
    if(check[member])
        return 0;

    check[member] = true;
    if(hierarchy[member].empty())
        return 1;

    int count = 0;
    for(string membership: hierarchy[member])
        count += MemberCount(membership);
    return count;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    string line;
    string first;
    string club, member;

    cin >> n;
    while(n) {
        hierarchy.clear();
        check.clear();

        for(int i = 0, start; i < n; i++) {
            cin >> line;

            start = 0;
            for(int end = 0; end < line.length(); end++) {
                if(line[end] == ':') {
                    club = line.substr(start, end - start);
                    start = end + 1;
                }
                else if(line[end] == ',' || line[end] == '.') {
                    member = line.substr(start, end - start);
                    start = end + 1;

                    hierarchy[club].push_back(member);
                }
            }

            if(i == 0)
                first = club;
        }

        cout << MemberCount(first) << '\n';
        cin >> n;
    }
    return 0;
}