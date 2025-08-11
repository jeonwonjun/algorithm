#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    //unique함수는 중복을 제거하지만 nums.size() 컨테이너 크기는 변하지 않는다.
    //따라서 resize 함수로 크기를 다시 조정해야한다.
    nums.resize(unique(nums.begin(), nums.end())-nums.begin());

    if (nums.size() >= n / 2)
        answer = n / 2;
    else
        answer = nums.size();

    return answer;
}