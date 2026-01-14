#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, r, x;
int answer = 0;

void checkDifficulty(vector<int> score, int total_cases) {
  for (int mask = 0; mask < total_cases; mask++) {
    if (__builtin_popcount(mask) >= 2) {
      int comp = mask;
      vector<int> positions;
      
      int sum = 0;
      while (comp > 0) {
        int lowest_bit = comp & -comp;
        int pos = 0;
        int temp = lowest_bit;
        while (temp >>= 1) pos++;
        positions.push_back(score[pos]);
        sum += score[pos];
        
        comp &= ~lowest_bit;
      }
      
      sort(positions.begin(), positions.end());
      
      int score_diff = positions[positions.size() - 1] - positions[0];
      if (score_diff >= x && (l <= sum && sum <= r)) {
        answer++;
      }
    }
  }
}

int main() 
{

    cin >> n >> l >> r >> x;
    vector<int> score(n);
    for (int i = 0; i < n; i++) {
      cin >> score[i];
    }
    
    int total_cases = 1 << n;
    checkDifficulty(score, total_cases);

    cout << answer;

    return 0;
}