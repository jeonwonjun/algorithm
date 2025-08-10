#include <iostream>
using namespace std;

int arr[100001];
int asc[100001];
int desc[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans_max = 0;
    asc[1] = 1, desc[1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[i+1]) {
            asc[i+1] = asc[i] + 1;
        } else
            asc[i+1] = 1;

        if (arr[i] >= arr[i+1]) {
            desc[i+1] = desc[i] + 1;
        } else
            desc[i+1] = 1;
    }

    for (int i=1; i<=n; i++) {
        ans_max = max(asc[i], ans_max);
        ans_max = max(desc[i], ans_max);
    }

    cout << ans_max << '\n';
    return 0;
}