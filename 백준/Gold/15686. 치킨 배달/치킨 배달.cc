// 15686 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int map[51][51];
int n, m;
int ans = 100000;

// 선택된 치킨집 조합으로 전체 집의 치킨 거리 합 계산
int calcDistance(vector<pair<int, int>> &selected)
{
    int total = 0;
    for (int i = 0; i < home.size(); i++)
    {
        int min_dist = 10000;
        for (int j = 0; j < selected.size(); j++)
        {
            int dist = abs(home[i].first - selected[j].first) + abs(home[i].second - selected[j].second);
            min_dist = min(min_dist, dist);
        }
        total += min_dist;
    }

    return total;
}

// 치킨집 M개를 조합으로 선택
void dfs(int idx, vector<pair<int, int>> &selected)
{

    if (selected.size() == m)
    {
        ans = min(ans, calcDistance(selected));
        return;
    }

    for (int i = idx; i < chicken.size(); i++)
    {
        selected.push_back(chicken[i]);
        dfs(i + 1, selected);
        selected.pop_back();
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
            else if (map[i][j] == 1)
                home.push_back({i, j});
        }
    }

    vector<pair<int, int>> selected;
    dfs(0, selected);

    cout << ans << '\n';

    return 0;
}