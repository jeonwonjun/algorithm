#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];
int main () {
    for (int i=0; i<5; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    int n = 1;
    while (cnt < 3) {
        n++;
        cnt = 0;
        
        for (int i=0; i<5; i++) {
            if (n % arr[i] == 0)
                cnt++;
        }
        
    }
    
    cout << n << '\n';
    
    return 0;
}