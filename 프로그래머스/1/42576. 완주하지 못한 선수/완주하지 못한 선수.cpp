#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> name;
    for(int i=0; i<participant.size(); i++){
        name[participant[i]]++;
    }
    
    for(int i=0; i<completion.size(); i++){
        name[completion[i]]--;
    }
    
    for(auto pair : name){
        if(pair.second > 0)
            answer = pair.first;
    }
    
    cout << answer;
    
    return answer;
}