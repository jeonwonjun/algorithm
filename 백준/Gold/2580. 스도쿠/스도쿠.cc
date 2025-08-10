/*비트마스크(해당 조건에 값이 존재하는가)를 활용한 백트래킹*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 9
int map[MAX][MAX]; // 스도쿠 판
vector<pair<int, int>> blank; // 빈칸 위치 저장
int cnt = 0;
bool found = false; // 스도쿠 완성 flag

// 숫자 넣을 때마다 true로 마킹하고, 백트래킹 시 원상복구
bool row[9][10];   // row[i][x]: i행에 x가 존재하는가
bool col[9][10];   // col[j][x]: j열에 x가 존재하는가
bool square[9][10]; // square[i][x]: i번째 3x3 블록에 x가 존재하는가

// 3x3 블록 인덱스 계산 함수
int squareIndex(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void sdoku(int x)
{
    // 1. 종료 조건: 빈칸의 개수만큼을 채워서 스도쿠 완성
    if(x == cnt) {
        for (int i=0; i<MAX; i++) {
            for (int j=0; j<MAX; j++) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        found = true;
        return;
    }

    int r = blank[x].first;
    int c = blank[x].second;
    int s = squareIndex(r, c);

    // 2. 다음 경우
    for (int num = 1; num <= 9; num++) {
        if (!row[r][num] && !col[c][num] && !square[s][num]) {
            row[r][num] = col[c][num] = square[s][num] = true;
            map[r][c] = num;

            sdoku(x + 1);
            if (found) return;

            map[r][c] = 0;
            row[r][num] = col[c][num] = square[s][num] = false;
        }
    }

    return;
}

int main()
{
    pair<int, int> point;
    // 1. map 입력 받고, 빈칸 구하기
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            cin >> map[i][j];
            int val = map[i][j];
            if (val == 0) {
                cnt++;
                point.first = i;
                point.second = j;
                blank.push_back(point);
            } else {
                // 숫자 미리 체크
                row[i][val] = true;
                col[j][val] = true;
                square[squareIndex(i, j)][val] = true;
            }
        }
    }
    sdoku(0);

    return 0;
}