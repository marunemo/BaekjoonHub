#include <iostream>
#define INF 30

using namespace std;

bool AllFlip(int *bowl) {
    for(int i = 0; i < 20; i++) {
        if(bowl[i] == 1)
            return false;
    }
    return true;
}

int Test(const int *bowl) {
    int copy[20];
    int l_count = 0;
    int r_count = 0;

    for(int i = 0; i < 20; i++)
        copy[i] = bowl[i];

    for(int i = 1; i <= 20; i++) {
        if(copy[i - 1]) {
            l_count++;

            copy[i - 1] = 1 - copy[i - 1];
            if(i < 20)
                copy[i] = 1 - copy[i];
            if(i < 19)
                copy[i + 1] = 1 - copy[i + 1];
        }
    }

    if(!AllFlip(copy))
        l_count = INF;

    for(int i = 0; i < 20; i++)
        copy[i] = bowl[i];

    for(int i = 18; i >= -1; i--) {
        if(copy[i + 1]) {
            r_count++;

            copy[i + 1] = 1 - copy[i + 1];
            if(i >= 0)
                copy[i] = 1 - copy[i];
            if(i > 0)
                copy[i - 1] = 1 - copy[i - 1];
        }
    }

    if(!AllFlip(copy))
        r_count = INF;

    return min(l_count, r_count);
}

int main() {
    int bowl[20];
    int count = INF;
    
    for(int i = 0; i < 20; i++)
        cin >> bowl[i];
    
    count = min(count, Test(bowl));
    
    if(bowl[0] == 1) {
        bowl[0] = 1 - bowl[0];
        bowl[1] = 1 - bowl[1];

        count = min(count, Test(bowl) + 1);
        
        bowl[0] = 1 - bowl[0];
        bowl[1] = 1 - bowl[1];
    }

    if(bowl[19] == 1) {
        bowl[19] = 1 - bowl[19];
        bowl[18] = 1 - bowl[18];

        count = min(count, Test(bowl) + 1);

        bowl[19] = 1 - bowl[19];
        bowl[18] = 1 - bowl[18];
    }

    if(bowl[0] == 1 && bowl[19] == 1) {
        bowl[0] = 1 - bowl[0];
        bowl[1] = 1 - bowl[1];
        bowl[19] = 1 - bowl[19];
        bowl[18] = 1 - bowl[18];

        count = min(count, Test(bowl) + 2);
    }
    
    cout << count << endl;
    return 0;
}