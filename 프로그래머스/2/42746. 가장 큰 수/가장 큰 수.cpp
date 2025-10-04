#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const std::string& a, const std::string& b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> strnum;
    strnum.resize(numbers.size());
    for(int i=0; i<numbers.size(); i++){
        strnum[i] = to_string(numbers[i]);
    }
    sort(strnum.begin(), strnum.end(), compare);
    for(int i=0; i<numbers.size(); i++){
        answer += strnum[i];
    }
    
    //만약 answer가 전부 0으로 이루어져있다면 00000000... 이 아닌 0을 반환한다.
    if(answer == string(answer.length(), '0'))
        return "0";
    
    return answer;
}