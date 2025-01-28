#include <iostream>
#include <string>

using namespace std;

int main() {
    string echo;
    int min_p = 0, min_m = 0;
    int weight = 0;

    cin >> echo;
    for(char e: echo) {
        if(e == 'K')
            weight++;
        else
            weight--;
        
        if(weight < 0)
            min_m = max(min_m, -weight);
        else
            min_p = max(min_p, weight);
    }
    cout << (min_m + min_p) << endl;
    return 0;
}