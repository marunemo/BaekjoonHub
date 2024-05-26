#include <iostream>
#define INF 1000000

using namespace std;

int value[100];
int exchange[10001];

int main() {
    int coin, price;

    cin >> coin >> price;
    for(int i = 0; i < coin; i++)
        cin >> value[i];
    
    exchange[0] = 0;
    for(int i = 1; i <= price; i++) {
        exchange[i] = INF;
        for(int j = 0; j < coin; j++) {
            if(i >= value[j])
                exchange[i] = min(exchange[i], exchange[i - value[j]] + 1);
        }
    }

    if(exchange[price] == INF)
        exchange[price] = -1;
        
    cout << exchange[price] << endl;
    return 0;
}