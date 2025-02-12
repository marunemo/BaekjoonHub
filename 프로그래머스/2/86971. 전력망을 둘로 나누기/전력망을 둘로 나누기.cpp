#include <string>
#include <vector>

using namespace std;

int DFS(vector<vector<int>> const &adj_list, int parent, int node) {
    int count = 1;
    
    for(int next: adj_list[node]) {
        if(next != parent)
            count += DFS(adj_list, node, next);
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> adj_list = vector<vector<int>>(n + 1);
    int count[2];
    
    for(vector<int> wire: wires) {
        adj_list[wire[0]].push_back(wire[1]);
        adj_list[wire[1]].push_back(wire[0]);
    }
    
    for(vector<int> wire: wires) {
        for(int i = 0; i < 2; i++)
            count[i] = DFS(adj_list, wire[1 - i], wire[i]);
        answer = min(answer, abs(count[0] - count[1]));
    }
    
    return answer;
}