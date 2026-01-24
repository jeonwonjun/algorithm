#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(), arr.end());
    
    cout << arr[0]*arr[n-1];
    return 0;
}