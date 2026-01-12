#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    long long a, b, c;
    cin >> a >> b >> c;
    
    do {
        vector<long long> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        sort(arr.begin(), arr.end());
        
        if ((arr[0]*arr[0] + arr[1]*arr[1]) == arr[2]*arr[2]) 
            cout << "right" <<'\n';
        else
            cout << "wrong" << '\n';
        cin >> a >> b >> c;
    } while (!(a == 0 && b == 0 && c == 0));
        
    return 0;
}