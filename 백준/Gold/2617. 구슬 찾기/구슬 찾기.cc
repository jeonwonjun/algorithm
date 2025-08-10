#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 101;
int N, M, mid;
vector<int> heavy[MAX], light[MAX];
bool visited[MAX];

// DFS 함수: 현재 노드 기준으로 더 무거운(또는 가벼운) 구슬을 찾기
int dfs(int node, vector<int> graph[MAX]) {
    visited[node] = true;
    int cnt = 1;
    for (int next : graph[node]) {
        if (!visited[next])
            cnt += dfs(next, graph);
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    mid = (N + 1) / 2;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // a > b
        heavy[a].push_back(b);  // a는 b보다 무겁다
        light[b].push_back(a);  // b는 a보다 가볍다
    }

    int result = 0;

    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        int heavier = dfs(i, light) - 1;  // 나보다 무거운 구슬 개수
        if (heavier >= mid) {
            result++;
            continue;
        }

        memset(visited, false, sizeof(visited));
        int lighter = dfs(i, heavy) - 1;  // 나보다 가벼운 구슬 개수
        if (lighter >= mid) {
            result++;
        }
    }

    cout << result << '\n';
    return 0;
}
