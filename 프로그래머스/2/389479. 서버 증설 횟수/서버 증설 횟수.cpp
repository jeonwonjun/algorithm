#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(24);
    // 1. players의 첫 index부터 players[i] / (m+server[i]) = 증설한 서버 수
    for(int i=0; i<24; i++) {
        int s = players[i] / m; // 필요한 증설 서버 수
        int a = 0; // 서버 증설 수
        if (s > server[i])
            a = s - server[i];
        // 2. 증설한 서버 수를 server[i] ~ server[i+k]까지 입력
        for(int j=0; j<k; j++) {
            if (i+j < 24)
                server[i+j] += a;
        }
        answer += a;
    }
    return answer;
}