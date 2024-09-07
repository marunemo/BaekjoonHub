#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int income_count;
    long long income, range_income, max_income;

    cin >> income_count;
    while(income_count) {
        range_income = max_income = -2500000000;
        while(income_count--) {
            cin >> income;

            if(range_income < 0)
                range_income = income;
            else
                range_income += income;
            max_income = max(range_income, max_income);
        }
        cout << max_income << '\n';

        cin >> income_count;
    }
}