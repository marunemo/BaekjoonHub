#include <iostream>

using namespace std;
using pii = pair<int, int>;

int value[51][51];
int prefix_sum[51][51];

int main() {
    int n, answer = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> value[i][j];

            prefix_sum[i][j] = prefix_sum[i][j - 1] + value[i][j];
        }

        for(int j = 1; j <= n; j++) {
            prefix_sum[i][j] += prefix_sum[i - 1][j];
        }
    }

    for(int start_row = 0; start_row < n; start_row++) {
        for(int start_col = 0; start_col < n; start_col++) {
            for(int end_row = start_row + 1; end_row <= n; end_row++) {
                for(int end_col = start_col + 1; end_col <= n; end_col++) {
                    int std_area = prefix_sum[end_row][end_col] - prefix_sum[start_row][end_col] - prefix_sum[end_row][start_col] + prefix_sum[start_row][start_col];

                    pii left_down = {end_row, start_col};
                    pii right_down = {end_row, end_col};

                    // 왼쪽
                    for(int row = left_down.first + 1; row <= n; row++) {
                        for(int col = 0; col < left_down.second; col++) {
                            int area = prefix_sum[row][left_down.second] - prefix_sum[left_down.first][left_down.second] - prefix_sum[row][col] + prefix_sum[left_down.first][col];
                            
                            answer += std_area == area;
                        }
                    }

                    // 오른쪽
                    for(int row = right_down.first + 1; row <= n; row++) {
                        for(int col = right_down.second + 1; col <= n; col++) {
                            int area = prefix_sum[row][col] - prefix_sum[right_down.first][col] - prefix_sum[row][right_down.second] + prefix_sum[right_down.first][right_down.second];

                            answer += std_area == area;
                        }
                    }
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}