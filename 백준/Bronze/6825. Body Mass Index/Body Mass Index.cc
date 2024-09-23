#include <iostream>

using namespace std;

int main() {
    double weight, height, bmi;

    cin >> weight >> height;
    bmi = weight / (height * height);
    if(bmi >= 25)
        cout << "Overweight" << endl;
    else if(bmi >= 18.5)
        cout << "Normal weight" << endl;
    else
        cout << "Underweight" << endl;
    return 0;
}