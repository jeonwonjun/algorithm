#include <iostream>
#include <vector>
using namespace std;

int main() {
    int j, r;
    cin >> j >> r;
    
    vector<int> player(j);
    for (int a=0; a<r; a++) {
        for (int b=0; b<j; b++) {
            int score;
            cin >> score;
            player[b] += score;
        }
    }
    
    
    int winner_i = 0;
    int total_score = 0;
    for (int i=0; i<j; i++) {
        if (total_score <= player[i]) {
            total_score = player[i];
            winner_i = i;
        }
    }
    
    cout << winner_i + 1;

    return 0;
}