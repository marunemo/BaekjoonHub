#include <iostream>
#define INF 20000000

using namespace std;

int w_size;
int weight[16][16];
int memo[1 << 16][16];

int TSP(int mask, int from) {
    if(mask == (1 << w_size) - 1) {
        if(weight[from][0] == 0)
            return INF;
        return weight[from][0];
    }

    int &min_weight = memo[mask][from];
    if(min_weight != -1)
        return min_weight;
    min_weight = INF;
    
    for(int to = 0; to < w_size; to++) {
        if(!(mask & (1 << to)) && weight[from][to] != 0)
            min_weight = min(min_weight, TSP(mask | (1 << to), to) + weight[from][to]);
    }
    return min_weight;
}

int main() {
    cin >> w_size;
    for(int i = 0; i < w_size; i++) {
        for(int j = 0; j < w_size; j++)
            cin >> weight[i][j];
    }
    
    for(int mask = 0; mask < (1 << w_size); mask++) {
        for(int from = 0; from < w_size; from++)
            memo[mask][from] = -1;
    }

    cout << TSP(1, 0) << endl;
    return 0;
}