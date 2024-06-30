#include <iostream>

using namespace std;

int prefix_sum[301][301] = {0};

int main() {
    int height, width;
    int car_width, car_length, camp_length;
    int cost, min_cost = 1800000;

    cin >> height >> width;
    cin >> car_width >> car_length >> camp_length;

    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            cin >> cost;
            prefix_sum[i][j] = prefix_sum[i][j - 1] + cost;
        }
        for(int j = 1; j <= width; j++)
            prefix_sum[i][j] += prefix_sum[i - 1][j];
    }
    
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            // fig 1.
            if(row + car_width <= height && col + car_length + camp_length <= width) {
                // car + camp
                cost = prefix_sum[row + car_width][col + car_length + camp_length];
                cost -= prefix_sum[row + car_width][col];
                cost -= prefix_sum[row][col + car_length + camp_length];
                // 포함 배제의 원리
                cost += prefix_sum[row][col];
                
                min_cost = min(cost, min_cost);
            }
            
            // fig 2.
            if(row + car_width + car_length <= height && col + camp_length + car_width <= width) {
                // car
                cost = prefix_sum[row + car_width + car_length][col + camp_length + car_width];
                cost -= prefix_sum[row + car_width + car_length][col + camp_length];
                cost -= prefix_sum[row + car_width][col + camp_length + car_width];
                cost += prefix_sum[row + car_width][col + camp_length];

                // camp
                cost += prefix_sum[row + car_width][col + camp_length];
                cost -= prefix_sum[row + car_width][col];
                cost -= prefix_sum[row][col + camp_length];
                cost += prefix_sum[row][col];
                
                min_cost = min(cost, min_cost);
            }

            // fig 3.
            if(row + car_width + camp_length <= height && col + car_length + car_width <= width) {
                // car
                cost = prefix_sum[row + car_width][col + car_length];
                cost -= prefix_sum[row + car_width][col];
                cost -= prefix_sum[row][col + car_length];
                cost += prefix_sum[row][col];

                // camp
                cost += prefix_sum[row + car_width + camp_length][col + car_length + car_width];
                cost -= prefix_sum[row + car_width + camp_length][col + car_length];
                cost -= prefix_sum[row + car_width][col + car_length + car_width];
                cost += prefix_sum[row + car_width][col + car_length];

                min_cost = min(cost, min_cost);
            }
        }
    }

    cout << min_cost << endl;
    return 0;
}