#include <iostream>

using namespace std;

int cand_count, len;
char candidate[20][21];
char predict[21];
char result[21] = {0};

bool Valid() {
    int diff;
    for(int i = 0; i < cand_count; i++) {
        diff = 0;
        for(int l = 0; l < len; l++) {
            if(candidate[i][l] != predict[l])
                diff++;
        }

        if(diff > 1)
            return false;
    }
    return true;
}

void Copy(char *src, char *dest) {
    for(int l = 0; l < len; l++)
        dest[l] = src[l];
    dest[len] = 0;
}

int main() {
    cin >> cand_count >> len;
    for(int i = 0; i < cand_count; i++)
        cin >> candidate[i];
    
    for(int i = 0; i < cand_count; i++) {
        for(int l = 0; l < len; l++) {
            Copy(candidate[i], predict);

            for(int alpha = 'A'; alpha <= 'Z'; alpha++) {
                predict[l] = alpha;
                if(Valid())
                    Copy(predict, result);
            }
        }
    }

    if(!result[0])
        cout << "CALL FRIEND" << endl;
    else
        cout << result << endl;
    return 0;
}