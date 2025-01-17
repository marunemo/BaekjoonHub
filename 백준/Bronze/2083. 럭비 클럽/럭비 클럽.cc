#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string name;
    int age, weight;

    cin >> name >> age >> weight;
    while(!(name == "#" && age == 0 && weight == 0)) {
        cout << name << ' ';
        if(age > 17 || weight >= 80)
            cout << "Senior\n";
        else
            cout << "Junior\n";
        cin >> name >> age >> weight;
    }
    return 0;
}