#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int from, to;
int answer = 0;

vector<int> family[101];
int dist[101];

int bfs(int start, int target) {
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            return dist[curr];
        }

        for (int next : family[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main() {
    cin >> n;
    cin >> from >> to;
    cin >> m;

    fill(dist, dist + 101, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        family[a].push_back(b);
        family[b].push_back(a);
    }

    int answer = bfs(from, to);
    cout << answer;
    return 0;
}