#include <iostream>
#include <algorithm>

using namespace std;

bool check[201][201][201];
bool map[201] = {0};
int result[100], result_count = 0;

void DFS(int const &a, int const &b, int const &c, int c_a, int c_b, int c_c) {
    if(check[c_a][c_b][c_c])
        return;

    if(c_a == 0 && !map[c_c]) {
        map[c_c] = true;
        result[result_count++] = c_c;
    }

    check[c_a][c_b][c_c] = true;
    // b -> a
    if(c_b >= a - c_a)
        DFS(a, b, c, a, c_b - (a - c_a), c_c);
    else
        DFS(a, b, c, c_a + c_b, 0, c_c);

    // c -> a
    if(c_c >= a - c_a)
        DFS(a, b, c, a, c_b, c_c - (a - c_a));
    else
        DFS(a, b, c, c_a + c_c, c_b, 0);

    // a -> b
    if(c_a >= b - c_b)
        DFS(a, b, c, c_a - (b - c_b), b, c_c);
    else
        DFS(a, b, c, 0, c_b + c_a, c_c);
        
    // c -> b
    if(c_c >= b - c_b)
        DFS(a, b, c, c_a, b, c_c - (b - c_b));
    else
        DFS(a, b, c, c_a, c_b + c_c, 0);

    // a -> c
    if(c_a >= c - c_c)
        DFS(a, b, c, c_a - (c - c_c), c_b, c);
    else
        DFS(a, b, c, 0, c_b, c_c + c_a);

    // b -> c
    if(c_b >= c - c_c)
        DFS(a, b, c, c_a, c_b - (c - c_c), c);
    else
        DFS(a, b, c, c_a, 0, c_c + c_b);
        
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    
    DFS(a, b, c, 0, 0, c);
    sort(result, result + result_count);

    for(int i = 0; i < result_count; i++)
        cout << result[i] << ' ';
    cout << '\n';
    return 0;
}