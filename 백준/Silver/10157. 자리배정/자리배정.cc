#include <iostream>
using namespace std;

int c,r,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool board[1001][1001];

int main() {

    cin >> r >> c >> k;
    
    if (c * r < k) {
        cout << 0;
    }
    else if (k==1) {
        cout << 1 << ' ' << 1;
    }
    else {
        int x=1,y=1,d=0,num=1;
        board[x][y]=true;
        while (1) {
            int nx=x+dx[d],ny=y+dy[d];
            if (nx>r || nx<=0 || ny>c || ny<=0 || board[nx][ny]) d = (d+1) % 4;
            x += dx[d];
            y += dy[d];
            board[x][y] = true;
            num++;
            if (num==k) break;
        }

        cout << x << ' ' << y;
    }
    return 0;
}
