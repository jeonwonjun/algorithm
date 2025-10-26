/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstring>

using namespace std;
int d[256][1000];

bool check(int x, int y) {
	if (d[x][y-2] == 0 && d[x][y-1] == 0 && d[x][y+1] == 0 && d[x][y+2] == 0)
        return true;
    return false;
}

int main(int argc, char** argv)
{

	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer = 0;
        memset(d, 0, sizeof(d));
        int n;
        cin >> n;
		for(int i = 0; i < n; i++) {
            int height;
            cin >> height;
        	for(int j = 0; j < height; j++) {
            	d[j][i] = 1;
            }
        }
        for(int i=2; i<n-2; i++) {
            int h = 0;
        	while(d[h][i] == 1) {
                // 조망권 체크
                if(check(h, i))
                    answer++;
                h++;
            }
        }
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}