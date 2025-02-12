#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool CheckTree(unordered_map<int, vector<int>> &adj_list, int parent, int node) {
    if(parent == -1) {
        if((adj_list[node].size() & 1) != (node & 1))
            return false;
    }
    else {
        if(((adj_list[node].size() - 1) & 1) != (node & 1))
            return false;
    }
    
    for(int next: adj_list[node]) {
        if(next != parent) {
            if(!CheckTree(adj_list, node, next))
                return false;
        }
    }
    
    return true;
}

bool CheckTreeReverse(unordered_map<int, vector<int>> &adj_list, int parent, int node) {
    if(parent == -1) {
        if((adj_list[node].size() & 1) == (node & 1))
            return false;
    }
    else {
        if(((adj_list[node].size() - 1) & 1) == (node & 1))
            return false;
    }
    
    for(int next: adj_list[node]) {
        if(next != parent) {
            if(!CheckTreeReverse(adj_list, node, next))
                return false;
        }
    }
    
    return true;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer = vector<int>(2);
    unordered_map<int, vector<int>> adj_list;
    
    for(vector<int> edge: edges) {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }
    
    for(int node: nodes) {
        answer[0] += CheckTree(adj_list, -1, node);
        answer[1] += CheckTreeReverse(adj_list, -1, node);
    }
    
    return answer;
}