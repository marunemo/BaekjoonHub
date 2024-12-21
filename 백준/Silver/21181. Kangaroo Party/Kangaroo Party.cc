#include <iostream>

using namespace std;

int main() {
    int n;
    int kangaroo[50];
    int energy, min_energy = 1e9;

    cin >> n; 
    for(int i = 0; i < n; i++)
        cin >> kangaroo[i];

    for(int pick1 = 0; pick1 < n; pick1++) {
        for(int pick2 = pick1 + 1; pick2 < n; pick2++) {
            energy = 0;
            for(int i = 0; i < n; i++) {
                if(i != pick1 && i != pick2)
                    energy += min((kangaroo[i] - kangaroo[pick1]) * (kangaroo[i] - kangaroo[pick1]), (kangaroo[i] - kangaroo[pick2]) * (kangaroo[i] - kangaroo[pick2]));
            }
            min_energy = min(energy, min_energy);
        }
    }

    cout << min_energy << endl;
    return 0;
}