#include <iostream>

using namespace std;

bool adj_matrix[500][500];

int main() {
    int vertice;
    int node;
    int count;

    cin >> vertice;

    for(int i = 0; i < vertice; i++) {
        for(int j = 0; j < vertice; j++)
            adj_matrix[i][j] = true;
        adj_matrix[i][i] = false;
    }

    count = vertice * (vertice - 1) / 2;

    node = 0;
    adj_matrix[0][vertice - 1] = adj_matrix[vertice - 1][0] = false;
    while(count--) {
        cout << 'a' << (node + 1) << ' ';
        for(int i = 0; i < vertice; i++) {
            if(adj_matrix[node][i]) {
                adj_matrix[node][i] = adj_matrix[i][node] = false;
                node = i;
                break;
            }
        }
    }
    cout << "a1" << endl;

    return 0;
}