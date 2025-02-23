#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
using pii = pair<int, int>;
using File = pair<string, bool>;

struct TypeCount {
    set<string> type;
    int count;
};

unordered_map<string, vector<File>> tree;
unordered_map<string, pii> result;

TypeCount DFS(string name) {
    TypeCount type_count, tmp;
    type_count.count = 0;

    for(File file: tree[name]) {
        if(file.second) {
            tmp = DFS(file.first);
            type_count.type.merge(tmp.type);
            type_count.count += tmp.count;
        }
        else {
            type_count.type.insert(file.first);
            type_count.count++;
        }
    }

    result[name] = {type_count.type.size(), type_count.count};
    return type_count;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int folder_count, file_count;
    string parent, dir;
    int type;
    int query;
    pii type_count;

    cin >> folder_count >> file_count;
    for(int i = 0; i < folder_count + file_count; i++) {
        cin >> parent >> dir >> type;

        tree[parent].push_back({dir, type == 1});
    }

    DFS("main");

    cin >> query;
    while(query--) {
        cin >> dir;

        for(int i = dir.length() - 1; i >= 0; i--) {
            if(dir[i] == '/') {
                dir = dir.substr(i + 1);
                break;
            }
        }

        type_count = result[dir];
        cout << type_count.first << ' ' << type_count.second << '\n';
    }
    return 0;
}