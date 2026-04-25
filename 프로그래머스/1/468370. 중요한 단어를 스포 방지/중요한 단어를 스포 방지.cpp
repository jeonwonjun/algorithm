#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    vector<bool> is_spoiler(message.length(), 0);
    vector<string> spoiler_words;
    unordered_map<string, int> words;
    
    for (int i = 0; i < spoiler_ranges.size(); i++) {
        int start = spoiler_ranges[i][0];
        int end = spoiler_ranges[i][1];
        for (int j = start; j <= end; j++) {
            is_spoiler[j] = true;
        }
    }
    
    int i = 0;
    while (i < message.length()) {
        if (message[i] == ' ') {
            i++;
            continue;
        }
        
        string word = "";
        bool spoiler_flag = false;
        
        int j = i;
        while (j < message.length() && message[j] != ' ') {
            word += message[j];
            if (is_spoiler[j] == true) {
                spoiler_flag = true;
            }
            j++;
        }
        
        if (spoiler_flag) {
            spoiler_words.push_back(word);
        } else {
            words[word]++;
        }
        
        i = j;
    }
    
    for (auto &word : spoiler_words) {

        if (words[word] == 0) {
            words[word]++;
            answer++;
        }
    }
    return answer;
}