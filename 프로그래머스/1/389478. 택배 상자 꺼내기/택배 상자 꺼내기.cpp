#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<int> box;
    
     for(int i = 1; i<w*2; i+=2){
        box.push_back(i);
    }
    
    sort(box.rbegin(), box.rend());
    
    // num 위 상자구하기
    int nextNum = num;
    while(nextNum<=n){
        int addNum;
        addNum = (nextNum % w == 0) ? w : nextNum % w;
        nextNum = nextNum + box[addNum-1];
        answer++;
    }
    
    return answer;
}