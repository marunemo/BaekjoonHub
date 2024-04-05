#include <iostream>

using namespace std;
using Pos = pair<int, int>;

int parent[3000];
Pos line[3000][2];
int group[3000];

int UnionFind(int node) {
    if(parent[node] == node)
        return node;
    return parent[node] = UnionFind(parent[node]);
}

int CCW(Pos a, Pos b, Pos c) {
    int outer_product = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
    return (outer_product > 0) - (outer_product < 0);
}

bool IsIntersect(Pos line_a[2], Pos line_b[2]) {
    int atob = CCW(line_a[0], line_a[1], line_b[0]) * CCW(line_a[0], line_a[1], line_b[1]);
    int btoa = CCW(line_b[0], line_b[1], line_a[0]) * CCW(line_b[0], line_b[1], line_a[1]);
    Pos left_a, right_a, left_b, right_b;

    if(atob == 0 && btoa == 0) {
        if(line_a[0] < line_a[1]) {
            left_a = line_a[0];
            right_a = line_a[1];
        }
        else {
            left_a = line_a[1];
            right_a = line_a[0];
        }

        if(line_b[0] < line_b[1]) {
            left_b = line_b[0];
            right_b = line_b[1];
        }
        else {
            left_b = line_b[1];
            right_b = line_b[0];
        }
        // 각 선의 오른쪽 끝보다 다른 선의 왼쪽 끝의 x, y 좌표가 모두 크다면 인접하지 않음
        return !(right_a < left_b || left_a > right_b);
    }
    return (atob <= 0 && btoa <= 0);
}

int main() {
    int n;
    int group_count, max_count;

    cin >> n;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        group[i] = 0;

        cin >> line[i][0].first >> line[i][0].second >> line[i][1].first >> line[i][1].second;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(UnionFind(i) == UnionFind(j))
                continue;
            
            if(!IsIntersect(line[i], line[j]))
                continue;
            
            if(parent[i] > parent[j])
                parent[parent[i]] = parent[j];
            else
                parent[parent[j]] = parent[i];
        }
    }

    group_count = 0;
    max_count = 0;
    for(int i = 0; i < n; i++) {
        if(group[parent[i]] == 0)
            group_count++;
        group[parent[i]]++;
        max_count = max(max_count, group[parent[i]]);
    }

    cout << group_count << '\n' << max_count << '\n';
    return 0;
}