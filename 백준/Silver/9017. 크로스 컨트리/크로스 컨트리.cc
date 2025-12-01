#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
    int N; cin >> N;
    vector<int> finish(N);
    for (int i = 0; i < N; i++) cin >> finish[i];

    // 1. 팀별 인원 수 세기
    vector<int> teamCnt(201);  // 팀 번호 최대치에 맞춰서
    for (int x : finish) teamCnt[x]++;
    
    // 2. 유효한 팀(6명)만 등수 부여
    int scoreRank = 0;
    vector<vector<int>> teamScores(201); // 각 팀의 등수 리스트
    for (int i = 0; i < N; i++) {
        int team = finish[i];
        if (teamCnt[team] != 6) continue; // 6명 아니면 스킵

        scoreRank++;
        teamScores[team].push_back(scoreRank);
    }
    
    // 3. 팀별로 1~4등수 합, 5번째 등수 구하기
    int bestTeam = -1;
    int bestSum = INT_MAX;
    int best5th = INT_MAX;

    for (int team = 1; team <= 200; team++) {
        if (teamCnt[team] != 6) continue;

        int sum4 = teamScores[team][0] + teamScores[team][1] +
                   teamScores[team][2] + teamScores[team][3];
        int fifth = teamScores[team][4];

        if (sum4 < bestSum ||
           (sum4 == bestSum && fifth < best5th)) {
            bestSum = sum4;
            best5th = fifth;
            bestTeam = team;
        }
    }

    cout << bestTeam << '\n';
        
    }
    return 0;
}