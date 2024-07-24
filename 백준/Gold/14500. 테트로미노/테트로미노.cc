#include <iostream>

using namespace std;

const int mask14[1][1][4] = {
    {
        {1, 1, 1, 1}
    }
};
const int mask41[1][4][1] = {
    {
        {1},
        {1},
        {1},
        {1}
    }
};
const int mask22[1][2][2] = {
    {
        {1, 1},
        {1, 1}
    }
};
const int mask32[8][3][2] = {
    {
        {1, 0},
        {1, 0},
        {1, 1}
    },
    {
        {0, 1},
        {0, 1},
        {1, 1}
    },
    {
        {1, 1},
        {0, 1},
        {0, 1}
    },
    {
        {1, 1},
        {1, 0},
        {1, 0}
    },
    {
        {1, 0},
        {1, 1},
        {0, 1}
    },
    {
        {0, 1},
        {1, 1},
        {1, 0}
    },
    {
        {0, 1},
        {1, 1},
        {0, 1}
    },
    {
        {1, 0},
        {1, 1},
        {1, 0}
    }
};
const int mask23[8][2][3] = {
    {
        {0, 0, 1},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 0, 1}
    },
    {
        {1, 1, 1},
        {1, 0, 0}
    },
    {
        {1, 0, 0},
        {1, 1, 1}
    },    
    {
        {1, 1, 0},
        {0, 1, 1}
    },
    {
        {0, 1, 1},
        {1, 1, 0}
    },
    {
        {0, 1, 0},
        {1, 1, 1}
    },
    {
        {1, 1, 1},
        {0, 1, 0}
    },
};

int height, width;
int map[500][500];

int MaxMask(int mask_r, int mask_c) {
    int mask_count = 1;
    int sum, max_sum = 0;

    if(mask_r == 2 && mask_c == 3)
        mask_count = 8;
    if(mask_r == 3 && mask_c == 2)
        mask_count = 8;

    for(int row = 0; row < height - (mask_r - 1); row++) {
        for(int col = 0; col < width - (mask_c - 1); col++) {
            for(int i = 0; i < mask_count; i++) {
                sum = 0;
                for(int r = 0; r < mask_r; r++) {
                    for(int c = 0; c < mask_c; c++) {
                        if(mask_r == 1 && mask_c == 4)
                            sum += map[row + r][col + c] * mask14[i][r][c];
                        else if(mask_r == 4 && mask_c == 1)
                            sum += map[row + r][col + c] * mask41[i][r][c];
                        else if(mask_r == 2 && mask_c == 2)
                            sum += map[row + r][col + c] * mask22[i][r][c];
                        else if(mask_r == 3 && mask_c == 2)
                            sum += map[row + r][col + c] * mask32[i][r][c];
                        else if(mask_r == 2 && mask_c == 3)
                            sum += map[row + r][col + c] * mask23[i][r][c];
                    }
                }
                max_sum = max(sum, max_sum);
            }
        }
    }
    
    return max_sum;
}

int main() {
    int max_sum = 0;

    cin >> height >> width;
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++)
            cin >> map[row][col];
    }

    max_sum = max(max_sum, MaxMask(1, 4));
    max_sum = max(max_sum, MaxMask(4, 1));
    max_sum = max(max_sum, MaxMask(2, 2));
    max_sum = max(max_sum, MaxMask(3, 2));
    max_sum = max(max_sum, MaxMask(2, 3));

    cout << max_sum << endl;
    return 0;
}