#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool Validate(vector<vector<int>> const &q, vector<int> const &ans, unordered_map<int, bool> &code) {
    for(int i = 0; i < q.size(); i++) {
        int count = 0;
        for(int j = 0; j < 5; j++) {
            count += code[q[i][j]];
        }
        if(count != ans[i])
            return false;
    }
    return true;
}

int DFS(vector<vector<int>> const &q, vector<int> const &ans, unordered_map<int, bool> &code, int n, int idx, int depth) {
    if(depth == 5)
        return Validate(q, ans, code);
    
    int count = 0;
    for(int i = idx; i <= n; i++) {
        code[i] = true;
        count += DFS(q, ans, code, n, i + 1, depth + 1);   
        code[i] = false;
    }
    return count;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    unordered_map<int, bool> code;
    int answer = DFS(q, ans, code, n, 1, 0);
    
    return answer;
}