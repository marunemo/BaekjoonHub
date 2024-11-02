#include <iostream>

using namespace std;

int main() {
    const char week[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int x, y;
    int date;

    cin >> x >> y;
    date = y;
    for(int i = 1; i < x; i++) {
        if(i == 2)
            date += 28;
        else if(i == 4 || i == 6 || i == 9 || i == 11)
            date += 30;
        else
            date += 31;
    }
    cout << week[date % 7] << endl;
    return 0;
}