#include <string>
#include <vector>

using namespace std;

void RemoveAll(vector<string> &storage, char target) {
    int height = storage.size();
    int width = storage[0].size();
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(storage[i][j] == target)
                storage[i][j] = ' ';
        }
    }
}

void Remove(vector<string> &storage, char target, int row, int col) {
    const int dy[4] = {-1, 1, 0, 0};
    const int dx[4] = {0, 0, -1, 1};
    
    if(storage[row][col] == target)
        storage[row][col] = '/';
    
    if(storage[row][col] != ' ')
        return;
    
    storage[row][col] = '/';
    for(int i = 0; i < 4; i++) {
        if(row + dy[i] < 0 || row + dy[i] >= storage.size() || col + dx[i] < 0 || col + dx[i] >= storage[row].size())
            continue;
        
        if(storage[row + dy[i]][col + dx[i]] == ' ' || storage[row + dy[i]][col + dx[i]] == target)
            Remove(storage, target, row + dy[i], col + dx[i]);
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int height = storage.size();
    int width = storage[0].size();
    
    for(string request: requests) {
        if(request.length() == 2) {
            RemoveAll(storage, request[0]);
        }
        else {
            for(int i = 0; i < width; i++) {
                Remove(storage, request[0], 0, i);
                Remove(storage, request[0], height - 1, i);
            }
            
            for(int i = 0; i < height; i++) {
                Remove(storage, request[0], i, 0);
                Remove(storage, request[0], i, width - 1);
            }

            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    if(storage[i][j] == '/')
                        storage[i][j] = ' ';
                }
            }
        }
    }
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            answer += storage[i][j] != ' ';
        }
    }
    
    return answer;
}