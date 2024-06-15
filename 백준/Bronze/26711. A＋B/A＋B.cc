#include <iostream>
#include <string>

using namespace std;

string Adder(string a, string b) {
    while(a.length() < b.length())
        a = "0" + a;
    
    while(a.length() > b.length())
        b = "0" + b;
    
    int index = a.length() - 1;
    int digit_a, digit_b, digit_sum;
    int carry = 0;
    string sum = "";

    for(; index >= 0; index--) {
        digit_a = a[index] - '0';
        digit_b = b[index] - '0';
        digit_sum = digit_a + digit_b + carry;

        sum = to_string(digit_sum % 10) + sum;
        carry = digit_sum >= 10;
    }

    if(carry)
        sum = "1" + sum;
    return sum;
}

int main() {
    string a, b;

    cin >> a >> b;

    cout << Adder(a, b) << endl;
    return 0;
}