#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> town = vector<int>(N + 1, 1000000);
    
    town[1] = 0;
    for(int vertex = 0; vertex < N; vertex++) {
        for(vector<int> edge: road) {
            if(town[edge[0]] > town[edge[1]] + edge[2])
                town[edge[0]] = town[edge[1]] + edge[2];
            if(town[edge[1]] > town[edge[0]] + edge[2])
                town[edge[1]] = town[edge[0]] + edge[2];
        }
    }

    for(int vertex = 1; vertex <= N; vertex++) {
        if(town[vertex] <= K)
            answer++;
    }
    return answer;
}