#include <iostream>
using namespace std;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int row = h / (n+1), col = w / (m+1);
    if (h % (n+1) != 0)
        row++;
    
    if (w % (m+1) != 0)
        col++;
        
    long long answer = row * col;
    cout << answer;
    
    return 0;
}