#include <string>
#include <vector>

using namespace std;
int pad[4][3];

int dist(int number, int x, int y){
    int distance = abs(number/3 - x) + abs(1 - y);
    
    return distance;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left_hand = {3, 0}; // *위치
    pair<int, int> right_hand = {3, 2}; // #위치
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            left_hand = {(numbers[i]/3), 0};
            answer += 'L';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            right_hand = {(numbers[i]-1)/3, 2};
            answer += 'R';
        } else {
            int k = numbers[i];
            if (k == 0) {
                k = 10;
            }
            int l_dist = dist(k, left_hand.first, left_hand.second);
            int r_dist = dist(k, right_hand.first, right_hand.second);
            if (l_dist == r_dist) {
                if (hand == "right") {
                    right_hand = {k/3, 1};
                    answer += 'R';
                } else {
                    left_hand = {k/3, 1};
                    answer += 'L';
                }
            } else if (l_dist > r_dist){
                right_hand = {k/3, 1};
                answer += 'R';
            } else {
                left_hand = {k/3, 1};
                answer += 'L';
            }
        }
    }
    return answer;
}