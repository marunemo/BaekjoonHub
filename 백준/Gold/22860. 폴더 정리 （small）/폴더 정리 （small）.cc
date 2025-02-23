#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;
using File = pair<string, bool>;

unordered_map<string, vector<File>> tree;
unordered_map<string, bool> check;

pii DFS(string name) {
    pii tmp, type_count = {0, 0};

    for(File file: tree[name]) {
        if(file.second) {
            tmp = DFS(file.first);
            type_count.first += tmp.first;
            type_count.second += tmp.second;
        }
        else {
            if(!check[file.first]) {
                check[file.first] = true;
                type_count.first++;
            }
            type_count.second++;
        }
    }

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

    cin >> query;
    while(query--) {
        cin >> dir;

        check.clear();
        for(int i = dir.length() - 1; i >= 0; i--) {
            if(dir[i] == '/') {
                dir = dir.substr(i + 1);
                break;
            }
        }

        type_count = DFS(dir);
        cout << type_count.first << ' ' << type_count.second << '\n';
    }
    return 0;
}