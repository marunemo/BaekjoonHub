#include <iostream>
#include <string>

using namespace std;

char number[10][5][4] = {
    {
        "###",
        "#.#",
        "#.#",
        "#.#",
        "###"
    },
    {},
    {
        "###",
        "..#",
        "###",
        "#..",
        "###"
    },
    {
        "###",
        "..#",
        "###",
        "..#",
        "###"
    },
    {
        "#.#",
        "#.#",
        "###",
        "..#",
        "..#"
    },
    {
        "###",
        "#..",
        "###",
        "..#",
        "###"
    },
    {
        "###",
        "#..",
        "###",
        "#.#",
        "###"
    },
    {
        "###",
        "..#",
        "..#",
        "..#",
        "..#"
    },
    {
        "###",
        "#.#",
        "###",
        "#.#",
        "###"
    },
    {
        "###",
        "#.#",
        "###",
        "..#",
        "###"
    }
};

int main() {
    int len;
    string signal;
    string pattern[5];
    string result = "";
    bool flag, match;

    cin >> len >> signal;
    for(int index = 0, i = 0; i < len; i += len / 5)
        pattern[index++] = signal.substr(i, len / 5);
    
    len /= 5;
    for(int col = 0; col < len; col++) {
        // empty
        if(pattern[0][col] == '.')
            continue;
        
        // 1
        if(col + 1 == len || col + 2 == len) {
            result += "1";
            continue;
        }
        
        flag = false;
        for(int i = 0; i < 10 && !flag; i++) {
            if(i == 1)
                continue;

            match = true;
            for(int r = 0; r < 5 && match; r++) {
                for(int c = 0; c < 3 && match; c++)
                    match = pattern[r][col + c] == number[i][r][c];
            }

            if(match) {
                flag = true;
                result += to_string(i);
            }
        }

        if(flag)
            col += 3;
        else
            result += "1";
    }

    cout << result << endl;
    return 0;
}