#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    const int size = board.size();
    vector<int> height = vector<int>(size);
    vector<int> basket;
    
    for(int col = 0; col < size; col++) {
        int row;
        for(row = 0; row < size; row++) {
            if(board[row][col])
                break;
        }
        height[col] = row;
    }
    
    for(int move: moves) {
        if(height[move - 1] == size)
            continue;
        
        if(!basket.empty() && basket.back() == board[height[move - 1]][move - 1]) {
            basket.pop_back();
            answer += 2;
        }
        else {
            basket.push_back(board[height[move - 1]][move - 1]);
        }
        
        height[move - 1]++;
    }
    
    return answer;
}