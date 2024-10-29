#include <iostream>

using namespace std;

int main() {
    int score, union_level, level;

    cin >> score >> union_level >> level;

    if(score >= 1000) {
        if(union_level >= 8000 || level >= 260)
            cout << "Very Good" << endl;
        else
            cout << "Good" << endl;
    }
    else
        cout << "Bad" << endl;
    return 0;
}