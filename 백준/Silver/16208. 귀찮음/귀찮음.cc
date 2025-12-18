#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    
    int num = 0;
    cin >> num;
    long long sum = num;
    long long result = 0;
    for(int i = 1; i<n; i++) {
        cin >> num;
        result += sum * num;
        sum += num;
    }
    printf("%lld", result);
}