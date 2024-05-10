#include <iostream>
#define INF 250000

using namespace std;

int adj_matrix[501][501];

int main() {
    int vertex, edge;
    int start, end;
    int count, answer;

    cin >> vertex >> edge;
    for(int i = 1; i <= vertex; i++) {
        for(int j = 1; j <= vertex; j++)
            adj_matrix[i][j] = INF;
        adj_matrix[i][i] = 0;
    }

    while(edge--) {
        cin >> start >> end;
        adj_matrix[start][end] = 1;
    }

    for(int mid = 1; mid <= vertex; mid++) {
        for(int start = 1; start <= vertex; start++) {
            for(int end = 1; end <= vertex; end++) {
                if(adj_matrix[start][end] > adj_matrix[start][mid] + adj_matrix[mid][end])
                    adj_matrix[start][end] = adj_matrix[start][mid] + adj_matrix[mid][end];
            }
        }
    }

    answer = 0;
    for(int start = 1; start <= vertex; start++) {
        count = 0;
        for(int end = 1; end <= vertex; end++) {
            if(adj_matrix[start][end] != INF || adj_matrix[end][start] != INF)
                count++;
        }

        if(count == vertex)
            answer++;
    }
    cout << answer << endl;
    return 0;
}