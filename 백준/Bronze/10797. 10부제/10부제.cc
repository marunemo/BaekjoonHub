#include <iostream>

using namespace std;

int main() {
    int digit, number;
    int count = 0;
    
    cin >> digit;
    for(int i = 0; i < 5; i++) {
        cin >> number;
        if(number % 10 == digit)
            count++;
    }
    
    cout << count << endl;
    return 0;
}