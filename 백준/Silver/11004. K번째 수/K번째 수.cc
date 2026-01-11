#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k >> n;
    vector<int> arr;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(), arr.end());
    
    cout << arr[n - 1];
    
}