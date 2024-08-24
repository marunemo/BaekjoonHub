#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int tc;
    int height, width;
    char image[10][10];
    bool checked[10][10];
    int count;

    cin >> tc;
    while(tc--) {
        cin >> height >> width;
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                cin >> image[row][col];
                checked[row][col] = false;
            }
        }
        
        count = 0;
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                if(checked[row][col])
                    continue;

                if(image[row][col] == '-') {
                    for(int dc = 0; col + dc < width && image[row][col + dc] == '-'; dc++)
                        checked[row][col + dc] = true;
                    count++;
                }
                else if(image[row][col] == '|') {
                    for(int dr = 0; row + dr < height && image[row + dr][col] == '|'; dr++)
                        checked[row + dr][col] = true;
                    count++;
                }
                else if(image[row][col] == '\\') {
                    for(int ds = 0; row + ds < height && col + ds < width && image[row + ds][col + ds] == '\\'; ds++)
                        image[row + ds][col + ds] = true;
                    count++;
                }
                else if(image[row][col] == '/') {
                    for(int ds = 0; row + ds < height && col - ds >= 0 && image[row + ds][col - ds] == '/'; ds++)
                        image[row + ds][col - ds] = true;
                    count++;
                }
            }
        }

        if(count != 1)
            cout << "INCORRECT\n";
        else
            cout << "CORRECT\n";
    }
    return 0;
}