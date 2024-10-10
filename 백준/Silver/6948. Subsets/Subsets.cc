#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void DFS(unordered_map<char, vector<char>> &adj_list, vector<char> &output, unordered_map<char, bool> &visit, char node) {
    visit[node] = true;
    for(char item: adj_list[node]) {
        if('A' <= item && item <= 'Z') {
            if(!visit[item])
                DFS(adj_list, output, visit, item);
        }
        else
            output.push_back(item);
    }
}

int main() {
    int num;
    char p, contains[10], c;
    unordered_map<char, bool> dupl_check;
    vector<char> set_list;
    unordered_map<char, vector<char>> adj_list;
    vector<char> output;
    unordered_map<char, bool> visit;

    cin >> num;
    while(num--) {
        cin >> p >> contains >> c;
        if(!dupl_check[p]) {
            dupl_check[p] = true;
            set_list.push_back(p);
        }
        if('A' <= c && c <= 'Z' && !dupl_check[c]) {
            dupl_check[c] = true;
            set_list.push_back(c);
        }
        adj_list[p].push_back(c);
    }
    sort(set_list.begin(), set_list.end());

    for(char node: set_list) {
        output = vector<char>();
        visit.clear();
        dupl_check.clear();

        DFS(adj_list, output, visit, node);
        sort(output.begin(), output.end());
        
        cout << node << " = {";
        if(!output.empty()) {
            dupl_check[output[0]] = true;
            cout << output[0];
        }
        for(int i = 1; i < output.size(); i++) {
            if(!dupl_check[output[i]]) {
                dupl_check[output[i]] = true;
                cout << ',' << output[i];
            }
        }
        cout << "}\n";
    }
    return 0;
}