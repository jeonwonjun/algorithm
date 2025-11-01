/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.

#include <iostream>
#include <algorithm>

using namespace std;

int max_sum = 0;

void raw_max(int arr[100][100]){
        for (int i = 0; i < 100; i++) {
            int sum = 0;
        	for(int j = 0; j < 100; j++) {
            	sum += arr[i][j];
            }
            max_sum = max(max_sum, sum);
        }
}

void column_max(int arr[100][100]){
        for (int i = 0; i < 100; i++) {
            int sum = 0;
        	for(int j = 0; j < 100; j++) {
            	sum += arr[j][i];
            }
            max_sum = max(max_sum, sum);
        }
}

void diagonal_max(int arr[100][100]) {
    int sum = 0;
    for (int i = 0; i < 100; i++) {
            sum += arr[i][99-i];
    }
    max_sum = max(max_sum, sum);
    
    sum = 0;
    for (int i = 0; i < 100; i++) {
            sum += arr[i][i];
    }
    max_sum = max(max_sum, sum);
} 

int main(int argc, char** argv)
{
	int test_case;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int t;
        cin >> t;
        int arr[100][100] = {0,};
		for(int i = 0; i < 100; i++) {
        	for(int j = 0; j < 100; j++) {
            	cin >> arr[i][j];
            }
        }
        raw_max(arr);
        column_max(arr);
        diagonal_max(arr);
		cout << "#" << t << " " << max_sum << "\n";
        max_sum = 0;
	}
	return 0;
}