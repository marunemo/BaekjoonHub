#include <iostream>
#include <vector>

using namespace std;

int paper_count[3];
vector<vector<int>> paper;

void Recursion(int paper_size, int r_start, int c_start) {
    bool flag = true;
    int num = paper[r_start][c_start];

    for(int row = 0; row < paper_size && flag; row++) {
        for(int col = 0; col < paper_size && flag; col++)
            flag = (num == paper[r_start + row][c_start + col]);
    }

    if(flag) {
        paper_count[num + 1]++;
        return;
    }
    
    for(int row = 0; row < paper_size; row += paper_size / 3) {
        for(int col = 0; col < paper_size; col += paper_size / 3)
            Recursion(paper_size / 3, r_start + row, c_start + col);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int paper_size;
    cin >> paper_size;

    paper = vector<vector<int>>(paper_size, vector<int>(paper_size));
    for(int row = 0; row < paper_size; row++) {
        for(int col = 0; col < paper_size; col++)
            cin >> paper[row][col];
    }

    Recursion(paper_size, 0, 0);
    for(int i = 0; i < 3; i++)
        cout << paper_count[i] << '\n';
    return 0;
}