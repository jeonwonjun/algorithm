// 14267: 회사의 문화1
// https://www.acmicpc.net/problem/14267
// C++14
#include <iostream>
#include <vector>
using namespace std;
vector<int> employees[100001];

// 직원 번호는 1부터 시작하므로, 0번 인덱스는 사용하지 않음
int num[100001]; // 직원별 점수 저장
int n, m;
int score[100001];

void dfs(int idx, int w) {
    for (int i=0; i<employees[idx].size(); i++) {
        int next = employees[idx][i];
        score[next] += num[next] + w; // 현재 직원의 점수에 직속상사로부터 받은 점수와 이전 점수를 더함
        dfs(next, num[next] + w); // 다음 직원으로 이동, 현재 직원의 점수도 전달
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == -1) {
            a = 0;
        }
        // 직원번호: 직속상사 + 1
        employees[a].push_back(i + 1);
    }

    for (int k=0; k<m; k++) {
        int i, w;
        cin >> i >> w;
        num[i] += w;
    }

    dfs(1, 0); // 시작점은 1번 직원, 초기 점수는 0

    for (int i=1; i<=n; i++) {
        cout << score[i] << ' ';
    }

    return 0;
}