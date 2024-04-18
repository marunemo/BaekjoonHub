#include <iostream>
#include <unordered_map>

using namespace std;

int group[1000][1000] = {0};
unordered_map<int, int> group_union;
char map[1000][1000] = {0};

int UnionFind(int node) {
    if(group_union[node] == node)
        return node;
    return group_union[node] = UnionFind(group_union[node]);
}

void DFS(int row, int col, int group_index) {
    if(group[row][col]) {
        if(UnionFind(group[row][col]) == UnionFind(group_index))
            return;
        
        if(group_union[group[row][col]] > group_union[group_index])
            group_union[group_union[group[row][col]]] = group_union[group_index];
        else
            group_union[group_union[group_index]] = group_union[group[row][col]];
        return;
    }

    group[row][col] = group_index;
    if(map[row][col] == 'U')
        DFS(row - 1, col, group_index);
    else if(map[row][col] == 'D')
        DFS(row + 1, col, group_index);
    else if(map[row][col] == 'L')
        DFS(row, col - 1, group_index);
    else if(map[row][col] == 'R')
        DFS(row, col + 1, group_index);
}

int main() {
    int height, width;
    int group_index = 0;
    int group_count = 0;
    unordered_map<int, bool> check;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> map[row][col];
    }

    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            if(!group[row][col]) {
                group_index++;
                group_union[group_index] = group_index;
                DFS(row, col, group_index);
            }
        }
    }

    for(int i = 1; i <= group_index; i++) {
        if(!check[UnionFind(i)]) {
            check[group_union[i]] = true;
            group_count++;
        }
    }

    cout << group_count << endl;
    return 0;
}