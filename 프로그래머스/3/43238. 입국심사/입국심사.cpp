#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    // times 정렬
    sort(times.begin(), times.end());
    
    // return 값이 시간이기 때문에 이진탐색의 기준은 시간으로 한다.
    long long min = 1; // 1명이 1분 걸린 경우
    long long max = n * (long long)times.back(); // 사람 * 가장 느린 심사관

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long cnt = 0;
        
        // 각 시간별 mid 시간 동안 처리할 수 있는 사람들 수를 더해준다.
        for (int i = 0; i < times.size(); i++)
            cnt += (mid / (long long) times[i]);
        
        // 예제로 하면 30분에 7명을 처리할 수 있기 때문에 더 적은 시간이 걸릴 것이다.
        if (cnt >= n)
        {
            // 우선 최소 경우인 30분은 answer에 넣고 더 적게 걸리는 경우를 탐색
            answer = mid;
            max = mid - 1;
        }
        else
            min = mid + 1;
    }
    return answer;
}