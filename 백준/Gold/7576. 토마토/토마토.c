#include <stdio.h>

int tomato[1000][1000];
int today[1000000][2];
int tmr[1000000][2];

int main() {
    int width, height, row, col;
    int today_count = 0;
    int tmr_count = 0;
    int date = 0;
    int flag;

    scanf("%d %d", &width, &height);
    for(row = 0; row < height; row++) {
        for(col = 0; col < width; col++) {
            scanf("%d", &tomato[row][col]);
            if(tomato[row][col] == 1) {
                today[today_count][0] = row;
                today[today_count][1] = col;
                today_count++;
            }
        }
    }

    while(today_count != 0) {
        for(int i = 0; i < today_count; i++) {
            row = today[i][0];
            col = today[i][1];

            if(row > 0 && tomato[row - 1][col] == 0) {
                tomato[row - 1][col] = 1;
                tmr[tmr_count][0] = row - 1;
                tmr[tmr_count][1] = col;
                tmr_count++;
            }
            if(row < height - 1 && tomato[row + 1][col] == 0) {
                tomato[row + 1][col] = 1;
                tmr[tmr_count][0] = row + 1;
                tmr[tmr_count][1] = col;
                tmr_count++;
            }
            if(col > 0 && tomato[row][col - 1] == 0) {
                tomato[row][col - 1] = 1;
                tmr[tmr_count][0] = row;
                tmr[tmr_count][1] = col - 1;
                tmr_count++;
            }
            if(col < width - 1 && tomato[row][col + 1] == 0) {
                tomato[row][col + 1] = 1;
                tmr[tmr_count][0] = row;
                tmr[tmr_count][1] = col + 1;
                tmr_count++;
            }
        }

        for(int cpy = 0; cpy < tmr_count; cpy++) {
            today[cpy][0] = tmr[cpy][0];
            today[cpy][1] = tmr[cpy][1];
        }
        today_count = tmr_count;
        tmr_count = 0;
        date += (today_count != 0);
    }

    flag = 1;
    for(row = 0; row < height && flag; row++) {
        for(col = 0; col < width && flag; col++) {
            if(tomato[row][col] == 0)
                flag = 0;
        }
    }

    if(!flag)
        printf("-1\n");
    else
        printf("%d\n", date);
    return 0;
}