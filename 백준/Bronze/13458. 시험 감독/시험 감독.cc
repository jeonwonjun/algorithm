#include <iostream>
using namespace std;

long long arr[1000001];

int main() {
    
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    long long B, C;
    cin >> B >> C;
    
    long long ans = 0;
    for (int i=0; i< N; i++) {
        arr[i] = arr[i] - B;
        ans++;
        if (arr[i] > 0) {
            ans += arr[i]/C;
                if(arr[i]%C > 0)
                    ans++;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}