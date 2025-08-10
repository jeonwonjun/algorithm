#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> A, B;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        B.push_back(num);
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += A[i]*B[i];
    }
    
    cout << sum << '\n';
    
    return 0;
    
}