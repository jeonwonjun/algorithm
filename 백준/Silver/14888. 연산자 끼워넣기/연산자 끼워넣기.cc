#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int N;
int cacurator[4];
int mymax = -1000000001;
int mymin = 1000000001;

void getanswer(int ans, int idx) {
    if (idx == N) {
        if (ans > mymax)
            mymax = ans;
        if (ans < mymin)
            mymin = ans;
        return;
    }

    for (int i=0; i<4; i++) {
        if (cacurator[i] > 0) {
            cacurator[i]--;
            if (i == 0)
                getanswer(ans+A[idx], idx+1);
            else if (i == 1)
                getanswer(ans-A[idx], idx+1);
            else if (i == 2)
                getanswer(ans*A[idx], idx+1);
            else if (i == 3)
                getanswer(ans/A[idx], idx+1);
            cacurator[i]++; // 재귀를 계속돌려야하기 때문에 줄였던 연산자 개수 늘리기
        }
    }
}

int main () {

    cin >> N;
    // 1. 입력 받기
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    for (int i=0; i<4; i++){
        cin >> cacurator[i];
    }
    getanswer(A[0],1);

    cout << mymax << '\n' << mymin;
    return 0;
}