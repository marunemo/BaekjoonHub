#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    char name[11];
    int score;
    
    cin >> tc;
    while(tc--) {
        cin >> name >> score;
        cout << name << ' ';
        if(score >= 97)
            cout << "A+";
        else if(score >= 90)
            cout << "A";
        else if(score >= 87)
            cout << "B+";
        else if(score >= 80)
            cout << "B";
        else if(score >= 77)
            cout << "C+";
        else if(score >= 70)
            cout << "C";
        else if(score >= 67)
            cout << "D+";
        else if(score >= 60)
            cout << "D";
        else
            cout << "F";
        cout << '\n';
    }
    return 0;
}