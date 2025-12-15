#include <iostream>
using namespace std;

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    int A[301][301];
    int B[601][601];
    for (int i=0; i<h+x; i++) {
        for (int j=0; j<w+y; j++) {
            cin >> B[i][j];
        }
    }
    
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (i-x<0 || j-y<0) {
                A[i][j] = B[i][j];
            } else {
                A[i][j] = B[i][j] - A[i-x][j-y];
            }
        }
    }
    
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}