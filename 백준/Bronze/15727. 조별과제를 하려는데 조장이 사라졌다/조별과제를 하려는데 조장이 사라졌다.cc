#include <iostream>
using namespace std;

int main() {
    int L;
    cin >> L;
    
    int answer = L/5;
    int plus = L%5;
    
    if (plus > 0)
        answer++;
    
    cout << answer;
    return 0;
}