/*
각 그래프별 특징 주목
1. 도넛 모양 그래프
- 각 정점은 1개의 진입 차수(in-degree)와 진출 차수(out-degree)를 가진다.

2. 막대 모양 그래프
- 마지막 정점은 1개의 진입 차수와 0개의 진출 차수를 가진다.

3. 8자 모양 그래프
- 그래프에 있는 하나의 정점은 2개의 진입 차수와 2개의 진출 차수를 가진다.
→ 진입차수 1개와 진출차수 1개를 가지는 그래프를 판별하는 방법이 존재하지 않는다.
→ 정확하게 말하자면, 팔자 모양 그래프의 진입차수와 진출차수가 2개인 특별한 정점을 제외하고 서는 모두 도넛 모양 그래프와 동일하 차수를 가진다. 따라서, 전체 그래프 개수에서 막대 모양 그래프와 8자 모양 그래프의 개수를 빼서 도넛 모양 그래프를 구한다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N = -1;
int rootNode;
bool exist[1000001];
int inDegree[1000001];
int outDegree[1000001];

void init(vector<vector<int>> edges) {
    // 노드의 진입,진출 개수 저장
    for (int i=0; i<edges.size(); i++) {
        outDegree[edges[i][0]]++;
        inDegree[edges[i][1]]++;
        
        // 노드의 가장 큰 값 저장
        N = max(N, max(edges[i][0], edges[i][1]));
        
        // 노드가 순서대로 오지 않을 수 있기 때문에 입력된 노드가 존재하는지 저장
        exist[edges[i][0]] = true;
        exist[edges[i][1]] = true;
    }
    
    // N개의 노드 중 진입차수가 없고 진출차수가 1개 이상이면 루트노드
    for (int i=1; i<=N; i++) {
        if (inDegree[i] == 0 && outDegree[i] >= 2)
            rootNode = i;
        
    }
    
    // 루트노드에서 나가는 간선 제거
    for (int i=0; i<edges.size(); i++) {
        if (rootNode == edges[i][0])
            inDegree[edges[i][1]]--;
    }
}

bool isLine(int node) {
    // size가 2 이상일 때
    if (inDegree[node] == 1 && outDegree[node] == 0)
        return true;
    // size가 1 일 때
    else if (inDegree[node] == 0 && outDegree[node] == 0)
        return true;
    
    return false;
}

bool isEight(int node) {
    // 해당 그래프에서 이 조건을 만족하는 경우가 있다면 8자 모양 그래프
    if (inDegree[node] == 2 && outDegree[node] == 2)
        return true;
    
    return false;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.assign(4, 0);
    
    init(edges);
    answer[0] = rootNode;
    
    for (int i=1; i<=N; i++) {
        if (exist[i]) {
            if(isLine(i))
                answer[2]++;
            else if(isEight(i))
                answer[3]++;
        }
    }
    answer[1] = outDegree[answer[0]] - (answer[2] + answer[3]);
    
    return answer;
}