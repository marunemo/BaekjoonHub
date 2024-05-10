#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using piv = pair<int, vector<int>>;

struct Node {
    piv node;
    Node *left = NULL;
    Node *right = NULL;
    
    Node(piv v) {
        node = v;
    }
};

vector<int> preorder(Node *node) {
    vector<int> order;
    order.push_back(node->node.first);
    if(node->left) {
        for(auto vertex: preorder(node->left))
            order.push_back(vertex);
    }
    if(node->right) {
        for(auto vertex: preorder(node->right))
            order.push_back(vertex);
    }
    return order;
}

vector<int> postorder(Node *node) {
    if(node == NULL)
        return vector<int>();
    
    vector<int> order;
    vector<int> left = postorder(node->left);
    vector<int> right = postorder(node->right);
    
    for(auto vertex: left)
        order.push_back(vertex);
    for(auto vertex: right)
        order.push_back(vertex);
    order.push_back(node->node.first);
    return order;
}

bool Compare(piv a, piv b) {
    if(a.second[1] == b.second[1])
        return a.second[0] < b.second[0];
    return a.second[1] > b.second[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<piv> vertex;
    for(int i = 0; i < nodeinfo.size(); i++)
        vertex.push_back({i + 1, nodeinfo[i]});
    sort(vertex.begin(), vertex.end(), Compare);
    
    Node root(vertex[0]);
    for(int i = 1; i < vertex.size(); i++) {
        Node *node = &root;
        Node *pre = NULL;
        while(node) {
            pre = node;
            if(node->node.second[0] > vertex[i].second[0])
                node = node->left;
            else
                node = node->right;
        }
        if(pre->node.second[0] > vertex[i].second[0])
            pre->left = new Node(vertex[i]);
        else
            pre->right = new Node(vertex[i]);
    }
    
    answer.push_back(preorder(&root));
    answer.push_back(postorder(&root));
    
    return answer;
}