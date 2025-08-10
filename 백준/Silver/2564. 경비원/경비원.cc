#include <iostream>
#include <vector>
using namespace std;

int x, y;
int n;
int a, b;
vector<pair<int, int>> store;

int main()
{
    cin >> y >> x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        switch (a)
        {
        case 1:
            store.push_back({0, b});
            break;
        case 2:
            store.push_back({x, b});
            break;
        case 3:
            store.push_back({b, 0});
            break;
        case 4:
            store.push_back({b, y});
            break;
        }
    }

    cin >> a >> b;
    if (a == 1)
    {
        a = 0;
    }
    else if (a == 2)
    {
        a = x;
    }
    else if (a == 3)
    {
        a = b, b = 0;
    }
    else if (a == 4)
    {
        a = b, b = y;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // 맞은편 위치
        if (abs(store[i].first - a) == x || abs(store[i].second - b) == y)
        {
            if (store[i].first == 0 || a == 0)
                sum += x + min(store[i].second + b, 2 * y - (store[i].second + b));
            else
                sum += y + min(store[i].first + a, 2 * x - (store[i].first + a));
        } // 같은 위치, 위치가 똑같은 맞은편이 걸리기 때문에 맞은편 부터 처리
        else if (abs(store[i].first - a) == 0 || abs(store[i].second - b) == 0)
        {
            sum += max(abs(store[i].first - a), abs(store[i].second - b));
        }
        else
        {
            sum += abs(store[i].first - a) + abs(store[i].second - b);
        }
    }
    cout << sum << '\n';

    return 0;
}